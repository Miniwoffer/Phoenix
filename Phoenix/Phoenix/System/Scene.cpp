/*
 * Scene.cpp
 *
 *  Created on: 17 Nov 2014
 *      Author: odin
 */

#include "Scene.h"
#include <iostream>
namespace System {

Scene::Scene(float gravX,float gravY) {
	b2Vec2 gravity(gravX,gravY);
	world = new b2World(gravity);

}

Scene::~Scene() {
	delete world;
}
void Scene::addGraphics(sf::Drawable& object, GraphicsLocation location)
{
	graphics.push_back(&object);
}
void Scene::addGUIGraphics(sf::Drawable& object, GraphicsLocation location)
{
	GUIgraphics.push_back(&object);
}
void Scene::addDebugGraphics(sf::Drawable& object, GraphicsLocation location)
{
	Debuggraphics.push_back(&object);
}
void Scene::addGameObjects(GameObject& object, AddType location)
{
	gameobjects.push_back(&object);
}

b2Body* Scene::addPhysics(b2BodyDef object, AddType location)
{
	return (world->CreateBody(&object));
}

void Scene::Draw(sf::RenderWindow& window,sf::View view)
{
	window.clear(sf::Color::Cyan);
	window.setView(view);
	for(int i = 0; i < graphics.size();i++)
	{
		window.draw(*graphics[i]);
	}
	for (int i = 0; i < Debuggraphics.size(); i++)
	{
		window.draw(*Debuggraphics[i]);
	}
	window.setView(window.getDefaultView());
	for (int i = 0; i < GUIgraphics.size(); i++)
	{
		window.draw(*GUIgraphics[i]);
	}
	window.setView(view);
	window.display();
}
void Scene::Update(float gametime)
{
	for(unsigned int i = 0; i < gameobjects.size();i++)
	{
		gameobjects[i]->Update(gametime);
	}
	world->Step(gametime, 6, 2);
}
} /* namespace Graphics */
