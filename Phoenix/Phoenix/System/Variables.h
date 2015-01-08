#ifndef VARIABLES_H
#define VARIABLES_H
#include <string>
#include <SFML/Graphics.hpp>

	enum Directions
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		ALL
	};
	enum CollisionType
	{
		WORLD,
		DESTRUCTIBLE,
		PLAYER,
		OTHER
	};
	struct Tile
	{
		sf::Sprite sprite;
		int x;
		int y;
	};
#endif
