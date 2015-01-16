#pragma once
#include <Box2D\Box2D.h>
#include <Phoenix\Keyboard.h>
#include <Phoenix\Scene.h>
#include <Phoenix\Convertion.h>
#include <Phoenix\Keyboard.h>
#include <string>
class Player : public Phoenix::GameObject
{
	b2Body* body;
	sf::RectangleShape rect;
public:
	Player(Phoenix::Scene& scene, float x, float y);
	~Player();
	void Update(float DeltaTime);
};
