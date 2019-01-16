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
	/*for (int y = 0; y < brd.GetHeight(); y++)
		for (int x = 0; x < brd.GetWidth(); x++)
			brd.drawCell({ x,y }, sf::Color(std::rand() % 256 - 1, std::rand() % 256 - 1, std::rand() % 256 - 1), window);
	*/
}
