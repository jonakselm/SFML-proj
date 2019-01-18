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
		delta_loc = { 0,-1 };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		delta_loc = { 0,1 };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		delta_loc = { -1,0 };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		delta_loc = { 1,0 };

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
