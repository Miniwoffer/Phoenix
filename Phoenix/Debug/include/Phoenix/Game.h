/*
* Game.h
*
*  Created on: 15 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*/
#pragma once
#ifdef GAME_EXPORTS
#define GAME_API __declspec(dllexport) 
#else
#define GAME_API __declspec(dllimport) 
#endif

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

#include "Variables.h"
#include "GameObject.h"
#include "Keyboard.h"
#include "Scene.h"
#include "Convertion.h"
#include "Tiledmap.h"
namespace Phoenix
{
	class __declspec(dllexport) Game
	{
	public:
		Game(int width = 900, int height = 600, int colordepth = 32, int target_fps = 6000, bool vSync = true, std::string windowName = "Phoenix", float gravityX = 0.f, float gravityY = 40.f);
		virtual ~Game();
		virtual void StartGameLoop();
		sf::RenderWindow window;
		sf::View camera;
		Scene scene;
		//std::vector<Box*> boxhell;
	private:
		sf::Clock deltaClock;
		sf::Clock timerClock;
	protected:
		bool run;
		virtual void Update(float deltatime);
		virtual void Draw();
		virtual void WindowEvent(sf::Event ev);
	};
}
