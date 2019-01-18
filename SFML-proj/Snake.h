#pragma once

#include "Board.h"
#include <vector>

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location &in_loc);
		void InitBody(sf::Color c_in);
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
	void Grow();
	void Draw(Board &brd, sf::RenderTarget &target) const;
	void MoveBy(const Location &delta_loc);
	bool inTile(const Location &lTarget) const;
	bool inTileExceptEnd(const Location& lTarget) const;
private:
	std::vector<Segment> segments;
};