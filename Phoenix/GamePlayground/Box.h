/*
 * Box.h
 *
 *  Created on: 17 Nov 2014
 *      Author: odin
 */

#pragma once
#include <SFML\Graphics.hpp>
#include <Phoenix\Scene.h>
#include <Box2D\Box2D.h>
#include <Phoenix\Convertion.h>
#include <Phoenix\GameObject.h>
class Box: public Phoenix::GameObject {
public:
	Box(Phoenix::Scene& scene,float x, float y, float sizeX, float size);
	virtual ~Box();
	void Update(float DeltaTime);
private:
	sf::RectangleShape rect;
	b2Body* body;
};

