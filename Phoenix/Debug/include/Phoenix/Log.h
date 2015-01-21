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
#include <windows.h>
#include <string>
namespace Phoenix 
{
	namespace Log
	{
		__declspec(dllexport) void error(std::string message);
		__declspec(dllexport) void debug(char* message);
		__declspec(dllexport) void warning(char* message);
	};
}

