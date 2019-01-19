#include "pch.h"
#include "Board.h"

void Board::drawRect(const Location & loc, sf::Color c, sf::RenderTarget &target)
{
	
	sf::RectangleShape rect(sf::Vector2f(dim, dim));
	rect.setFillColor(c);
	rect.setOutlineColor(sf::Color::Blue);
	rect.setOutlineThickness(3);
	rect.setPosition(float(loc.x * dim), float(loc.y * dim));
	target.draw(rect);
}

void Board::drawCircle(const Location & loc, sf::Color c, sf::RenderTarget & target)
{
	sf::CircleShape circle(float(dim / 2));
	circle.setFillColor(c);
	//circle.setOutlineColor(sf::Color::Blue);
	//circle.setOutlineThickness(3);
	circle.setPosition(float(loc.x * dim / 2), float(loc.y * dim / 2));
	target.draw(circle);
}

int Board::GetWidth()
{
	return width;
}

int Board::GetHeight()
{
	return height;
}
