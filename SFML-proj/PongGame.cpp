#include "stdafx.h"
#include "PongGame.hpp"
#include "StateHandler.hpp"
#include <sstream>


PongGame::PongGame()
	:
	rng(rd()),
	xDist(400, 600),
	yDist(300, 500),
	vXDist(-2.0, 2.0),
	vYDist(-2.0, 2.0),
	ballYRebound(-0.4, 0.4),
	p1Rebound(0.4, 2.0),
	p2Rebound(-2.0, -0.4),
	paddle(200, 300, 850, 300),
	pongBall(xDist(rng), yDist(rng), vXDist(rng), vYDist(rng))
{
}


PongGame::~PongGame()
{
}

void PongGame::init(sf::Window &window, StateHandler &stateHandler)
{
	auto &kEsc = keyHandler.addKey(sf::Keyboard::Escape, [&]
		{
			stateHandler.Pop();
		});

	if (!font.loadFromFile("data/fonts/joystix.ttf"))
	{
		//do something
	}

	p1Score.setPosition(10, 10);
	p2Score.setPosition(950, 10);

	p1Score.setCharacterSize(60);
	p2Score.setCharacterSize(60);

	p1Score.setFont(font);
	p2Score.setFont(font);
}

void PongGame::updateModel(sf::Window &window, StateHandler &stateHandler)
{
	std::stringstream scoreP1;
	std::stringstream scoreP2;

	scoreP1 << p1Points;
	scoreP2 << p2Points;

	p1Score.setString(scoreP1.str());
	p2Score.setString(scoreP2.str());


	paddle.handleInput();
	pongBall.move();


	if (walls.rightBounds().intersects(pongBall.getGlobalBounds()))
	{
		pongBall.respawn(xDist(rng), yDist(rng), vXDist(rng), vYDist(rng));
		p1Points++;
	}

	if (walls.leftBounds().intersects(pongBall.getGlobalBounds()))
	{
		pongBall.respawn(xDist(rng), yDist(rng), vXDist(rng), vYDist(rng));
		p2Points++;
	}


	if (pongBall.getGlobalBounds().intersects(paddle.getPlayerOneBounds()))
	{
			pongBall.reboundX(p1Rebound(rng));
			pongBall.reboundY(ballYRebound(rng));
	}

	if (pongBall.getGlobalBounds().intersects(paddle.getPlayerTwoBounds()))
	{
			pongBall.reboundX(p2Rebound(rng));
			pongBall.reboundY(ballYRebound(rng));
	}

	if (pongBall.getGlobalBounds().intersects(walls.topBounds()) ||
		pongBall.getGlobalBounds().intersects(walls.bottomBounds()))
			pongBall.reboundY();
}

void PongGame::draw(sf::RenderTarget & target)
{
	walls.draw(target);
	paddle.draw(target);
	pongBall.draw(target);

	target.draw(p1Score);
	target.draw(p2Score);
}
