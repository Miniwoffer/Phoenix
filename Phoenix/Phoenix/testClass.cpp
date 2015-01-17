#include "testClass.h"
namespace Phoenix {
	testClass::testClass(b2World* world)
	{

		b2BodyDef def;

		def.position = b2Vec2(10, 10);
		def.type = b2_dynamicBody;

		b2Body* body;
		body = world->CreateBody(&def);

		b2Vec2 sizeboxsim(10, 10);
		b2PolygonShape shape;
		b2FixtureDef fixture;
		fixture.shape = &shape;

		body->CreateFixture(&fixture);
	}


	testClass::~testClass()
	{
	}
}