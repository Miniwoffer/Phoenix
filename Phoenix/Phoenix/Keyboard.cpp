/*
*  Keyboard.cpp
*
*  Created on: 18 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*/
#include "Keyboard.h"

namespace Phoenix{
	namespace Keyboard{
		std::map<sf::Keyboard::Key, Keystate> keystate;
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
	}
}
