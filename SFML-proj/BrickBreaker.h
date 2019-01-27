#pragma once

#include "State.hpp"
#include "ButtonHandler.hpp"
#include "KeyHandler.hpp"

class BrickBreaker : public State
{
public:
	BrickBreaker();
	virtual ~BrickBreaker();

	void init(sf::Window &window, StateHandler &stateHandler);
	void updateModel(sf::Window &window, StateHandler &stateHandler) override;
	void draw(sf::RenderTarget &target) override;

private:
	ButtonHandler buttonHandler;
	KeyHandler keyHandler;
};

