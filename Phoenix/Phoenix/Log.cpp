/*
* Log.cpp
*
*  Created on: 17 Jan 2015
*      Author: Odin Hultgren Van Der Horst
* Description:
*		This is the class that handels the output to the console.
*/

#include "Log.h"

namespace Phoenix
{
	using std::cout;
	using std::endl;
	enum Colorcodes{
		error = 12,//red
		debug = 11,//blue
		warning = 14,//yellow
		normal = 15 //White
	};
	//a private function for chaning the color of the console
	void setConsoleColor(Colorcodes color){
		unsigned short wAttributes = (unsigned)color;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wAttributes);
	}

	void Log::error(std::string message){
		setConsoleColor(Colorcodes::error);
		cout << ":::::::::ERROR:::::::::" << endl;
		setConsoleColor(Colorcodes::normal);
		cout << message << endl;
	}

	void Log::debug(char* message){
		setConsoleColor(Colorcodes::debug);
		cout << ":::::::::DEBUG:::::::::" << endl;
		setConsoleColor(Colorcodes::normal);
		cout << message << endl;
	}

	void Log::warning(char* message){
		setConsoleColor(Colorcodes::warning);
		cout << "::::::::WARNING::::::::" << endl;
		setConsoleColor(Colorcodes::normal);
		cout << message << endl;
	}
}