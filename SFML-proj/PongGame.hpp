#pragma once

#include "State.hpp"
#include "PongBall.h"
#include "Paddle.h"
#include "Walls.hpp"
#include <random>
#include "KeyHandler.hpp"

class PongGame : public State
{
public:
	PongGame();
	virtual ~PongGame();

	void init(sf::Window &window, StateHandler &stateHandler);
	void updateModel(sf::Window &window, StateHandler &stateHandler);
	void draw(sf::RenderTarget &target);


private:
	KeyHandler keyHandler;
	sf::Font font;
	sf::Text p1Score;
	sf::Text p2Score;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<double> xDist, yDist, vXDist, vYDist, p1Rebound, p2Rebound, ballYRebound;
	Walls walls;
	Paddle paddle;
	PongBall pongBall;
	int p1Points = 0, p2Points = 0;
};

