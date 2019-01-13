#include "pch.h"
#include "ButtonHandler.hpp"

void ButtonHandler::setSpacing(int spacing)
{
	m_spacing = spacing;
}

int ButtonHandler::getSpacing() const
{
	return m_spacing;
}

void ButtonHandler::setNextPosition(int x, int y)
{
	m_xCurr = x;
	m_yCurr = y;
}

std::pair<int, int> ButtonHandler::getNextPosition() const
{
	return std::make_pair(m_xCurr, m_yCurr);
}

void ButtonHandler::setDefaultSize(int width, int height)
{
	m_defaultWidth = width;
	m_defaultHeight = height;
}

std::pair<int, int> ButtonHandler::getDefaultSize() const
{
	return std::make_pair(m_defaultWidth, m_defaultHeight);
}

Button &ButtonHandler::addButton(const std::string &text, const std::function<void()> &func)
{
	auto &button = m_buttons.emplace_back(m_font);
	if (m_buttons.size() == 1)
		button.select();

	button.setSize(m_defaultWidth, m_defaultHeight);
	button.setPosition(m_xCurr, m_yCurr);
	button.setText(text);
	button.setActionHandler(func);

	auto[buttonX, buttonY] = button.getPosition();
	auto[buttonWidth, buttonHeight] = button.getSize();

	m_yCurr = buttonY + buttonHeight + m_spacing;

	return button;
}

bool ButtonHandler::toogleInputMode()
{
	if (!m_mouseControl)
	{
		m_lastMousePos = sf::Mouse::getPosition();
		m_mouseControl = false;
	}

	auto currMousePos = sf::Mouse::getPosition();
	if (m_lastMousePos != currMousePos)
	{
		m_lastMousePos = currMousePos;
		m_mouseControl = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		m_mouseControl = false;
	}

	return *m_mouseControl;
}

void ButtonHandler::handleInput(sf::Window &window)
{
	toogleInputMode() ? handleMouseEvents(window) : handleKeyEvents(window);
}

void ButtonHandler::draw(sf::RenderTarget &target) const
{
	for (auto &button : m_buttons)
		button.draw(target);
}

void ButtonHandler::handleKeyEvents(sf::Window &window)
{
	if (m_buttons.empty())
		return;

	if (m_index >= m_buttons.size())
	{
		m_index = 0;
		m_buttons[m_index].select();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_buttons[m_index].deselect();
		m_index = (m_buttons.size() + (m_index - 1)) % m_buttons.size();
		m_buttons[m_index].select();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_buttons[m_index].deselect();
		m_index = (m_index + 1) % m_buttons.size();
		m_buttons[m_index].select();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		m_buttons[m_index].invoke();
	}
}

void ButtonHandler::handleMouseEvents(sf::Window &window)
{
	auto pos = sf::Mouse::getPosition(window);
	bool anySelected = false;

	for (int index = m_buttons.size() - 1; index >= 0; --index)
	{
		auto &button = m_buttons[index];

		if (button.contains(pos.x, pos.y))
		{
			m_index = index;
			anySelected = true;
			button.select();
		}
		else
		{
			button.deselect();
		}
	}

	if (!anySelected)
		m_index = -1;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (m_index < m_buttons.size())
			m_buttons[m_index].invoke();
	}
}
