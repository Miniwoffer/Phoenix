/*
* Game.h
*
*  Created on: 15 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*
*	Description:
*		The class containing the main loop, the deltatimer, the camera and the render window.
*/
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

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
		virtual void StartGameLoop();//stars the gameloop
		sf::RenderWindow window;
		sf::View camera;//the camera for the scene
		Scene scene;//the current scene
	private:
		sf::Clock deltaClock;
	protected:
		bool run;//if set to true, the deltatime will be set to 0, physics and any gameobject using deltatime will stop moving.
		virtual void Update(float deltatime);//the function that updates the scene
		virtual void Draw();//the function that telles the scene to draw everything
		virtual void WindowEvent(sf::Event ev);//The event handler for the window
	};
}
