#pragma once

#include "Board.h"
#include "Snake.h"
#include "FrameTimer.h"

class Game
{
public:
	Game();
	void Go (sf::RenderTarget &window);
private:
	void UpdateModel();
	void ComposeFrame(sf::RenderTarget &window);
public:
private:
	Board brd;
	Snake snake;
	Location delta_loc = { 1,0 };
	FrameTimer ft;
	static constexpr float snakeMovePeriodMin = 0.06f;
	float snakeMovePeriod = 0.4f;
	float snakeMoveCounter = 0.0f;
	static constexpr float snakeSpeedupFactor = 0.005f;
};                                                                                                                                                                                                                                                         