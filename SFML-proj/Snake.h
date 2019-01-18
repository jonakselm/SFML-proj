#pragma once

#include "Board.h"
#include <vector>

class Snake
{
private:
	class Segment
	{
	public:
		Segment(const Location &in_loc);
		Segment(sf::Color c_in);
		void Draw(Board &brd, sf::RenderTarget &target) const;
		void Follow(const Segment &next);
		void MoveBy(const Location &delta_loc);
		const Location &GetLocation() const;
	private:
		Location loc;
		sf::Color c;
	};
public:
	Snake(const Location &loc);
	Location nextHeadLoc(const Location& delta_loc) const;
	void GrowAndMoveBy(const Location &delta_loc);
	void Draw(Board &brd, sf::RenderTarget &target) const;
	void MoveBy(const Location &delta_loc);
	bool inTile(const Location &lTarget) const;
	bool inTileExceptEnd(const Location& lTarget) const;
private:
	sf::Color bodyColor = sf::Color::Magenta;
	//static const sf::Color headColor = sf::Color::Green;
	std::vector<Segment> segments;
};