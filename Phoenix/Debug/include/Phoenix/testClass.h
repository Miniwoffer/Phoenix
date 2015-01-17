#pragma once
#include <Box2D\Box2D.h>
//#include <Phoenix\Scene.h>
namespace Phoenix {
	class __declspec(dllexport) testClass
	{
	public:
		testClass(b2World* world);
		~testClass();
	};
}

