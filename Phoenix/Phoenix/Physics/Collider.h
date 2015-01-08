/*
 * Collider.h
 *
 *  Created on: 17 Nov 2014
 *      Author: Odin Hultgren Van Der Horst
 */
#pragma once

//Export all the functions to the dll
#ifdef COLLIDER_EXPORTS
#define COLLIDER_API __declspec(dllexport) 
#else
#define COLLIDER_API __declspec(dllimport) 
#endif

#include "../System/GameObject.h"
namespace Phoenix {

class Collider {
public:
	Collider(GameObject* Parent);
	virtual ~Collider();
	virtual void Update();
	GameObject* Parent;
	bool Active = false;
};

}

