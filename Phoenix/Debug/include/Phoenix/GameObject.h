/*
* GameObject.h
*
*  Created on: 18 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*/
#pragma once
#ifdef GAMEOBJECT_EXPORTS
#define GAMEOBJECT_API __declspec(dllexport) 
#else
#define GAMEOBJECT_API __declspec(dllimport) 
#endif
namespace Phoenix{
	class __declspec(dllexport) GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();
		virtual void Update(float DeltaTime);
		virtual void Draw();
	};
}