#pragma once

#include "Walls.hpp"

class PongBall
{
public:
	PongBall(double x, double y, double velX, double velY);
	~PongBall();
	sf::FloatRect getGlobalBounds();
	void draw(sf::RenderTarget &target);
	void move();
	double reboundX(double velX);
	double reboundY();
	double reboundY(double velY);
	void respawn(double x, double y, double velX, double velY);
private:
	Walls walls;
	sf::RectangleShape m_shape;
	sf::Vector2f vel;
	sf::Vector2f pos;
};

