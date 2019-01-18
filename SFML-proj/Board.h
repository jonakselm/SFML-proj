#pragma once

#include "Location.h"

class Board
{
public:
	void drawRect(const Location &loc, sf::Color c, sf::RenderTarget &target);
	void drawCircle(const Location &loc, sf::Color c, sf::RenderTarget &target);
	int GetWidth();
	int GetHeight();
private:
	const int dim = 30;
	const int width = 33;
	const int height = 30;
};