/*
* Convertion.cpp
*
*  Created on: 15 Jan 2015
*      Author: Odin Hultgren Van Der Horst
*
*	Description:
*		uttility functions deticated to converting from one unit to another
*/
#include "Convertion.h"
namespace Phoenix
{

	sf::Vector2f SimulationToWorld(const b2Vec2 b2vec)
	{
		return sf::Vector2f(b2vec.x / SIMULATOINRATE, b2vec.y / SIMULATOINRATE);
	}
	b2Vec2 WorldToSimulation(const sf::Vector2f sfvec2)
	{
		return b2Vec2(sfvec2.x*SIMULATOINRATE, sfvec2.y*SIMULATOINRATE);
	}


	sf::Vector2f SimulationToWorld(const float x, const float y)
	{
		return sf::Vector2f(x / SIMULATOINRATE, y / SIMULATOINRATE);
	}
	b2Vec2 WorldToSimulation(const float x, const float y)
	{
		return b2Vec2(x*SIMULATOINRATE, y*SIMULATOINRATE);
	}


	float SimulationToWorld(const float x)
	{
		return x / SIMULATOINRATE;
	}

	float WorldToSimulation(const float x)
	{
		return x*SIMULATOINRATE;
	}

	float RadianToRot(const float radian)
	{
		return (float)((radian / 3.14) * 180);
	}
	float RotToRadian(const float rot)
	{
		return(float)((rot*3.14) / 180);
	}
}
