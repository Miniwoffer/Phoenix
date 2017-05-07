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
	
	void Log::error(std::string message){
		cout << ":::::::::ERROR:::::::::" << endl;
		cout << message << endl;
	}

	void Log::debug(char* message){
		cout << ":::::::::DEBUG:::::::::" << endl;
		cout << message << endl;
	}

	void Log::warning(char* message){
		cout << "::::::::WARNING::::::::" << endl;
		cout << message << endl;
	}
}