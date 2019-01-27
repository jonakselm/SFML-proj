#include "pch.h"
#include "Ball.h"


Ball::Ball()
{
}


Ball::~Ball()
{
}

sf::FloatRect Ball::getGlobalBounds()
{
	return m_shape.getGlobalBounds();
}
