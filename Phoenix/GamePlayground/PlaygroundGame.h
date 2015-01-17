#pragma once
#include <Phoenix\Game.h>
#include <vector>
#include <memory>
#include "Box.h"
#include "Player.h"
class PlaygroundGame :
	public Phoenix::Game
{
public:
	PlaygroundGame();
	~PlaygroundGame();
protected:
	int fps = 0;
	int boxes = 0;
	Phoenix::Tiledmap tile;
	sf::Font font;
	//Player pl;
	std::vector<Box*> boxhell;
	sf::Text fpsCounter;
	sf::Text boxCounter;
	void Update(float deltatime);
	void Draw();
	void WindowEvent(sf::Event ev);
};

