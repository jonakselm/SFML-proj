#include "stdafx.h"
#include "Paddle.h"

Paddle::Paddle(float p1X, float p1Y, float p2X, float p2Y)
	:
	size(20, 80),
	m_player1(size),
	m_player2(size),
	pos1(p1X, p1Y),
	pos2(p2X, p2Y)
{
	m_player1.setPosition(pos1);
	m_player2.setPosition(pos2);
}

Paddle::~Paddle()
{
}

void Paddle::draw(sf::RenderTarget & target)
{
	target.draw(m_player1);
	target.draw(m_player2);
}

void Paddle::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !p1TopCollision())
		m_player1.move(0, -1);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !p1BottomCollision())
		m_player1.move(0, 1);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !p2TopCollision())
		m_player2.move(0, -1);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !p2BottomCollision())
		m_player2.move(0, 1);
}

sf::FloatRect Paddle::getPlayerOneBounds() const
{
	return m_player1.getGlobalBounds();
}

sf::FloatRect Paddle::getPlayerTwoBounds() const
{
	return m_player2.getGlobalBounds();
}

bool Paddle::p1TopCollision()
{
	if (walls.topBounds().intersects(m_player1.getGlobalBounds()))
		return true;

	return false;
}

bool Paddle::p1BottomCollision()
{
	if (walls.bottomBounds().intersects(m_player1.getGlobalBounds()))
		return true;

	return false;
}

bool Paddle::p2TopCollision()
{
	if (walls.topBounds().intersects(m_player2.getGlobalBounds()))
		return true;

	return false;
}

bool Paddle::p2BottomCollision()
{
	if (walls.bottomBounds().intersects(m_player2.getGlobalBounds()))
		return true;

	return false;
}
