#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "System/Variables.h"
#include "System/GameObject.h"

class game
{
public:
	game();
	~game();
	std::vector<GameObject> world;
	sf::RenderWindow* window;
private:
	void update(float deltatime);
};
