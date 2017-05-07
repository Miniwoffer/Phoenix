/*
 * Convertion.h
 *
 *  Created on: 18 Nov 2014
 *      Author: Odin Hultgren Van Der Horst
 *
 *	Description:
*		uttility functions deticated to converting from one unit to another
 */
#pragma once

#include <SFML/Graphics.hpp>

#include <Box2D/Box2D.h>

#include <iostream>
#include <string>

//the float represents the simulation units to pixels ratio
const float SIMULATOINRATE = 0.05f;

namespace Phoenix
{
	//convert from simulation uints(box2d) to pixel units(sfml)
	sf::Vector2f SimulationToWorld(const b2Vec2 b2vec);
	sf::Vector2f SimulationToWorld(const float x, const float y);
	float SimulationToWorld(const float x);

	//convert from pixel units(sfml) to simulation uints(box2d)
	b2Vec2 WorldToSimulation(const float x, const float y);
	b2Vec2 WorldToSimulation(const sf::Vector2f sfvec2);
	float WorldToSimulation(const float x);

	//convert from radian to rotation
	float RadianToRot(const float radian);
	//converts from rotation to radian
	float RotToRadian(const float rot);
}
