#include "Personnage.h"

#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>

Personnage::Personnage(string nom, string race, int ptsAttaque, int ptsVie, int ptsExperience, int niveau)
{
    this->nom = nom;
    this->race = race;
    this->ptsAttaque = ptsAttaque;
    this->ptsVie = ptsVie;
    this->ptsExperience = ptsExperience;
    this->niveau = niveau;
    //ctor
}

Personnage::Personnage()
{
    if (!perso_texture.loadFromFile("X-Wing.png"))
    {
        std::cout << "ok" << std::endl;
    }


    x = 3750;
    y = 2026;
    perso_sprite.setTexture(perso_texture);
    perso_sprite.setPosition(x, y);
    perso_sprite.setOrigin(32.5, 32.5);
}

Personnage::~Personnage()
{
    //dtor
}

Personnage::Personnage(const Personnage& other):nom(other.nom),race(other.race), ptsAttaque(other.ptsAttaque), ptsVie(other.ptsVie), ptsExperience(other.ptsExperience), niveau(other.niveau)
{
    //copy ctor
}

Personnage& Personnage::operator=(const Personnage& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string Personnage::str() const
{
    string result = nom + " " + race + " " + to_string(ptsAttaque) + " " +
    to_string(ptsVie) + " " + to_string(ptsExperience) + " " + to_string(niveau);
    return result;
}

int Personnage::getX() const
{
    return x;
}

void Personnage::setX(int x)
{
    this->x = x;
}

int Personnage::getY() const
{
    return y;
}

void Personnage::setY(int y)
{
    this->y = y;
}

int Personnage::seDeplacerX(Event event, int x)
{
    switch (event.key.code)
    {
        case sf::Keyboard::Left:
        {
            x = x - 25;
            perso_sprite.setRotation(270);
            break;
        }

        case sf::Keyboard::Right:
        {
            x = x + 25;
            perso_sprite.setRotation(90);
            break;
        }
        default:
        break;
    }
    return x;
}

int Personnage::seDeplacerY(Event event, int y)
{
    switch (event.key.code)
    {
        case sf::Keyboard::Up:
        {
            y = y - 25;
            perso_sprite.setRotation(0);
            break;
        }

        case sf::Keyboard::Down:
        {
            y = y + 25;
            perso_sprite.setRotation(180);
            break;
        }
        default:
        break;
    }
    return y;
}
