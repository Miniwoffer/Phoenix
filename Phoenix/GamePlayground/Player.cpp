#include "Player.h"
#include "Keyboard.h"
namespace
{
	const int HEIGHT = 100;
	const int WIDTH = 50;
}
Player::Player(System::Scene& scene, float x, float y)
{
	rect.setSize(sf::Vector2f(WIDTH, HEIGHT));
	rect.setOrigin(sf::Vector2f(WIDTH / 2, HEIGHT / 2));
	rect.setPosition(sf::Vector2f(x, y));
	rect.setFillColor(sf::Color::Red);

	b2BodyDef def;
	def.position = tools::sTOb(x, y);
	def.type = b2_dynamicBody;
	def.fixedRotation = true;
	body = scene.addPhysics(def);
	b2Vec2 sizeboxsim(tools::sTOb(WIDTH / 2, HEIGHT / 2));
	b2PolygonShape shape;
	shape.SetAsBox(sizeboxsim.x, sizeboxsim.y);
	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = 1.0f;
	fixture.friction = 100.f;
	body->CreateFixture(&fixture);
	body->SetBullet(true);

	scene.addGraphics(rect);
	scene.addGameObjects(*this);
}


Player::~Player()
{
}
void Player::Update(float DeltaTime)
{
	float movementx(0);
	float movementy(0);
	if (Input::Keyboard::keystate[sf::Keyboard::Right] == Input::Keystate::KEYDOWN)
	{
		movementx += 10;
	}
	if (Input::Keyboard::keystate[sf::Keyboard::Left] == Input::Keystate::KEYDOWN)
	{
		movementx -= 10;
	}
	if (Input::Keyboard::keystate[sf::Keyboard::Space] == Input::Keystate::CLICKED)
	{
		movementy -= 10;
	}
	//body->SetTransform(b2Vec2(body->GetTransform().p.x + (movementx*DeltaTime), body->GetTransform().p.y + (movementy*DeltaTime)), body->GetAngle());
	body->SetLinearVelocity(b2Vec2(movementx*DeltaTime, body->GetLinearVelocity().y + (movementy*DeltaTime)));
	rect.setPosition(tools::bTOs(body->GetPosition()));
	rect.setRotation(tools::radianTorot(body->GetAngle()));
}
