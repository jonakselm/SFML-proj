#include "pch.h"
#include "Game.h"

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
}
