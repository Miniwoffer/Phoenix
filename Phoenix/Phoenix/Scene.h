/*
* Scene.h
*
*  Created on: 17 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*/
#pragma once
#ifdef SCENE_EXPORTS
#define SCENE_API __declspec(dllexport) 
#else
#define SCENE_API __declspec(dllimport) 
#endif

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "Convertion.h"
#include "GameObject.h"
#include <vector>
namespace Phoenix {
	enum __declspec(dllexport) GraphicsLocation
{
	World,
	WorldBottom,
	GUI,
	GUIBottom
};
	enum __declspec(dllexport) AddType
{
	Top,
	Bottom
};
	class __declspec(dllexport) Scene {
public:
	Scene(float gravX,float gravY);
	virtual ~Scene();
	void Draw(sf::RenderWindow& window, sf::View view);
	void Update(float gametime);
	void addGameObjects(GameObject& object, AddType location = AddType::Top);
	void addGraphics(sf::Drawable& object);
	void addGUIGraphics(sf::Drawable& object);
	b2Body* addPhysics(b2BodyDef object, AddType location = AddType::Top);
	b2World* getWorld();
private:
	b2World* world;
	std::vector<GameObject*> gameobjects;
	std::vector<sf::Drawable*> GUIgraphics;
	std::vector<sf::Drawable*> Debuggraphics;
	std::vector<sf::Drawable*> graphics;
};

}

