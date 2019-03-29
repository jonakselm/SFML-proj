#pragma once
#include "State.hpp"
#include "ButtonHandler.hpp"
#include "KeyHandler.hpp"
#include "Worm.hpp"
#include "FrameTimer.h"

class Practise : public State
{
public:
	Practise();
	virtual ~Practise();

	void init(sf::Window &window, StateHandler &stateHandler);
	void updateModel(sf::Window &window, StateHandler &stateHandler);
	void draw(sf::RenderTarget &target);
private:
	ButtonHandler buttonHandler;
	KeyHandler keyHandler;
	Worm worm;
	FrameTimer ft;

	double theta = 0;
	double angularSpeed = 8;
};
