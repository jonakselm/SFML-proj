#include "pch.h"
#include <Windows.h>
#include <iostream>

int main()
{
	//Console Window
	HWND hWnd = GetConsoleWindow();
#ifdef DEBUG
	ShowWindow(hWnd, SW_SHOW);
#else
	ShowWindow(hWnd, SW_HIDE);
#endif // DEBUG

	sf::RenderWindow window(sf::VideoMode(1000, 900), "SFML works!");

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}