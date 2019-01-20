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
}

void Game::ComposeFrame(sf::RenderTarget& window)
{
	snake.draw(window);
}
