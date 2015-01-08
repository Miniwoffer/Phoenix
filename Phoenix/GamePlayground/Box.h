/*
 * Box.h
 *
 *  Created on: 17 Nov 2014
 *      Author: odin
 */

#ifndef PHYSICS_BOX_H_
#define PHYSICS_BOX_H_
#include <SFML/Graphics.hpp>
#include "../System/Scene.h"
#include <Box2D/Box2D.h>
namespace Graphics {

class Box: public GameObject {
public:
	Box(System::Scene& scene,float x, float y, float sizeX, float size);
	virtual ~Box();
	void Update(float DeltaTime);
private:
	sf::RectangleShape rect;
	b2Body* body;
	b2PolygonShape shape;
	b2FixtureDef fixture;
};

} /* namespace Graphics */

#endif /* PHYSICS_BOX_H_ */
