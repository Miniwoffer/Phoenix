/*
* Log.h
*
*  Created on: 17 Jan 2015
*      Author: Odin Hultgren Van Der Horst
* Description:
*		This is the class that handels the output to the console.
*/

#pragma once
#include <iostream>
#include <string>
namespace Phoenix 
{
	namespace Log
	{
		void error(std::string message);
		void debug(char* message);
		void warning(char* message);
	};
}

