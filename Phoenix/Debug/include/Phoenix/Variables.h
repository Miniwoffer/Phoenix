/*
* Variables.h
*
*  Created on: 18 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*/
#pragma once
#ifdef VARIABLES_EXPORTS
#define VARIABLES_API __declspec(dllexport) 
#else
#define VARIABLES_API __declspec(dllimport) 
#endif

#include <string>
#include <SFML/Graphics.hpp>
namespace Phoenix{
	enum VARIABLES_API Directions
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		ALL
	};
	enum VARIABLES_API CollisionType
	{
		WORLD,
		DESTRUCTIBLE,
		PLAYER,
		OTHER
	};
	struct VARIABLES_API Tile
	{
		sf::Sprite sprite;
		int x;
		int y;
	};
}