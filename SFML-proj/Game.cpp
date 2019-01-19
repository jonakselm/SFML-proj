#include "pch.h"
#include "Game.h"

Game::Game()
	:
	snake({ 1,1 })
{
}

void Game::Go(sf::RenderTarget& window)
{
	UpdateModel();
	ComposeFrame(window);
}

void Game::UpdateModel()
{
	float dt = ft.Mark();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		const Location new_delta_loc = { 0,-1 };
		if (delta_loc != -new_delta_loc || snake.GetLenght() <= 2)
			delta_loc = new_delta_loc;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		const Location new_delta_loc = { 0,1 };
		if (delta_loc != -new_delta_loc || snake.GetLenght() <= 2)
			delta_loc = new_delta_loc;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		const Location new_delta_loc = { -1,0 };
		if (delta_loc != -new_delta_loc || snake.GetLenght() <= 2)
			delta_loc = new_delta_loc;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		const Location new_delta_loc = { 1,0 };
		if (delta_loc != -new_delta_loc || snake.GetLenght() <= 2)
			delta_loc = new_delta_loc;
	}

	snakeMoveCounter += dt;

	if (snakeMoveCounter >= snakeMovePeriod)
	{
		snakeMoveCounter -= snakeMovePeriod;
		const Location next = snake.nextHeadLoc(delta_loc);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			snake.GrowAndMoveBy(delta_loc);
		}
		else
		{
			snake.MoveBy(delta_loc);
		}
	}
	snakeMovePeriod = std::max(snakeMovePeriod - dt * snakeSpeedupFactor, snakeMovePeriodMin);
}

void Game::ComposeFrame(sf::RenderTarget& window)
{
	snake.Draw(brd, window);
}
