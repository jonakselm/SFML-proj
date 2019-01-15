#include "pch.h"
#include "Board.h"

void Board::drawCell(const Location & loc, sf::Color c, sf::RenderTarget &target)
{
	
	sf::RectangleShape rect(sf::Vector2f(dim, dim));
	rect.setFillColor(c);
	rect.setPosition(loc.x * dim, loc.y * dim);
	target.draw(rect);
}

int Board::GetWidth()
{
	return width;
}

int Board::GetHeight()
{
	return height;
}
