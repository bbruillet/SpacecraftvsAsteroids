#include "PauseMenu.h"

#include <iostream>

using std::cout;
using std::endl;

PauseMenu::PauseMenu()
{
 if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}

	if (!pause_menu_texture.loadFromFile("Images/Backgrounds/Menu_Background.jpg"))
    {
        std::cout << "Problem for loading background" << std::endl;
    }

    pause_menu_sprite.setTexture(pause_menu_texture);
    pause_menu_sprite.setPosition(0, 0);
    pause_menu_sprite.scale(1.0f, 1.0f);

	pauseMenu[0].setFont(font);
	pauseMenu[0].setFillColor(sf::Color(201, 135, 185));
	pauseMenu[0].setString("> Reprendre");
	pauseMenu[0].setPosition(sf::Vector2f(100,100));

	pauseMenu[1].setFont(font);
	pauseMenu[1].setFillColor(sf::Color::White);
	pauseMenu[1].setString("> Voir la map");
	pauseMenu[1].setPosition(sf::Vector2f(100,250));

	pauseMenu[2].setFont(font);
	pauseMenu[2].setFillColor(sf::Color::White);
	pauseMenu[2].setString("> Voir ses stats");
	pauseMenu[2].setPosition(sf::Vector2f(100,400));

	pauseMenu[3].setFont(font);
	pauseMenu[3].setFillColor(sf::Color::White);
	pauseMenu[3].setString("> Quitter");
	pauseMenu[3].setPosition(sf::Vector2f(100,550));

	for (int i = 0; i < MAX_NUMBER_OF_TEXTS; i++)
	{
		pauseMenu[i].setCharacterSize(150);
	}

	selectedItemIndex = 0;
}

PauseMenu::~PauseMenu()
{

}

int PauseMenu::getPressedItem()
{
    return selectedItemIndex;
}

void PauseMenu::draw(sf::RenderWindow &window)
{
    window.draw(pause_menu_sprite);
	for (int i = 0; i < MAX_NUMBER_OF_TEXTS; i++)
	{
		window.draw(pauseMenu[i]);
	}
}

void PauseMenu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		pauseMenu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		pauseMenu[selectedItemIndex].setFillColor(sf::Color(201, 135, 185));
	}
}

void PauseMenu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_TEXTS)
	{
		pauseMenu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		pauseMenu[selectedItemIndex].setFillColor(sf::Color(201, 135, 185));
	}
}

