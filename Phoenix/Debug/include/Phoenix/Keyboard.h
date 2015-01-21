/*
*  Keyboard.h
*
*  Created on: 18 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*	
*	Description:
*		A set static functions that handels the keyboard input.
*/
#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

#include <map>

namespace Phoenix{
	enum __declspec(dllexport)  Keystate
	{
		NONE,//Key is not active
		CLICKED,//Key was pressed this frame
		KEYDOWN,//Key is down
		RELEASED//Key was released this frame
	};
	namespace Keyboard
	{
		//The keyevent handler called my the Game class
		__declspec(dllexport)  void keyevent(sf::Event ev);
		//Orders the keys to advance one fase, so clicked->keydown, and released->none.
		__declspec(dllexport)  void keyboardupdate();
		//a wrapper for the keyboard map so no one accidenly = when they want to == and ruin other parts of the code
		__declspec(dllexport)  Keystate getKeyState(sf::Keyboard::Key key);
	};
}