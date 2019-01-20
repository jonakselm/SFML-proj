#include "pch.h"
#include "Snake.h"

Snake::Snake(const Location & loc)
	:
	shape(sf::Vector2f(Board::dim, Board::dim))
{
	segments.emplace_back(loc);
}

Location Snake::nextHeadLoc(const Location & delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

void Snake::GrowAndMoveBy(const Location &delta_loc)
{
	segments.emplace_back(sf::Color::Magenta);

	MoveBy(delta_loc);
}

Snake::Segment::Segment(const Location & in_loc)
	:
	shape(sf::Vector2f(Board::dim, Board::dim))
{
	loc = in_loc;
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(loc.x * Board::dim, loc.y * Board::dim);
}

Snake::Segment::Segment(sf::Color c_in)
{
	shape.setFillColor(c_in);
}

void Snake::Segment::draw(sf::RenderTarget &target) const
{
	target.draw(shape);
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	shape.move(delta_loc.x * Board::dim, delta_loc.y * Board::dim);
}

const Location & Snake::Segment::GetLocation() const
{
	return loc;
}

sf::FloatRect Snake::Segment::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}

void Snake::draw(sf::RenderTarget &target) const
{
	for (auto it = segments.rbegin(); it != segments.rend(); ++it)
	{
		it->draw(target);
	}
}

void Snake::MoveBy(const Location & delta_loc)
{
	/*for (size_t i = segments.size() - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}*/
	segments.front().MoveBy(delta_loc);
}

bool Snake::inTile(const Location & lTarget) const
{
	for (const auto &s : segments)
	{
		if (s.GetLocation() == lTarget)
		{
			return true;
		}
	}
	return false;
}

bool Snake::inTileExceptEnd(const Location & lTarget) const
{
	for (size_t i = 0; i < segments.size() - 1; i++)
	{
		if (segments[i].GetLocation() == lTarget)
		{
			return true;
		}
	}
	return false;
}

size_t Snake::GetLenght()
{
	return segments.size();
}

sf::FloatRect Snake::getGlobalBounds() const
{
	return segments.front().getGlobalBounds();
}

