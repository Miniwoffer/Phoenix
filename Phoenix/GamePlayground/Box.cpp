/*
 * Box.cppv
 *
 *  Created on: 17 Nov 2014
 *      Author: odin
 */

#include "Box.h"
#include "../Convertion.h"
namespace Graphics {

Box::Box(System::Scene& scene,float x, float y, float sizeX, float sizeY) {
	rect.setSize(sf::Vector2f(sizeX,sizeY));
	rect.setOrigin(sf::Vector2f(sizeX/2,sizeY/2));
	rect.setPosition(sf::Vector2f(x,y));
	rect.setFillColor(sf::Color::Red);
	
	b2BodyDef def;
	def.position = tools::sTOb(x,y);
	def.type = b2_dynamicBody;
	body = scene.addPhysics(def);
	b2Vec2 sizeboxsim = tools::sTOb(sizeX/2,sizeY/2);
	shape.SetAsBox(sizeboxsim.x,sizeboxsim.y);
	fixture.shape = &shape;
	fixture.density = 1.0f;
	fixture.friction = 0.3f;
	body->CreateFixture(&fixture);
	scene.addGraphics(rect);
	scene.addGameObjects(*this);

	// TODO Auto-generated constructor stu
}

Box::~Box() {
	// TODO Auto-generated destructor stub
}
void Box::Update(float DeltaTime)
{
	rect.setPosition(tools::bTOs(body->GetPosition()));
	rect.setRotation(tools::radianTorot(body->GetAngle()));
}
} /* namespace Graphics */
