#include "Compte.h"

Compte::Compte()
{
    //ctor
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}

	races[0].setFont(font);
	races[0].setFillColor(sf::Color(201, 135, 185));
	races[0].setString("> Humain");
	races[0].setPosition(sf::Vector2f(100,100));

	races[1].setFont(font);
	races[1].setFillColor(sf::Color::White);
	races[1].setString("> Valdera");
	races[1].setPosition(sf::Vector2f(100,250));

	races[2].setFont(font);
	races[2].setFillColor(sf::Color::White);
	races[2].setString("> Vanduul");
	races[2].setPosition(sf::Vector2f(100,400));

	races[3].setFont(font);
	races[3].setFillColor(sf::Color::White);
	races[3].setString("> Covenante");
	races[3].setPosition(sf::Vector2f(100,550));

	races[4].setFont(font);
	races[4].setFillColor(sf::Color::White);
	races[4].setString("> Aetwi");
	races[4].setPosition(sf::Vector2f(100,700));

	for (int i = 0; i < MAX_NUMBER_OF_RACES; i++)
	{
		races[i].setCharacterSize(150);
	}

	selectedItemIndex = 0;

	if (!compte_texture.loadFromFile("Images/Backgrounds/0_Race.png"))
    {
            std::cout << "Problème" << std::endl;
    }

        compte_sprite.setTexture(compte_texture);
        compte_sprite.setPosition(0, 0);
        compte_sprite.scale(1.0f, 1.0f);
}

Compte::~Compte()
{
    //dtor
}

int Compte::GetPressedItem()
{
    return selectedItemIndex;
}

void Compte::draw(sf::RenderWindow &window)
{
    window.draw(compte_sprite);
	for (int i = 0; i < MAX_NUMBER_OF_RACES; i++)
	{
		window.draw(races[i]);
	}
}

void Compte::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		races[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		races[selectedItemIndex].setFillColor(sf::Color(201, 135, 185));
		if (!compte_texture.loadFromFile("Images/Backgrounds/"+to_string(selectedItemIndex)+"_Race.png"))
        {
            std::cout << "Problème" << std::endl;
        }

        compte_sprite.setTexture(compte_texture);
        compte_sprite.setPosition(0, 0);
        compte_sprite.scale(1.0f, 1.0f);

	}
}

void Compte::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_RACES)
	{
		races[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		races[selectedItemIndex].setFillColor(sf::Color(201, 135, 185));
		if (!compte_texture.loadFromFile("Images/Backgrounds/"+to_string(selectedItemIndex)+"_Race.png"))
        {
            std::cout << "Problème" << std::endl;
        }

        compte_sprite.setTexture(compte_texture);
        compte_sprite.setPosition(0, 0);
        compte_sprite.scale(1.0f, 1.0f);
	}
}

Compte::Compte(const Compte& other)
{
    //copy ctor
}

Compte& Compte::operator=(const Compte& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
