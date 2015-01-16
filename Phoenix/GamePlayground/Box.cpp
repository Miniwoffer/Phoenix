/*
 * Box.cppv
 *
 *  Created on: 17 Nov 2014
 *      Author: odin
 */

#include "Box.h"
Box::Box(Phoenix::Scene& scene,float x, float y, float sizeX, float sizeY): rect() {
	rect.setSize(sf::Vector2f(sizeX,sizeY));
	rect.setOrigin(sf::Vector2f(sizeX/2,sizeY/2));
	rect.setPosition(sf::Vector2f(x,y));
	rect.setFillColor(sf::Color::Red);
	
	b2BodyDef def;
	def.position = Phoenix::sTOb(x,y);
	def.type = b2_dynamicBody;
	body = scene.addPhysics(def);
	b2Vec2 sizeboxsim = Phoenix::sTOb(sizeX / 2, sizeY / 2);
	b2PolygonShape shape;
	shape.SetAsBox(sizeboxsim.x,sizeboxsim.y);
	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = 1.0f;
	fixture.friction = 0.3f;
	body->CreateFixture(&fixture);
	scene.addGraphics(rect);
	scene.addGameObjects(*this);
}

Box::~Box() {
}
void Box::Update(float DeltaTime)
{
	rect.setPosition(Phoenix::bTOs(body->GetPosition()));
	rect.setRotation(Phoenix::radianTorot(body->GetAngle()));
}
