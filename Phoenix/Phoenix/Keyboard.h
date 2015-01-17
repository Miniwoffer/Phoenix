/*
*  Keyboard.h
*
*  Created on: 18 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*/
#pragma once
#ifdef KEYBOARD_EXPORTS
#define KEYBOARD_API __declspec(dllexport) 
#else
#define KEYBOARD_API __declspec(dllimport) 
#endif

#include <map>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

namespace Phoenix{
	enum KEYBOARD_API Keystate
	{
		NONE,
		CLICKED,
		KEYDOWN,
		RELEASED
	};
	namespace Keyboard
	{
		KEYBOARD_API std::map<sf::Keyboard::Key, Keystate> keystate;
		KEYBOARD_API void keyevent(sf::Event ev);
		KEYBOARD_API void keyboardupdate();
	};
}