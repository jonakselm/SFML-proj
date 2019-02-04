#include "stdafx.h"
#include "PongBall.h"


PongBall::PongBall(double x, double y, double velX, double velY)
	:
	m_shape(sf::Vector2f(25, 25))
	/*vel(velX, velY),
	pos(x, y)*/
{
	respawn(x, y, velX, velX);
	m_shape.setPosition(pos);
}


PongBall::~PongBall()
{
}

sf::FloatRect PongBall::getGlobalBounds()
{
	return m_shape.getGlobalBounds();
}

void PongBall::draw(sf::RenderTarget & target)
{
	target.draw(m_shape);
}

void PongBall::move()
{
	m_shape.move(vel);
}

double PongBall::reboundX(double velX)
{
	return vel.x = velX;
}

double PongBall::reboundY()
{
	return vel.y *= -1;
}

double PongBall::reboundY(double velY)
{
	return vel.y = velY;
}

void PongBall::respawn(double x, double y, double velX, double velY)
{
	pos = (sf::Vector2f(x, y));
	vel = (sf::Vector2f(velX, velY));

	m_shape.setPosition(pos);
}
