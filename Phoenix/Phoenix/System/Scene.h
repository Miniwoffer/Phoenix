/*
 * Scene.h
 *
 *  Created on: 17 Nov 2014
 *      Author: odin
 */

#ifndef SCENE_H_
#define SCENE_H_
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "Convertion.h"
#include "GameObject.h"
#include <vector>
namespace System {
enum GraphicsLocation
{
	World,
	WorldBottom,
	GUI,
	GUIBottom
};
enum AddType
{
	Top,
	Bottom
};
class Scene {
public:
	Scene(float gravX,float gravY);
	virtual ~Scene();
	void Draw(sf::RenderWindow& window, sf::View view);
	void Update(float gametime);
	void addGameObjects(GameObject& object, AddType location = AddType::Top);
	void addGraphics(sf::Drawable& object, GraphicsLocation location = GraphicsLocation::World);
	void addGUIGraphics(sf::Drawable& object, GraphicsLocation location = GraphicsLocation::World);
	void addDebugGraphics(sf::Drawable& object, GraphicsLocation location = GraphicsLocation::World);
	b2Body* addPhysics(b2BodyDef object, AddType location = AddType::Top);
private:
	b2World* world;
	std::vector<GameObject*> gameobjects;
	std::vector<sf::Drawable*> GUIgraphics;
	std::vector<sf::Drawable*> Debuggraphics;
	std::vector<sf::Drawable*> graphics;
};

} /* namespace Graphics */

#endif /* SCENE_H_ */
