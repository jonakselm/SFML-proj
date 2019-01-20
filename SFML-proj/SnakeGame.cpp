#include "pch.h"
#include "SnakeGame.hpp"
#include "StateHandler.hpp"

SnakeGame::SnakeGame()
	:
	snake ({ 1,1 })
{
}


SnakeGame::~SnakeGame()
{
}

void SnakeGame::init(sf::Window & window, StateHandler & stateHandler)
{
	auto &esc = keyHandler.addKey(sf::Keyboard::Escape, [&]
		{
			stateHandler.Pop();
		});
}

void SnakeGame::updateModel(sf::Window & window, StateHandler & stateHandler)
{
	keyHandler.handleKeyInput();

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

		if (snake.intersects(m_apple))
		{
			m_apple.respawn();
			snake.GrowAndMoveBy(delta_loc);
		}
		else
		{
			snake.MoveBy(delta_loc);
		}
	}


	snakeMovePeriod = std::max(snakeMovePeriod - dt * snakeSpeedupFactor, snakeMovePeriodMin);
}

void SnakeGame::draw(sf::RenderTarget & target)
{
	m_apple.draw(target);
	snake.draw(target);
}
