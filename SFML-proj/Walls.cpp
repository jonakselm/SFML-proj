#include "stdafx.h"
#include "Walls.hpp"


Walls::Walls()
	:
	borderTop(sf::Vector2f(width * dim, dim)),
	borderBottom(sf::Vector2f(width * dim, dim)),
	borderLeft(sf::Vector2f(dim, height * dim)),
	borderRight(sf::Vector2f(dim, height * dim))
{
	borderTop.setPosition(offsetX, offsetY);
	borderBottom.setPosition(offsetX, offsetY + (height * dim));
	borderLeft.setPosition(offsetX - dim * 2, offsetY);
	borderRight.setPosition(offsetX + (width * dim) + dim, offsetY);
}


Walls::~Walls()
{
}

void Walls::draw(sf::RenderTarget & target) const
{
	target.draw(borderTop);
	target.draw(borderBottom);
	//target.draw(borderLeft);
	//target.draw(borderRight);
}

sf::FloatRect Walls::boardBounds()
{
	return sf::FloatRect(offsetX, offsetY, width * dim - dim, height * dim - dim);
}

sf::FloatRect Walls::topBounds()
{
	return borderTop.getGlobalBounds();
}

sf::FloatRect Walls::bottomBounds()
{
	return borderBottom.getGlobalBounds();
}

sf::FloatRect Walls::leftBounds()
{
	return borderLeft.getGlobalBounds();
}

sf::FloatRect Walls::rightBounds()
{
	return borderRight.getGlobalBounds();
}
