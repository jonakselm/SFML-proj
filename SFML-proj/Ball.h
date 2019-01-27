#pragma once

#include "Shape.hpp"

class Ball : public Shape
{
public:
	Ball();
	virtual ~Ball();

	sf::FloatRect getGlobalBounds();

private:
	sf::CircleShape m_shape;
};

