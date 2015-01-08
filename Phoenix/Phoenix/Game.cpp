#include "game.h"
#include "System/Keyboard.h"
#include "System/Scene.h"
#include "System/Convertion.h"
#include <vector>
#include "Graphics/tiledmap.h"
namespace{
	const int WIDTH = 900;
	const int HEIGHT = 600;
	const int COLORDEPTH = 32;
	const int FRAMERATE = 6000;
	const std::string WINDOWNAME = "OG:Phoenix";
}

game::game()
{
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text fpsCounter;
	fpsCounter.setFont(font);
	fpsCounter.setCharacterSize(30);
	fpsCounter.setStyle(sf::Text::Regular);
	sf::Text boxCounter;
	boxCounter.setFont(font);
	boxCounter.setCharacterSize(30);
	boxCounter.setStyle(sf::Text::Regular);
	boxCounter.setPosition(0, 30);

	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT, COLORDEPTH), WINDOWNAME);
	window->setFramerateLimit(FRAMERATE);
	window->setVerticalSyncEnabled(true);
	System::Scene scene(0.f, 40.f);
	sf::View camera;
	Tiledmap tile("Levels/LevelOne.lvl.tmx", scene);
	scene.addGraphics(tile);
	scene.addGUIGraphics(fpsCounter);
	scene.addGUIGraphics(boxCounter);
	//TODO remove player
	Player pl(scene,100,100);


	std::vector<Graphics::Box*> boxhell;

	camera.setSize(WIDTH, HEIGHT);
	window->setView(camera);
	sf::Clock deltaClock;
	sf::Clock timerClock;
	bool keydown = false;
	int fps = 0;
	int boxes = 0;
	bool pause = false;
	while (window->isOpen())
	{
		fpsCounter.setString("FPS:" + std::to_string(fps));
		boxCounter.setString("Boxes:" + std::to_string(boxes));
		sf::Time dt = deltaClock.restart();
		std::ostringstream ss;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!keydown)
			{
				boxhell.push_back(new Graphics::Box(scene, window->mapPixelToCoords(sf::Mouse::getPosition(*window)).x,
					window->mapPixelToCoords(sf::Mouse::getPosition(*window)).y,
					50, 50));
				boxes++;
			}
			keydown = false;
		}
		else
		{
			keydown = false;
		}
		sf::Event event;
		Input::Keyboard::keyboardupdate();
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::Resized:
				break;
			case sf::Event::MouseWheelMoved:
				camera.zoom(1 - event.mouseWheel.delta*0.1);
				break;
			default:
				break;
			}
			Input::Keyboard::keyevent(event);
		}
		float deltatime = dt.asSeconds();
		if (pause)
		{
			deltatime = 0;
		}
		scene.Update(deltatime);
		scene.Draw(*window, camera);
		update(deltatime);
		fps = 60/dt.asSeconds();
		float moveleng = 500 * dt.asSeconds();
		if (Input::Keyboard::keystate[sf::Keyboard::W] == Input::Keystate::KEYDOWN)
		{
			camera.move(0, -moveleng);
		}
		if (Input::Keyboard::keystate[sf::Keyboard::A] == Input::Keystate::KEYDOWN)
		{
			camera.move(-moveleng, 0);
		}
		if (Input::Keyboard::keystate[sf::Keyboard::S] == Input::Keystate::KEYDOWN)
		{
			camera.move(0, moveleng);
		}
		if (Input::Keyboard::keystate[sf::Keyboard::D] == Input::Keystate::KEYDOWN)
		{
			camera.move(moveleng, 0);
		}
		if (Input::Keyboard::keystate[sf::Keyboard::P] == Input::Keystate::CLICKED)
		{
			pause = !pause;
		}
	}
}

game::~game()
{
}
void game::update(float deltatime){
	for (int i = 0; i < world.size(); i++)
	{
		world[i].Update(deltatime);
	}
}
