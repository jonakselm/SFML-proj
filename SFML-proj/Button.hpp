#pragma once
#include <functional>

class Button
{
public:
	Button(const sf::Font &font);
	~Button() = default;

////////////////////////////////////////////////
	// Button
public:
	// Usage: button.setPosition(x, y);
	void setPosition(double x, double y);

	// Usage: auto[x, y] = button.getPosition();
	sf::Vector2f getPosition() const;

	// Usage: button.setSize(width, height);
	void setSize(double width, double height);
	
	// Usage: auto[width, height] = button.getSize();
	sf::Vector2f getSize() const;

	bool contains(double x, double y); 
	sf::FloatRect getGlobalBounds() const;


/////////////////////////////////////////////////
	// Text
public:
	
	void setText(const std::string &text);
	std::string getText() const;

	void setTextSize(unsigned int size);
	unsigned int getTextSize() const;

	void setFont(const sf::Font &font);
	const sf::Font &getFont() const;

private:
	void centralizeText(sf::IntRect bounds);

/////////////////////////////////////////////////
//  Selection
public:
	void setSelectionColour(sf::Color colour);
	sf::Color getSelectionColour() const;
	void setDeselectionColour(sf::Color colour);
	sf::Color getDeselectionColour() const;
		   
	void setTextSelectionColour(sf::Color colour);
	sf::Color getTextSelectionColour() const;
	void setTextDeselectionColour(sf::Color colour);
	sf::Color getTextDeselectionColour() const;
	
	// Select a button, changing to the selection colours
	void select();

	// Deselect a button, changing to the deselection colours
	void deselect();

	// Returns true if selected, false otherwise
	bool selected();

////////////////////////////////////////////////
	// General
public:

	void draw(sf::RenderTarget &target) const;

	// Usage1: button.setActionHandler(Game::someFunc);
	// Usage2: button.setActionHandler([]
	// { doWhatever(); });
	// Usage3: button.setActionHandler(std::bind(&Game::somefunc, this));
	void setActionHandler(const std::function<void()> &func);

	void invoke() const;

////////////////////////////////////////////////
	// Member variables
private:
	bool m_selected = false;
	sf::Color 
		m_colourSelect = sf::Color::Red, 
		m_colourDeselect = sf::Color::Red,
		m_textColourSelect = sf::Color::Yellow, 
		m_textColourDeselect = sf::Color::White;
	const sf::Font *m_pFont;
	sf::Text m_text;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	std::function<void()> m_func;
};

