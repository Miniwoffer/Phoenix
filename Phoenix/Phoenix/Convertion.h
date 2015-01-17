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
	static int linenum = 0;
	template <typename T>
	__declspec(dllexport) void logAction(const T message);
	__declspec(dllexport) sf::Vector2f bTOs(const b2Vec2 b2vec);
	__declspec(dllexport) b2Vec2 sTOb(const sf::Vector2f sfvec2);
	__declspec(dllexport) sf::Vector2f bTOs(const float x, const float y);
	__declspec(dllexport) b2Vec2 sTOb(const float x, const float y);
	__declspec(dllexport) float bTOs(const float x);
	__declspec(dllexport) float sTOb(const float x);
	__declspec(dllexport) float radianTorot(const float radian);
	__declspec(dllexport) float totToradian(const float rot);
}
