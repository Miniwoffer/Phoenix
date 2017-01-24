/*
* Scene.h
*
*  Created on: 17 Nov 2014
*      Author: Odin Hultgren Van Der Horst
* Description:
*		This is the class handels the update and draw function as well as storing the box2d World and pointers to Drawable objects.
*/

#pragma once

#include <SFML/Graphics.hpp>

#include <Box2D/Box2D.h>

#include <vector>
#include <memory>

#include "Convertion.h"
#include "GameObject.h"
#include "Log.h"
namespace Phoenix {

enum AddType
{
	Top,
	Bottom,
	Intersect
};
	class Scene {
public:
	Scene(float gravX,float gravY);
	void Draw(sf::RenderWindow& window, sf::View view);
	void Update(float gametime);
	void addGameObjects(const std::shared_ptr<GameObject> object, AddType location = AddType::Top, unsigned int pos = 0);
	void addGraphics(const std::shared_ptr<sf::Drawable> object, AddType location = AddType::Top, unsigned int pos = 0);
	void addGUIGraphics(const std::shared_ptr<sf::Drawable> object, AddType location = AddType::Top, unsigned int pos = 0);
	b2Body* addPhysics(b2BodyDef& object);


	private:
	b2World world;
	static void doDrawLoop(std::vector<std::shared_ptr<sf::Drawable>>& vec, sf::RenderWindow& window);

	template <typename T>
	static void addObjecToList(std::vector<std::shared_ptr<T>>& vec, std::shared_ptr<T> object, AddType location, unsigned int pos);

	std::vector<std::shared_ptr<GameObject>> gameobjects;
	std::vector<std::shared_ptr<sf::Drawable>> GUIgraphics;
	std::vector<std::shared_ptr<sf::Drawable>> graphics;
};
}

