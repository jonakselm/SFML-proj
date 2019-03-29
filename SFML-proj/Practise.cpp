#include "stdafx.h"
#include "Practise.hpp"
#include "StateHandler.hpp"


Practise::Practise()
	:
	worm(100, 100)
{
}


Practise::~Practise()
{
}

void Practise::init(sf::Window & window, StateHandler & stateHandler)
{
	auto kEsc = keyHandler.addKey(sf::Keyboard::Escape, [&]
		{
			stateHandler.Pop();
		});

}

void Practise::updateModel(sf::Window & window, StateHandler & stateHandler)
{
	keyHandler.handleKeyInput();
	buttonHandler.handleInput(window);

	float dt = ft.Mark();

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		theta -= dt * angularSpeed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		theta += dt * angularSpeed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		worm.grow();

	double length = worm.speed() * dt;
	worm.move(theta, length);
}

void Practise::draw(sf::RenderTarget & target)
{
	worm.draw(target);
	buttonHandler.draw(target);
}
