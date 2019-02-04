#pragma once

#include "PongBall.h"
#include "Walls.hpp"

class Paddle
{
public:
	Paddle(float p1X, float p1Y, float p2X, float p2Y);
	~Paddle();

	void draw(sf::RenderTarget &target);
	void handleInput();
	sf::FloatRect getPlayerOneBounds() const;
	sf::FloatRect getPlayerTwoBounds() const;
	bool p1TopCollision();
	bool p1BottomCollision();
	bool p2TopCollision();
	bool p2BottomCollision();
private:
	Walls walls;
	sf::Vector2f size;
	sf::Vector2f pos1, pos2;
	sf::RectangleShape m_player1, m_player2;
};