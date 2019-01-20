#pragma once
#include "StateHandler.hpp"

class App
{
public:
	App();
	~App();

	void run();

private:
	void init();
	bool frame();

	sf::RenderWindow m_window;
	sf::Color m_windowColor;

	StateHandler m_stateHandler;
};

