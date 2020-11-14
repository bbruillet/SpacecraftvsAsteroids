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
}

Personnage::Personnage()
{
    if (!perso_texture.loadFromFile("images/X-Wing.png"))
    {
        std::cout << "ok" << std::endl;
    }

    //Coordonnées de départ du personnage
    x = 7150;
    y = 3500;
    perso_sprite.setTexture(perso_texture);
    perso_sprite.setPosition(x, y);
    perso_sprite.setOrigin(62.5, 62.5);
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
            if(x>1000) {
                x = x - 50;
                perso_sprite.setRotation(270);
//                cout << x << endl;
            }
            else {
                perso_sprite.setRotation(90);
            }
            break;
        }

        case sf::Keyboard::Right:
        {
            if(x<12000) {
                x = x + 50;
                perso_sprite.setRotation(90);
//                cout << x << endl;
            }
            else {
                perso_sprite.setRotation(270);
            }
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
            if(y>1000){
            y = y - 50;
            perso_sprite.setRotation(0);
            cout << y << endl;
            }
            else {
                perso_sprite.setRotation(180);
            }
            break;
        }

        case sf::Keyboard::Down:
        {
            if(y<6500){
            y = y + 50;
            perso_sprite.setRotation(180);
            cout << y << endl;
            }
            else {
                perso_sprite.setRotation(0);
            }
            break;
        }
        default:
        break;
    }
    return y;
}
