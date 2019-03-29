#include "stdafx.h"
#include "Worm.hpp"
#include <vector>


Worm::Worm(double xPos, double yPos)
{
	auto &head = m_segments.emplace_back();
	head.setPosition(sf::Vector2f(xPos, yPos));
	m_speed = 200;
}


Worm::~Worm()
{
}

void Worm::draw(sf::RenderTarget & target) const
{
	for (auto it = m_segments.rbegin(); it != m_segments.rend(); ++it)
	{
		it->draw(target);
	}
}

sf::FloatRect Worm::getGlobalBounds() const
{
	return m_segments.front().getGlobalBounds();
}

void Worm::move(double theta, double length)
{
	for (size_t i = m_segments.size() - 1; i > 0; i--)
	{
		m_segments[i].setPosition(m_segments[i - 1].getPosition());
	}
	m_segments.front().move(theta, length);

	sf::Vector2f prev = { m_segments.front().getPosition() };

	if (m_segments.front().getPosition().x < -10)
		m_segments.front().setPosition(sf::Vector2f(prev.x + 1020, prev.y));
	else if (m_segments.front().getPosition().x > 1000)
		m_segments.front().setPosition(sf::Vector2f(prev.x - 1020, prev.y));

	if (m_segments.front().getPosition().y < -10)
		m_segments.front().setPosition(sf::Vector2f(prev.x, prev.y + 930));
	else if (m_segments.front().getPosition().y > 910)
		m_segments.front().setPosition(sf::Vector2f(prev.x, prev.y - 930));
}

void Worm::grow()
{
	for (int i = 0; i < 10; i++)
		m_segments.emplace_back(sf::Color(std::rand() % 255, std::rand() % 255, std::rand() % 255));
}

Worm::Body::Body()
	:
	m_shape(15.f)
{
	m_shape.setPosition(100, 100);
	m_shape.setFillColor(sf::Color::Green);
}

Worm::Body::Body(sf::Color color)
	:
	m_shape(15.f)
{
	m_shape.setFillColor(color);
}

void Worm::Body::draw(sf::RenderTarget & target) const
{
	target.draw(m_shape);
}

sf::FloatRect Worm::Body::getGlobalBounds() const
{
	return m_shape.getGlobalBounds();
}

void Worm::Body::move(double theta, double length)
{
	sf::Vector2f delta;
	delta.x = length * cos(theta);
	delta.y = length * sin(theta);

	auto prev = m_shape.getPosition();
	m_shape.setPosition(prev + delta);
}

sf::Vector2f Worm::Body::getPosition() const
{
	return m_shape.getPosition();
}

void Worm::Body::setPosition(sf::Vector2f pos)
{
	m_shape.setPosition(pos);
}
