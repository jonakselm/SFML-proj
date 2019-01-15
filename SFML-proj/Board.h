#pragma once

#include "Location.h"

class Board
{
public:
	void drawCell(const Location &loc, sf::Color c, sf::RenderTarget &target);
	float GetWidth();
	float GetHeight();
private:
	const int dim = 40;
	const float width = 25.f;
	const float height = 22.5f;
};