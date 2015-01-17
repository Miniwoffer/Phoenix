#include "Player.h"
namespace
{
	const int HEIGHT = 100;
	const int WIDTH = 50;
}
Player::Player(Phoenix::Scene& scene, float x, float y)
{
	rect.setSize(sf::Vector2f(WIDTH, HEIGHT));
	rect.setOrigin(sf::Vector2f(WIDTH / 2, HEIGHT / 2));
	rect.setPosition(sf::Vector2f(x, y));
	rect.setFillColor(sf::Color::Red);


	b2BodyDef def;
	def.position = Phoenix::sTOb(x, y);
	def.type = b2_dynamicBody;
	def.fixedRotation = true;
	body = scene.addPhysics(def);
	b2Vec2 sizeboxsim(Phoenix::sTOb(WIDTH / 2, HEIGHT / 2));
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
	if (Phoenix::Keyboard::keystate[sf::Keyboard::Right] == Phoenix::Keystate::KEYDOWN)
	{
		movementx += 10;
	}
	if (Phoenix::Keyboard::keystate[sf::Keyboard::Left] == Phoenix::Keystate::KEYDOWN)
	{
		movementx -= 10;
	}
	if (Phoenix::Keyboard::keystate[sf::Keyboard::Space] == Phoenix::Keystate::CLICKED)
	{
		movementy -= 10;
	}
	//body->SetTransform(b2Vec2(body->GetTransform().p.x + (movementx*DeltaTime), body->GetTransform().p.y + (movementy*DeltaTime)), body->GetAngle());
	body->SetLinearVelocity(b2Vec2(movementx*DeltaTime, body->GetLinearVelocity().y + (movementy*DeltaTime)));
	rect.setPosition(Phoenix::bTOs(body->GetPosition()));
	rect.setRotation(Phoenix::radianTorot(body->GetAngle()));
}
