#include "IncreaseStatsMenu.h"

#include <iostream>

using std::cout;
using std::endl;

IncreaseStatsMenu::IncreaseStatsMenu()
{
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}

	if (!stats_menu_texture.loadFromFile("Images/Backgrounds/Menu_Background.jpg"))
    {
        std::cout << "Problem for loading background" << std::endl;
    }

    stats_menu_sprite.setTexture(stats_menu_texture);
    stats_menu_sprite.setPosition(0, 0);
    stats_menu_sprite.scale(1.0f, 1.0f);

	statsMenu[0].setFillColor(sf::Color(201, 135, 185));
	statsMenu[0].setString("> Augmenter Points de vie");

	statsMenu[1].setFillColor(sf::Color::White);
	statsMenu[1].setString("> Augmenter points d'attaque");

	statsMenu[2].setFillColor(sf::Color::White);
	statsMenu[2].setString("> Augmenter l'attaque spéciale");

	statsMenu[3].setFillColor(sf::Color::White);
	statsMenu[3].setString("> Augmenter le bouclier");

	statsMenu[4].setFillColor(sf::Color::White);
	statsMenu[4].setString("> Augmenter pourcentage de coups critique");

	statsMenu[5].setFillColor(sf::Color::White);
	statsMenu[5].setString("> Augmenter pourcentage d'esquive");

	statsMenu[6].setFillColor(sf::Color::White);
	statsMenu[6].setString("> Augmenter les points de regeneration");

	for (int i = 0; i < MAX_NUMBER_OF_INCREASED_STATS; i++)
	{
		statsMenu[i].setCharacterSize(100);
		statsMenu[i].setFont(font);
		statsMenu[i].setPosition(sf::Vector2f(100,i*100));
	}

	selectedItemIndex = 0;
}

IncreaseStatsMenu::~IncreaseStatsMenu()
{
    //dtor
}

int IncreaseStatsMenu::getPressedItem()
{
    return selectedItemIndex;
}

void IncreaseStatsMenu::draw(sf::RenderWindow &window)
{
    window.draw(stats_menu_sprite);
	for (int i = 0; i < MAX_NUMBER_OF_INCREASED_STATS; i++)
	{
		window.draw(statsMenu[i]);
	}
}

void IncreaseStatsMenu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		statsMenu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		statsMenu[selectedItemIndex].setFillColor(sf::Color(201, 135, 185));
	}
}

void IncreaseStatsMenu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_INCREASED_STATS)
	{
		statsMenu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		statsMenu[selectedItemIndex].setFillColor(sf::Color(201, 135, 185));
	}
}
