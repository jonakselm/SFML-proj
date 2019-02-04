#include "stdafx.h"
#include "Brick.h"
#include "Location.h"
#include "Ball.h"


Brick::Brick(sf::Color &c)
	:
	m_shape(sf::Vector2f(40,20))
{
	m_shape.setFillColor(c);
	m_shape.setOutlineThickness(-1.5);
}


Brick::~Brick()
{
}

void Brick::draw(sf::RenderTarget & target) const
{
	if (!destroyed)
	target.draw(m_shape);
}

sf::FloatRect Brick::getGlobalBounds() const
{
	return m_shape.getGlobalBounds();
}

bool Brick::collision(Ball & ball)
{
	if (m_shape.getGlobalBounds().intersects(ball.getGlobalBounds()))
	{
		destroyed = true;
		return true;
	}
	return false;
}
