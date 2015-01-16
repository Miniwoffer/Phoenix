#include "Convertion.h"
namespace Phoenix
{
	template <typename T>
	void logAction(const T message)
	{
		std::cout << linenum << ": " << message << std::endl;
		linenum++;
	}
	sf::Vector2f bTOs(const b2Vec2 b2vec)
	{
		return sf::Vector2f(b2vec.x / SIMULATOINRATE, b2vec.y / SIMULATOINRATE);
	}
	b2Vec2 sTOb(const sf::Vector2f sfvec2)
	{
		return b2Vec2(sfvec2.x*SIMULATOINRATE, sfvec2.y*SIMULATOINRATE);
	}


	sf::Vector2f bTOs(const float x, const float y)
	{
		return sf::Vector2f(x / SIMULATOINRATE, y / SIMULATOINRATE);
	}
	b2Vec2 sTOb(const float x, const float y)
	{
		return b2Vec2(x*SIMULATOINRATE, y*SIMULATOINRATE);
	}


	float bTOs(const float x)
	{
		return x / SIMULATOINRATE;
	}
	float sTOb(const float x)
	{
		return x*SIMULATOINRATE;
	}

	float radianTorot(const float radian)
	{
		return (float)((radian / 3.14) * 180);
	}
	float totToradian(const float rot)
	{
		return(float)((rot*3.14) / 180);
	}
}
