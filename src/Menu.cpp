#include "Menu.h"

#include <iostream>

using std::cout;
using std::endl;


Menu::Menu()
{
	if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}

	if (!menu_texture.loadFromFile("Images/Backgrounds/Menu_Background.jpg"))
    {
        std::cout << "Problem for loading background" << std::endl;
    }

    menu_sprite.setTexture(menu_texture);
    menu_sprite.setPosition(0, 0);
    menu_sprite.scale(1.0f, 1.0f);

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color(201, 135, 185));
	menu[0].setString("> Play");
	menu[0].setPosition(sf::Vector2f(100,100));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("> Credits");
	menu[1].setPosition(sf::Vector2f(100,250));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("> Quit game");
	menu[2].setPosition(sf::Vector2f(100,400));

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		menu[i].setCharacterSize(150);
	}

	selectedItemIndex = 0;
}

Menu::~Menu()
{

}

int Menu::getPressedItem()
{
    return selectedItemIndex;
}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(menu_sprite);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color(201, 135, 185));
	}
}

void Menu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color(201, 135, 185));
	}
}

void Menu::show(Management& man,sf::RenderWindow &window)
{
    while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    moveUp();
                    break;

                case sf::Keyboard::Down:
                    moveDown();
                    break;

                case sf::Keyboard::Return:
                    switch(getPressedItem())
                    {
                    case 0:
                        man.playerAccount(window);
                        window.close();

                        break;

                    case 1:
                        man.creditGame(window);

                        break;

                    case 2:
                        window.close();
                        default:
                        break;
                    }
                    window.clear();
                    default:
                    break;
                }
                break;
                case sf::Event::Closed:
                    window.close();

                default:
                break;

			}

		}

		window.clear();

		draw(window);
		window.display();
	}

}

