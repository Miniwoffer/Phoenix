/*
*  Keyboard.cpp
*
*  Created on: 18 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*
*	Description:
*		A set static functions that handels the keyboard input.
*/
#include "Keyboard.h"

namespace Phoenix{
	namespace Keyboard{
		//the map containing alle the states of the keys on the keyboard
		std::map<sf::Keyboard::Key, Keystate> keystate;
		//The keyevent handler called my the Game class
		void keyevent(sf::Event ev)
		{
			switch (ev.type)
			{
			case sf::Event::EventType::KeyPressed:
				if (keystate[ev.key.code] == Keystate::NONE)
				{
					keystate[ev.key.code] = Keystate::CLICKED;
				}
				break;
			case sf::Event::EventType::KeyReleased:
				keystate[ev.key.code] = Keystate::RELEASED;
				break;
			default:
				break;
			}
		}
		//Orders the keys to advance one fase, so clicked->keydown, and released->none.
		void keyboardupdate()
		{
			for (std::map<sf::Keyboard::Key, Keystate>::iterator it = keystate.begin(); it != keystate.end(); ++it)
			{
				if (it->second == Keystate::CLICKED)
				{
					it->second = Keystate::KEYDOWN;
				}
				if (it->second == Keystate::RELEASED)
				{
					it->second = Keystate::NONE;
				}
			}
		}
		//a wrapper for the keyboard map so no one accidenly = when they want to == and ruin other parts of the code
		Keystate getKeyState(sf::Keyboard::Key key){
			return keystate[key];
		}
	}
}
