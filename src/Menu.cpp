#include "Menu.h"

#include <iostream>

using std::cout;
using std::endl;

/*
    This is the constructor
*/
Menu::Menu()
{
    /*The font will be loaded here*/
	if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}

	/*This is where the background will be loaded*/
	if (!menu_texture.loadFromFile("Images/Backgrounds/Menu_Background.jpg"))
    {
        std::cout << "Problem while loading background" << std::endl;
    }

    menu_sprite.setTexture(menu_texture);
    menu_sprite.setPosition(0, 0);
    menu_sprite.scale(1.0f, 1.0f);

    /*
        These lines are used to store a color and some string in some text.
        It will be displayed in the window with 'draw()' function
    */
	menu[0].setFillColor(sf::Color(201, 135, 185));
	menu[0].setString("> Play");
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("> Credits");
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("> Quit game");

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		menu[i].setCharacterSize(150);
		menu[i].setPosition(sf::Vector2f(100,(i+1)*175));
		menu[i].setFont(font);
	}

	selectedItemIndex = 0;
}

/*This is the destructor*/
Menu::~Menu()
{

}

/*This is where the pressed element will be recovered*/
int Menu::getPressedItem()
{
    return selectedItemIndex;
}

/*This is where the sprite and text will be drawed*/
void Menu::draw(sf::RenderWindow &window)
{
    window.draw(menu_sprite);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

/*
    This is where the user will be allowed to move up in the menu
    The color of the text will be changed according to the choice
*/
void Menu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color(201, 135, 185));
	}
}

/*
    This is where the user will be allowed to move down in the menu
    The color of the text will be changed according to the choice
*/
void Menu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color(201, 135, 185));
	}
}

/*
    This function is used to navigate in the menu with (key up and key down). Management class is used in !
*/
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
                /*If up is pressed*/
                case sf::Keyboard::Up:
                    moveUp();
                    break;
                /*id down is pressed*/
                case sf::Keyboard::Down:
                    moveDown();
                    break;
                /*If return is pressed*/
                case sf::Keyboard::Return:
                    switch(getPressedItem())
                    {
                    /*First text*/
                    case 0:
                        /*The function playerAccount will be showed by pressinf the text*/
                        man.playerAccount();
                        break;

                    /*Second text*/
                    case 1:
                        /*The function creditGame will be showed by pressinf the text*/
                        man.creditGame();
                        break;

                    /*Third text*/
                    case 2:
                        /*The window will be closed*/
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
                    break;
                    default:
                break;
			}
		}

		window.clear();
		draw(window);
		window.display();
	}

}

