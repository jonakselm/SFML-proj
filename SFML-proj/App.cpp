#include "pch.h"
#include "App.hpp"
#include "MainMenu.hpp"

App::App()
{
}


App::~App()
{
}

void App::init()
{
	m_window.create(sf::VideoMode(990, 900), "SFML game");
	m_stateHandler.Push<MainMenu>();
}

void App::run()
{
	init();
	while (frame());
}

bool App::frame()
{
	if (m_stateHandler.InTransition())
		m_stateHandler.PerformTransition(m_window, m_stateHandler);

	auto state = m_stateHandler.GetState();
	if (!state)
		return false;

	if (!state->pollEvent(m_window))
		return false;

	state->updateModel(m_window, m_stateHandler);

	// Draw
	m_window.clear(m_windowColor);
	state->draw(m_window);
	m_window.display();

	return true;
}
