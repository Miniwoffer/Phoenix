/*
 * Convertion.h
 *
 *  Created on: 18 Nov 2014
 *      Author: Odin Hultgren Van Der Horst
 */
#pragma once
#ifdef CONVERTION_EXPORTS
#define CONVERTION_API __declspec(dllexport) 
#else
#define CONVERTION_API __declspec(dllimport) 
#endif

#include <string>
#include <iostream>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
const float SIMULATOINRATE = 0.05f;
namespace Phoenix
{
	__declspec(dllexport) sf::Vector2f SimulationToWorld(const b2Vec2 b2vec);
	__declspec(dllexport) b2Vec2 WorldToSimulation(const sf::Vector2f sfvec2);
	__declspec(dllexport) sf::Vector2f SimulationToWorld(const float x, const float y);
	__declspec(dllexport) b2Vec2 WorldToSimulation(const float x, const float y);
	__declspec(dllexport) float SimulationToWorld(const float x);
	__declspec(dllexport) float WorldToSimulation(const float x);
	__declspec(dllexport) float RadianToRot(const float radian);
	__declspec(dllexport) float RotToRadian(const float rot);
}
