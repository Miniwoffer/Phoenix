/*
* Game.cpp
*
*  Created on: 15 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*
*	Description:
*		The class containing the main loop, the deltatimer, the camera and the render window.
*/
#include "Game.h"
#include "Log.h"
namespace Phoenix
{
	Game::Game(int width, int height, int colordepth, int target_fps, bool vSync, std::string windowName, float gravityX, float gravityY) : window(sf::VideoMode(width, height, colordepth), windowName), scene(gravityX, gravityY)//inits the window and scene
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
			//tells the keyboard to advance the keys to the next stage.
			Keyboard::keyboardupdate();

			//Looks for poolEvents
			sf::Event event;
			while (window.pollEvent(event)){WindowEvent(event);}

			float deltatime = dt.asSeconds();
			//sets deltatime to 0 so the game is paused
			if (!run){deltatime = 0;}

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
