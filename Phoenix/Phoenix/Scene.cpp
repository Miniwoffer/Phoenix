/*
* Scene.cpp
*
*  Created on: 17 Nov 2014
*      Author: Odin Hultgren Van Der Horst
*
* Description:
*		This is the class handels the update and draw function as well as storing the box2d World and pointers to Drawable objects.
*/

#include "Scene.h"
#include <iostream>
namespace Phoenix {
	//Initiates the box2D world with the provided parameters.
	Scene::Scene(float gravX, float gravY) : world(b2Vec2(gravX, gravY)) {}
	void Scene::addGraphics(const std::shared_ptr<sf::Drawable> object, AddType location, unsigned int pos)
	{
		addObjecToList(graphics, object, location, pos);
	}
	void Scene::addGUIGraphics(const std::shared_ptr<sf::Drawable> object, AddType location, unsigned int pos)
	{
		addObjecToList(GUIgraphics, object, location, pos);
	}
	void Scene::addGameObjects(const std::shared_ptr<GameObject> object, AddType location, unsigned int pos)
	{
		addObjecToList(gameobjects, object, location, pos);
	}

	//a wrapper function to restrict the access to the Box2D world
	b2Body* Scene::addPhysics(b2BodyDef& object)
	{
		return (world.CreateBody(&object));
	}

	void Scene::Draw(sf::RenderWindow& window, sf::View view)
	{
		//Clear the screen to a deafult Cyan color
		window.clear(sf::Color::Cyan);
		//Sets the veiw to the camera
		window.setView(view);
		//Draw all the graphics located in the world
		doDrawLoop(graphics, window);
		//Sets the camera to 0 x and 0 y so we can draw any graphics that dosnt move with the world
		window.setView(window.getDefaultView());
		//draws all the graphics on the GUI layer
		doDrawLoop(GUIgraphics, window);
		//flips the buffer so the next frame gets drawn
		window.display();
	}


	void Scene::Update(float gametime)
	{
		for (auto it = gameobjects.begin(); it != gameobjects.end(); ++it)
		{
			(*it)->Update(gametime);
		}
		world.Step(gametime, 6, 2);
	}

	//loops thorugh and draws all the objects
	void Scene::doDrawLoop(std::vector<std::shared_ptr<sf::Drawable>>& vec, sf::RenderWindow& window)
	{
		for (auto it = vec.begin(); it != vec.end(); ++it)
		{
			window.draw(*(*it));
		}
	}


	//a function that first checks if the pointer is valid, adds it to the list.
	template <class T> 
	void Scene::addObjecToList(std::vector<std::shared_ptr<T>>& vec, std::shared_ptr<T> object, AddType location, unsigned int pos)
	{
		if (!object)
		{
			Log::error("GameObject or Drawable not instantiated,\nfailed to add it to the scene!");
		}
		else
		{
			auto itr = vec.begin();

			switch (location){
			case Top:
				vec.push_back(object);
				return;
				break;

			case Intersect:
				itr += pos;
				break;
			}
			vec.insert(itr, object);
		}
	}
}
