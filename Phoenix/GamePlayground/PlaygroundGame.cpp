//a temp test class
#include "PlaygroundGame.h"

#include <Phoenix\Tiledmap.h>
#include <Phoenix\Scene.h>
#include <Phoenix\Log.h>
#include <string>

PlaygroundGame::PlaygroundGame() : tile(new Phoenix::Tiledmap("Levels/LevelOne.lvl.tmx", scene)),fpsCounter(new sf::Text()) //, pl(scene, 100, 100)
{
	Phoenix::Log::debug("Debug text test \n this is a test \n lorem ipsum");
	Phoenix::Log::error("Error text test \n this is a test \n lorem ipsum");
	Phoenix::Log::warning("Warning text test \n this is a test \n lorem ipsum");

	font.loadFromFile("Fonts\\arial.ttf");
	fpsCounter->setFont(font);
	fpsCounter->setCharacterSize(30);
	fpsCounter->setStyle(sf::Text::Regular);

	scene.addGraphics(tile);
	scene.addGUIGraphics(fpsCounter);
	scene.addGUIGraphics(boxCounter);
}


PlaygroundGame::~PlaygroundGame()
{
}
void PlaygroundGame::Update(float deltatime){
	Game::Update(deltatime);

	fpsCounter->setString("FPS:" + std::to_string(fps));
	fps = 60 / deltatime;


	float moveleng = 500 * deltatime;
	if (Phoenix::Keyboard::getKeyState(sf::Keyboard::W) == Phoenix::Keystate::KEYDOWN)
	{
		camera.move(0, -moveleng);
	}
	if (Phoenix::Keyboard::getKeyState(sf::Keyboard::A) == Phoenix::Keystate::KEYDOWN)
	{
		camera.move(-moveleng, 0);
	}
	if (Phoenix::Keyboard::getKeyState(sf::Keyboard::S) == Phoenix::Keystate::KEYDOWN)
	{
		camera.move(0, moveleng);
	}
	if (Phoenix::Keyboard::getKeyState(sf::Keyboard::D) == Phoenix::Keystate::KEYDOWN)
	{
		camera.move(moveleng, 0);
	}
	if (Phoenix::Keyboard::getKeyState(sf::Keyboard::P) == Phoenix::Keystate::CLICKED)
	{
		run = !run;
	}
}
void PlaygroundGame::Draw(){
	Game::Draw();
}
void PlaygroundGame::WindowEvent(sf::Event ev){
	Game::WindowEvent(ev);
	if (ev.type == sf::Event::MouseWheelMoved)
	{
		camera.zoom(1 - ev.mouseWheel.delta*0.1);
	}
}
