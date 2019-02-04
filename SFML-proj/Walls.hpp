#pragma once
class Walls
{
public:
	Walls();
	~Walls();

	void draw(sf::RenderTarget &target) const;
	sf::FloatRect boardBounds();
	sf::FloatRect topBounds();
	sf::FloatRect bottomBounds();
	sf::FloatRect leftBounds();
	sf::FloatRect rightBounds();
private:
	const float offsetX = 130, offsetY = 75;
	const float width = 40, height = 26, dim = 20;
	sf::RectangleShape borderTop, borderBottom, borderLeft, borderRight;
};

