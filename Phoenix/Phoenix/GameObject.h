/*
* GameObject.h
*
*  Created on: 18 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*
*	Description:
*		A simple sceletion for other objects to be built upon
*/
#pragma once

namespace Phoenix{
	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();
		virtual void Update(float DeltaTime);
		virtual void Draw();
	};
}