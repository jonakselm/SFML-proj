#pragma once
#include "Button.hpp"
#include <optional>

class ButtonHandler
{
public:
	ButtonHandler(const sf::Font &font) : m_font(font) {}
	~ButtonHandler() = default;
		
	void setSpacing(int spacing);
	int getSpacing() const;

	void setNextPosition(int x, int y);
	std::pair<int, int> getNextPosition() const;

	void setDefaultSize(int width, int height);
	std::pair<int, int> getDefaultSize() const;

	Button &addButton(const std::string &text, const std::function<void()> &func);

	void handleInput(sf::Window &window);
	void draw(sf::RenderTarget &target) const;
	
	auto getButtons() const { return m_buttons; }

private:
	bool toogleInputMode();
	void handleKeyEvents(sf::Window &window);
	void handleMouseEvents(sf::Window &window); // TODO: implement pollevent

private:
	sf::Vector2i m_lastMousePos;
	std::optional<bool> m_mouseControl;
	int m_defaultWidth = 250, m_defaultHeight = 60;
	int m_xCurr = 0, m_yCurr = 0;
	int m_spacing = 10;
	int m_index = 0;
	std::vector<Button> m_buttons;
	const sf::Font &m_font;
};

