/*
* Tilemap.h
*
*  Created on: 18 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*
* Description:
*		Parses a Tiled(http://www.mapeditor.org/) xml map and adds the graphics and physics to the scene.
*		Currently only support a collision layer, add a costom properti where col=1.
*/
#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/optional.hpp>
#include <boost/foreach.hpp>

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics.hpp>

#include <Box2D/Box2D.h>

#include <iostream>
#include <string>
#include <vector>

#include "Convertion.h"
#include "Scene.h"
#include "Log.h"

namespace  Phoenix
{
	class __declspec(dllexport) Tiledmap : public sf::Drawable, sf::Transformable
	{
	public:
		Tiledmap(std::string filename, Scene& scene);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	private:
		std::vector<sf::VertexArray> m_vertices;
		sf::Texture m_tileset;
	};
}
