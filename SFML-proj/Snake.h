#pragma once

#include "Location.h"
#include <vector>

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location &in_loc);
		void InitBody(sf::Color c_in);
	private:
	};
public:
	Snake(const Location &loc);
	Location nextHeadLoc(const Location& delta_loc) const;
	void Grow();
private:
	std::vector<int> segments;
	sf::Color headColor = sf::Color::Green;
};