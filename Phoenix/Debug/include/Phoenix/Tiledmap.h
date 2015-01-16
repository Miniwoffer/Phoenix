/*
* Tilemap.h
*
*  Created on: 18 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*/
#pragma once
#ifdef TILEMAP_EXPORTS
#define TILEMAP_API __declspec(dllexport) 
#else
#define TILEMAP_API __declspec(dllimport) 
#endif

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
