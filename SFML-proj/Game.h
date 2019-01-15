#pragma once

#include "Board.h"

class Game
{
public:
	void Go(sf::RenderTarget& window);
private:
	void UpdateModel();
	void ComposeFrame(sf::RenderTarget& window);
public:
private:
	Board brd;
};