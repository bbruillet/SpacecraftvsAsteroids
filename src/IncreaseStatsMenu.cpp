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

	if (!stats_menu_texture.loadFromFile("Images/Backgrounds/Laboratory.png"))
    {
        std::cout << "Problem for loading background" << std::endl;
    }



    stats_menu_sprite.setTexture(stats_menu_texture);
    stats_menu_sprite.setPosition(0, 0);
    stats_menu_sprite.scale(1.0f, 1.0f);

	statsMenu[0].setFillColor(sf::Color::Yellow);
	statsMenu[0].setString("> Increase life (+10)");

	statsMenu[1].setFillColor(sf::Color::White);
	statsMenu[1].setString("> Increase attack (Attack +5 | Special attack +5)");

	statsMenu[2].setFillColor(sf::Color::White);
	statsMenu[2].setString("> Increase shield (+10)");

	statsMenu[3].setFillColor(sf::Color::White);
	statsMenu[3].setString("> Increase regeneration capacity (+10)");

	for (int i = 0; i < MAX_NUMBER_OF_INCREASED_STATS-1; i++)
	{
		statsMenu[i].setCharacterSize(55);
		statsMenu[i].setFont(font);
		statsMenu[i].setPosition(sf::Vector2f(50,(i+1)*200));
		statsMenu[i].setStyle(sf::Text::Bold);
	}

	statsMenu[4].setFillColor(sf::Color(243,76,7));
	statsMenu[4].setString("! Increase your stats !");
	statsMenu[4].setCharacterSize(75);
    statsMenu[4].setFont(font);
    statsMenu[4].setStyle(sf::Text::Bold);
	statsMenu[4].setPosition(sf::Vector2f(400,40));

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
		statsMenu[selectedItemIndex].setFillColor(sf::Color::Yellow);
	}
}

void IncreaseStatsMenu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_INCREASED_STATS-1)
	{
		statsMenu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		statsMenu[selectedItemIndex].setFillColor(sf::Color::Yellow);
	}
}
