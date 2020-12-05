#include "PauseMenu.h"

#include <iostream>

using std::cout;
using std::endl;

/*
    This is the constructor
*/
PauseMenu::PauseMenu()
{
    /*The font will be loaded here*/
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}

	/*This is where the background will be loaded*/
	if (!pause_menu_texture.loadFromFile("Images/Backgrounds/Menu_Background.jpg"))
    {
        std::cout << "Problem while loading background" << std::endl;
    }

    pause_menu_sprite.setTexture(pause_menu_texture);
    pause_menu_sprite.setPosition(0, 0);
    pause_menu_sprite.scale(1.0f, 1.0f);


	pauseMenu[0].setFillColor(sf::Color(201, 135, 185));
	pauseMenu[0].setString("> Resume");
	pauseMenu[0].setPosition(sf::Vector2f(100,100));


	pauseMenu[1].setFillColor(sf::Color::White);
	pauseMenu[1].setString("> Show map");
	pauseMenu[1].setPosition(sf::Vector2f(100,250));


	pauseMenu[2].setFillColor(sf::Color::White);
	pauseMenu[2].setString("> Show my statistics");
	pauseMenu[2].setPosition(sf::Vector2f(100,400));

	pauseMenu[3].setFillColor(sf::Color::White);
	pauseMenu[3].setString("> Show tutorial");
	pauseMenu[3].setPosition(sf::Vector2f(100,550));

	pauseMenu[4].setFillColor(sf::Color::White);
	pauseMenu[4].setString("> Quit game");
	pauseMenu[4].setPosition(sf::Vector2f(100,700));

	for (int i = 0; i < MAX_NUMBER_OF_TEXTS; i++)
	{
		pauseMenu[i].setCharacterSize(100);
        pauseMenu[i].setFont(font);
	}

	selectedItemIndex = 0;
}

/*This is the destructor*/
PauseMenu::~PauseMenu()
{

}

/*This is where the pressed element will be recovered*/
int PauseMenu::getPressedItem()
{
    return selectedItemIndex;
}

/*This is where the sprite and text will be drawed*/
void PauseMenu::draw(sf::RenderWindow &window)
{
    window.draw(pause_menu_sprite);
	for (int i = 0; i < MAX_NUMBER_OF_TEXTS; i++)
	{
		window.draw(pauseMenu[i]);
	}
}

/*
    This is where the user will be allowed to move up in the menu
    The color of the text will be changed according to the choice
*/
void PauseMenu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		pauseMenu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		pauseMenu[selectedItemIndex].setFillColor(sf::Color(201, 135, 185));
	}
}

/*
    This is where the user will be allowed to move down in the menu
    The color of the text will be changed according to the choice
*/
void PauseMenu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_TEXTS)
	{
		pauseMenu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		pauseMenu[selectedItemIndex].setFillColor(sf::Color(201, 135, 185));
	}
}

/*
    This function is used to navigate in the menu with (key up and key down). Management class is used in !
*/
void PauseMenu::show(Management& man,sf::RenderWindow& window)
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
                        /*The function playerAccount will be showed by pressing the text*/
                        man.launch(window);
                        break;

                    /*Second text*/
                    case 1:
                        /*The function creditGame will be showed by pressing the text*/
                        man.mapSpace(window);
                        break;

                    /*Third text*/
                    case 2:
                        /*The function showStats will be showed by pressing the text*/
                        man.showStats(window);
                       break;

                    /*Fourth text*/
                    case 3:
                        man.tuto(window);
                        break;
                    case 4:
                        window.close();
                        break;
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

