/*
 * Copyright 2014, Odin Hultgren Van Der Horst
 */

#ifndef TILEDMAP_H
#define TILEDMAP_H
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <string>
#include <vector>
#include <boost/optional.hpp>
#include "Convertion.h"
#include "Scene.h"
namespace Phoenix
{
	class Tiledmap : public sf::Drawable, sf::Transformable
	{
	public:
		Tiledmap(std::string filename, System::Scene& scene);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	private:
		std::vector<sf::VertexArray> m_vertices;
		sf::Texture m_tileset;
		//std::vector<b2Body> bodies;
	};
}
#endif // TILEDMAP_H
