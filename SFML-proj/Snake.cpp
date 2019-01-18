#include "pch.h"
#include "Snake.h"

Snake::Snake(const Location & loc)
{
	for (int i = 0; i < segments.size(); i++)
	{
		segments[i].InitBody(sf::Color::Magenta);
	}

	segments[0].InitHead(loc);
}

Location Snake::nextHeadLoc(const Location & delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

void Snake::Grow()
{
	segments.emplace_back();
}

void Snake::Segment::InitHead(const Location & in_loc)
{
	loc = in_loc;
	c = sf::Color::Green;
}

void Snake::Segment::InitBody(sf::Color c_in)
{
	c = c_in;
}

void Snake::Segment::Draw(Board & brd, sf::RenderTarget &target) const
{
	brd.drawCell(loc, c, target);
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	loc.Add(delta_loc);
}

const Location & Snake::Segment::GetLocation() const
{
	return loc;
}

void Snake::Draw(Board & brd, sf::RenderTarget &target) const
{
	for (int i = 0; i < segments.size(); i++)
	{
		segments[i].Draw(brd, target);
	}
}

void Snake::MoveBy(const Location & delta_loc)
{
	for (int i = (int)segments.size() - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

bool Snake::inTile(const Location & lTarget) const
{
	for (int i = 0; i < (int)segments.size(); i++)
	{
		if (segments[i].GetLocation() == lTarget)
		{
			return true;
		}
	}
}

bool Snake::inTileExceptEnd(const Location & lTarget) const
{
	for (int i = 0; i < (int)segments.size() - 1; i++)
	{
		if (segments[i].GetLocation() == lTarget)
		{
			return true;
		}
	}
}

