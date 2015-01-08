/*
 * Convertion.h
 *
 *  Created on: 18 Nov 2014
 *      Author: odin
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
	static void logAction(T message)
	{
		std::cout << linenum << ": " << message << std::endl;
		linenum++;
	}
	static sf::Vector2f bTOs(b2Vec2 b2vec)
	{
		return sf::Vector2f(b2vec.x/SIMULATOINRATE,b2vec.y/SIMULATOINRATE);
	}
	static b2Vec2 sTOb(sf::Vector2f sfvec2)
	{
		return b2Vec2(sfvec2.x*SIMULATOINRATE,sfvec2.y*SIMULATOINRATE);
	}


	static sf::Vector2f bTOs(float x, float y)
	{
		return sf::Vector2f(x/SIMULATOINRATE,y/SIMULATOINRATE);
	}
	static b2Vec2 sTOb(float x, float y)
	{
		return b2Vec2(x*SIMULATOINRATE,y*SIMULATOINRATE);
	}


	static float bTOs(float x)
	{
		return x/SIMULATOINRATE;
	}
	static float sTOb(float x)
	{
		return x*SIMULATOINRATE;
	}

	static float radianTorot(float radian)
	{
		return (float)((radian/3.14)*180);
	}
	static float totToradian(float rot)
	{
		return(float)((rot*3.14) / 180);
	}
}
