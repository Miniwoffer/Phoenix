/*
* Tilemap.cpp
*
*  Created on: 18 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*
* Description:
*		Parses a Tiled(http://www.mapeditor.org/) xml map and adds the graphics and physics to the scene.
*		Currently only support a collision layer, add a costom properti where col=1.
*/

#include "Tiledmap.h"

namespace Phoenix{
	Tiledmap::Tiledmap(std::string filename, Scene& scene)
	{
		boost::property_tree::ptree pt;
		boost::property_tree::read_xml(filename, pt);
		std::string imagedir;
		imagedir = pt.get<std::string>("map.tileset.image.<xmlattr>.source");
		imagedir = imagedir.substr(3, imagedir.length());
		if (m_tileset.loadFromFile(imagedir))
		{
			BOOST_FOREACH(boost::property_tree::ptree::value_type &t, pt.get_child("map"))
			{
				if ((std::string)(t.first.data()) == "layer")
				{
					bool col = false;

					boost::optional<boost::property_tree::basic_ptree<std::string, std::string>& > child = t.second.get_child_optional("properties");
					if (child)
					{
						BOOST_FOREACH(boost::property_tree::ptree::value_type &v, t.second.get_child("properties"))
						{
							if ((std::string)(v.first.data()) == "property")
							{
								if (v.second.get<std::string>("<xmlattr>.name") == "col")
								{
									if (v.second.get<int>("<xmlattr>.value") == 1)
									{
										col = true;
									}
								}
							}
						}
					}
					sf::VertexArray m_vert;
					m_vert.setPrimitiveType(sf::Quads);
					int width = t.second.get<int>("<xmlattr>.width");
					int height = t.second.get<int>("<xmlattr>.height");
					sf::Vector2u tileSize(pt.get<int>("map.<xmlattr>.tilewidth"), pt.get<int>("map.<xmlattr>.tileheight"));
					m_vert.resize(width * height * 4);
					int j = 0;
					int i = 0;
					BOOST_FOREACH(boost::property_tree::ptree::value_type &v, t.second.get_child("data"))
					{
						if (v.second.get<int>("<xmlattr>.gid") != 0)
						{
							int tileNumber = v.second.get<int>("<xmlattr>.gid") - 1;
							// find its position in the tileset texture
							int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
							int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

							// get a pointer to the current tile's quad
							sf::Vertex* quad = &m_vert[(i * height + j) * 4];

							// define its 4 corners
							quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
							quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
							quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
							quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

							// define its 4 texture coordinates
							quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
							quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
							quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
							quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
							if (col == true)
							{
								b2BodyDef def;
								def.position = WorldToSimulation(i * tileSize.x + tileSize.x / 2, j * tileSize.y + tileSize.y / 2);
								b2Body* body = scene.addPhysics(def);
								b2Vec2 sizeboxsim(WorldToSimulation(tileSize.x / 2, tileSize.y / 2));
								b2PolygonShape shape;
								shape.SetAsBox(sizeboxsim.x, sizeboxsim.y);
								b2FixtureDef fixture;
								fixture.shape = &shape;
								fixture.density = 1.0f;
								fixture.friction = 0.3f;
								body->CreateFixture(&fixture);
							}
						}
						i++;
						if (i >= width)
						{
							i = 0;
							j++;
						}
					}
					m_vertices.push_back(m_vert);
				}
			}
		}
		else
		{
			Log::error("Failed to load " + imagedir + " while loading " + filename + " in Tilemap.cpp");
		}
	}

	void Tiledmap::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform(); // getTransform() is defined by sf::Transformable
		states.texture = &m_tileset;
		for (auto itr = m_vertices.begin(); itr < m_vertices.end(); ++itr)
		{
			target.draw(*itr, states);
		}
	}
}