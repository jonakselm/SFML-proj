#pragma once
#include "Shape.hpp"

class Worm : public Shape
{
public:
	Worm(double xPos, double yPos);
	virtual ~Worm();

	void draw(sf::RenderTarget &target) const;
	sf::FloatRect getGlobalBounds() const;
	void move(double theta, double length);
	void grow();
	double speed() const { return m_speed; }
private:
	class Body : public Shape
	{
	public:
		Body();
		Body(sf::Color color);
		void draw(sf::RenderTarget &target) const;
		sf::FloatRect getGlobalBounds() const;
		void move(double theta, double length);
		sf::Vector2f getPosition() const;
		void setPosition(sf::Vector2f pos);
	private:
		sf::CircleShape m_shape;
	};
private:
	std::vector<Body> m_segments;
	double m_speed;
};

