#pragma once

#include "Shape.hpp"

class Ball;
class Brick : public Shape
{
public:
	Brick(sf::Color &c);
	virtual ~Brick();

	void draw(sf::RenderTarget &target) const;
	sf::FloatRect getGlobalBounds() const;
	bool collision(Ball &ball);
private:
	sf::RectangleShape m_shape;
	bool destroyed = false;
};

