#pragma once

#include "Location.h"

class Board
{
public:
	void drawCell(const Location &loc, sf::Color c, sf::RenderTarget &target);
	int GetWidth();
	int GetHeight();
private:
	const int dim = 30;
	const int width = 33;
	const int height = 30;
};