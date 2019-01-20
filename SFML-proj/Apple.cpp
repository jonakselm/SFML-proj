#include "pch.h"
#include "Apple.h"
#include "Board.h"

Apple::Apple() :
	m_shape(15.f)
{
	m_shape.setFillColor(sf::Color::Red);
	respawn();
}


void Apple::respawn()
{
	m_shape.setPosition(float(std::rand() % (Board::dim * (Board::width - 1))), float(std::rand() % Board::dim * (Board::height - 1)));
}

void Apple::draw(sf::RenderTarget &target) const
{
	target.draw(m_shape);
}

sf::FloatRect Apple::getGlobalBounds() const
{
	return m_shape.getGlobalBounds();
}
