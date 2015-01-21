//a temp test class
#pragma once
#include <Phoenix\Game.h>
#include <vector>
#include <memory>
class PlaygroundGame :
	public Phoenix::Game
{
public:
	PlaygroundGame();
	~PlaygroundGame();
protected:
	int fps = 0;
	int boxes = 0;
	std::shared_ptr<Phoenix::Tiledmap> tile;
	sf::Font font;
	std::shared_ptr<sf::Text> fpsCounter;
	std::shared_ptr<sf::Text> boxCounter;
	void Update(float deltatime);
	void Draw();
	void WindowEvent(sf::Event ev);
};

