/*
* Game.cpp
*
*  Created on: 15 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*/

#include "Game.h"

namespace Phoenix
{
	Game::Game(int width, int height, int colordepth, int target_fps, bool vSync, std::string windowName, float gravityX, float gravityY) : window(sf::VideoMode(width, height, colordepth), windowName), scene(gravityX, gravityY)
	{
		run = true;
		//initiates the window and sets targetFPS and vSync
		window.setFramerateLimit(target_fps);
		window.setVerticalSyncEnabled(vSync);
		//initilises the scene
		camera.setSize(width, height);

		window.setView(camera);
	}
	void Game::StartGameLoop()
	{
		while (window.isOpen())
		{
			//Resets the deltaTime clock
			sf::Time dt = deltaClock.restart();

			sf::Event event;

			//tells the keyboard to advance the keys to the next stage.
			Keyboard::keyboardupdate();

			//Looks for poolEvents
			while (window.pollEvent(event))
			{
				WindowEvent(event);
			}
			float deltatime = dt.asSeconds();
			if (!run)
			{
				//Sets deltatime to 0, if the game is paused.
				deltatime = 0;
			}
			Update(deltatime);
			Draw();

		}
	}
	Game::~Game()
	{
	}
	void Game::Update(float deltatime){
		scene.Update(deltatime);
	}
	void Game::Draw()
	{
		scene.Draw(window, camera);
	}
	void Game::WindowEvent(sf::Event ev)
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::Resized:
			break;
		default:
			break;
		}
		Keyboard::keyevent(ev);
	}
}
