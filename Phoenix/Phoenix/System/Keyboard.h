#ifndef KEYBOARDINP_H
#define KEYBOARDINP_H

#include <map>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

namespace Input{
	enum Keystate
	{
		NONE,
		CLICKED,
		KEYDOWN,
		RELEASED
	};
	class Keyboard
	{
	public:
		static std::map<sf::Keyboard::Key, Keystate> keystate;
		static void keyevent(sf::Event ev);
		static void keyboardupdate();
	};
}
#endif
