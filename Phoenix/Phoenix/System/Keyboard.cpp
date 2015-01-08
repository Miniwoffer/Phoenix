#include "Keyboard.h"

std::map<sf::Keyboard::Key, Input::Keystate> Input::Keyboard::keystate;

void Input::Keyboard::keyevent(sf::Event ev)
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


void Input::Keyboard::keyboardupdate()
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
