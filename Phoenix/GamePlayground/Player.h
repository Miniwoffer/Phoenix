#pragma once
#include "GameObject.h"
#include <Box2D\Box2D.h>
#include "System\Scene.h"
#include "Convertion.h"
#include <string>
class Player : public GameObject
{
	b2Body* body;
	sf::RectangleShape rect;
public:
	Player(System::Scene& scene, float x, float y);
	~Player();
	void Update(float DeltaTime);
};
