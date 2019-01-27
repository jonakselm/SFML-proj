#include "pch.h"
#include "BrickBreaker.h"
#include "StateHandler.hpp"


BrickBreaker::BrickBreaker()
{
}


BrickBreaker::~BrickBreaker()
{
}

void BrickBreaker::init(sf::Window & window, StateHandler & stateHandler)
{
	auto &kEsc = keyHandler.addKey(sf::Keyboard::Escape, [&]
		{
			stateHandler.Pop();
		});
}

void BrickBreaker::updateModel(sf::Window & window, StateHandler & stateHandler)
{
	keyHandler.handleKeyInput();
}

void BrickBreaker::draw(sf::RenderTarget & target)
{
}
