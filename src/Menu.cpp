#include "Menu.h"

#include <SFML/Graphics.hpp>

#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>


Menu::Menu()
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Cyan);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(100,100));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Map");
	menu[1].setPosition(sf::Vector2f(200,100));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(300,100));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Cyan);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Cyan);
	}
}
