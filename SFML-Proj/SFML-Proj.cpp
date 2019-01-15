#include "pch.h"
#include <Windows.h>
#include <iostream>
#include "ButtonHandler.hpp"
#include "KeyHandler.hpp"
#include "Game.h"
#include "Board.h"

sf::Color randomColour()
{
	return sf::Color(std::rand() % 256 - 1, std::rand() % 256 - 1, std::rand() % 256 - 1);
}

sf::Vector2f randomDirection(float length)
{
	auto rand = std::rand();

	if (rand % 4 == 0)
		return sf::Vector2f(0, length);

	if (rand % 4 == 1)
		return sf::Vector2f(length, 0);

	if (rand % 4 == 2)
		return sf::Vector2f(0, -length);

	return sf::Vector2f(-length, 0);
}

int main()
{
	//Console Window
	HWND hWnd = GetConsoleWindow();
#ifdef DEBUG
	ShowWindow(hWnd, SW_SHOW);
#else
	ShowWindow(hWnd, SW_HIDE);
#endif // DEBUG

	sf::RenderWindow window(sf::VideoMode(1000, 900), "SFML");
	sf::Color windowColor(sf::Color::Blue);

	sf::Font font;
	font.loadFromFile("data/fonts/Georgia.ttf");

	Game game;
	
	KeyHandler keyHandler;

	ButtonHandler buttonHandler(font);
	buttonHandler.setDefaultSize(300, 60);
	buttonHandler.setNextPosition(150, 100);
	buttonHandler.setSpacing(10);
	
	std::unique_ptr<sf::Shape> shape = std::make_unique<sf::RectangleShape>(sf::Vector2f(30, 30));
	shape->setPosition(200, 300);

	bool mouseMovable = false;
	bool mouseColor = false;
	bool movable = false;
	bool autoColor = false;
	bool windowMoveColor = false;
	bool windowAutoColor = false;
	bool autoFollowMouse = false;
	bool changedText = false;

	Board brd;

		//Buttons Start
		auto &b1 = buttonHandler.addButton("Random Color", [&]
			{
				shape->setFillColor(randomColour());
			});
		b1.setSelectionColour(sf::Color(0, 255, 255, 127));
		b1.setDeselectionColour(sf::Color(0, 255, 255, 127));
		b1.setTextSelectionColour(sf::Color::Green);

		auto &b2 = buttonHandler.addButton("Random Position", [&]
			{
				shape->move(randomDirection(10));
			});
		b2.setSelectionColour(sf::Color(0, 255, 0, 127));
		b2.setDeselectionColour(sf::Color(0, 255, 0, 127));
		b2.setTextSelectionColour(sf::Color::Red);

		auto &b3 = buttonHandler.addButton("Random Pos/Color", [&]
			{
				shape->setFillColor(randomColour());
				shape->move(randomDirection(10));
			});
		b3.setSelectionColour(sf::Color(255, 0, 0, 127));
		b3.setDeselectionColour(sf::Color(255, 0, 0, 127));
		b3.setTextSelectionColour(sf::Color::Black);

		auto &b4 = buttonHandler.addButton("Move to Center", [&]
			{
				shape->setPosition(500, 400);
			});
		b4.setSelectionColour(sf::Color(255, 255, 0, 127));
		b4.setDeselectionColour(sf::Color(255, 255, 0, 127));
		b4.setTextSelectionColour(sf::Color::Magenta);

		auto &b5 = buttonHandler.addButton("Mousemove", [&]
			{
				mouseMovable = !mouseMovable;
				movable = false;
			});
		b5.setSelectionColour(sf::Color(255, 0, 255, 127));
		b5.setDeselectionColour(sf::Color(255, 0, 255, 127));
		b5.setTextSelectionColour(sf::Color::Cyan);

		auto &b6 = buttonHandler.addButton("MouseColor", [&]
			{
				mouseColor = !mouseColor;
				autoColor = false;
			});
		b6.setSelectionColour(sf::Color(127, 255, 127, 127));
		b6.setDeselectionColour(sf::Color(127, 255, 127, 127));
		b6.setTextSelectionColour(sf::Color::Cyan);

		auto &b7 = buttonHandler.addButton("Automove", [&]
			{
				movable = !movable;
				mouseMovable = false;
			});
		b7.setSelectionColour(sf::Color(127, 127, 255, 127));
		b7.setDeselectionColour(sf::Color(127, 127, 255, 127));
		b7.setTextSelectionColour(sf::Color::Cyan);

		auto &b8 = buttonHandler.addButton("AutoColor", [&]
			{
				autoColor = !autoColor;
				mouseColor = false;
			});
		b8.setSelectionColour(sf::Color(255, 127, 127, 127));
		b8.setDeselectionColour(sf::Color(255, 127, 127, 127));
		b8.setTextSelectionColour(sf::Color::Cyan);

		auto &b9 = buttonHandler.addButton("WindowMoveColor", [&]
			{
				windowMoveColor = !windowMoveColor;
				windowAutoColor = false;
			});
		b9.setSelectionColour(sf::Color(255, 127, 127, 127));
		b9.setDeselectionColour(sf::Color(255, 127, 127, 127));
		b9.setTextSelectionColour(sf::Color::Cyan);

		auto &b10 = buttonHandler.addButton("WindowAutoColor", [&]
			{
				windowAutoColor = !windowAutoColor;
				windowMoveColor = false;
			});
		b10.setSelectionColour(sf::Color(255, 127, 127, 127));
		b10.setDeselectionColour(sf::Color(255, 127, 127, 127));
		b10.setTextSelectionColour(sf::Color::Cyan);

		buttonHandler.setNextPosition(460, 100);

		auto &b11 = buttonHandler.addButton("Follow Mouse", [&]
			{
				auto pos = sf::Mouse::getPosition(window);
				shape->setPosition(pos.x - 15, pos.y - 15);
				autoFollowMouse = false;
			});
		b11.setSelectionColour(sf::Color(0, 255, 255, 127));
		b11.setDeselectionColour(sf::Color(0, 255, 255, 127));
		b11.setTextSelectionColour(sf::Color::Green);

		auto &b12 = buttonHandler.addButton("AutoFollowMouse", [&]
			{
				autoFollowMouse = !autoFollowMouse;
			});
		b12.setSelectionColour(sf::Color(0, 255, 255, 127));
		b12.setDeselectionColour(sf::Color(0, 255, 255, 127));
		b12.setTextSelectionColour(sf::Color::Green);

		auto &b13 = buttonHandler.addButton("Change Shape", [&]
			{
				auto pos = shape->getPosition();
				auto color = shape->getFillColor();

				if (dynamic_cast<sf::RectangleShape*>(shape.get()))
					shape = std::make_unique<sf::CircleShape>(15);
				else
					shape = std::make_unique<sf::RectangleShape>(sf::Vector2f(30, 30));

				shape->setPosition(pos);
				shape->setFillColor(color);
			});
		b13.setSelectionColour(sf::Color(0, 255, 255, 127));
		b13.setDeselectionColour(sf::Color(0, 255, 255, 127));
		b13.setTextSelectionColour(sf::Color::Green);

		auto &b14 = buttonHandler.addButton("Change B13 Text", [&]
			{
				if (!changedText)
					b13.setText("hehe");
				else
					b13.setText("Change Shape");
				changedText = !changedText;
			});
		b14.setSelectionColour(sf::Color(0, 255, 255, 127));
		b14.setDeselectionColour(sf::Color(0, 255, 255, 127));
		b14.setTextSelectionColour(sf::Color::Green);

		auto &b15 = buttonHandler.addButton("To Snake-Game", [&]
			{
				window.create(sf::VideoMode(990, 900), "SFML Snake");
			});
		b15.setSelectionColour(sf::Color(0, 255, 255, 127));
		b15.setDeselectionColour(sf::Color(0, 255, 255, 127));
		b15.setTextSelectionColour(sf::Color::Green);

		//Buttons End

	keyHandler.addKey(sf::Keyboard::W, [&] 
		{
			shape->move(0, -10);
		});
	keyHandler.addKey(sf::Keyboard::A, [&]
		{
			shape->move(-10, 0);
		});
	keyHandler.addKey(sf::Keyboard::S, [&]
		{
			shape->move(0, 10);
		});
	keyHandler.addKey(sf::Keyboard::D, [&]
		{
			shape->move(10, 0);
		});
	keyHandler.addKey(sf::Keyboard::R, [&]
		{
			b1.invoke();
		});
	keyHandler.addKey(sf::Keyboard::F, [&]
		{
			b11.invoke();
		});
	keyHandler.addKey(sf::Keyboard::X, [&]
		{
			auto pos = sf::Mouse::getPosition(window);
			b13.setPosition(pos.x - 150, pos.y - 30);
		});

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			keyHandler.handleKeyInput();
			buttonHandler.handleInput(window);

			if (mouseMovable)
				shape->move(randomDirection(10));

			if(mouseColor)
				shape->setFillColor(randomColour());

			if (windowMoveColor)
				windowColor = randomColour();

			if (autoFollowMouse)
			{
				auto pos = sf::Mouse::getPosition(window);
				shape->setPosition(pos.x - 15, pos.y - 15);
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (movable)
			shape->move(randomDirection(10));

		if (autoColor)
			shape->setFillColor(randomColour());

		if (windowAutoColor)
			windowColor = randomColour();

		window.clear(windowColor);
		window.draw(*shape);
		game.Go(window);
		buttonHandler.draw(window);
		window.display();
	}

	return 0;
}
