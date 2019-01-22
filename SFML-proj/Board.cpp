#include "pch.h"
#include "Board.h"

void Board::drawRect(const Location & loc, sf::Color c, sf::RenderTarget & target)
{
	sf::RectangleShape shape(sf::Vector2f(dim, dim));
	shape.setFillColor(c);
	shape.setPosition(loc.x * dim, loc.y * dim);
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(2);
	target.draw(shape);
}

void Board::drawCircle(const Location & loc, sf::Color c, sf::RenderTarget & target)
{
	sf::CircleShape shape(dim / 2);
	shape.setFillColor(c);
	shape.setPosition(loc.x * dim, loc.y * dim);
	target.draw(shape);
}
