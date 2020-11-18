#include "Vaisseau.h"
#include "IConstante.h"

#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>

Vaisseau::Vaisseau(const int x, const int y)
:x(x), y(y)
{
    if (!vaisseau_texture.loadFromFile("Images/Avatars/X-Wing.png"))
    {
        std::cout << "ok" << std::endl;
    }

    //Coordonnées de départ du personnage
//    x = 7150;
//    y = 3500;
    vaisseau_sprite.setTexture(vaisseau_texture);
    vaisseau_sprite.setPosition(x, y);
    vaisseau_sprite.setOrigin(VAISSEAU_COORDONNEE_ORIGINE, VAISSEAU_COORDONNEE_ORIGINE);
}

Vaisseau::~Vaisseau()
{
    //dtor
}

void Vaisseau::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(vaisseau_sprite);
}

int Vaisseau::seDeplacerX(Event event, int x)
{

    switch (event.key.code)
    {
        case sf::Keyboard::Left:
        {
            if(x>1000)
            {
                x = x - 50;
                vaisseau_sprite.setRotation(270);
                cout << "X: "<< x << endl;
            }
            else
            {
                vaisseau_sprite.setRotation(90);
            }
            break;
        }

        case sf::Keyboard::Right:
        {
            if(x<12000)
            {
                x = x + 50;
                vaisseau_sprite.setRotation(90);
                cout << "X: "<< x << endl;
            }
            else
            {
                vaisseau_sprite.setRotation(270);
            }
            break;
        }
        default:
        break;
    }
    return x;
}

int Vaisseau::seDeplacerY(Event event, int y)
{
    switch (event.key.code)
    {
        case sf::Keyboard::Up:
        {
            if(y>1000)
            {
                y = y - 50;
                vaisseau_sprite.setRotation(0);
                cout << "Y: "<< y << endl;
            }
            else
            {
                vaisseau_sprite.setRotation(180);
            }
            break;
        }

        case sf::Keyboard::Down:
        {
            if(y<6500)
            {
                y = y + 50;
                vaisseau_sprite.setRotation(180);
                cout << "Y: "<< y << endl;
            }
            else
            {
                vaisseau_sprite.setRotation(0);
            }
            break;
        }
        default:
        break;
    }
    return y;
}

int Vaisseau::getX() const
{
    return x;
}

void Vaisseau::setX(const int &x)
{
    this->x = x;
}

int Vaisseau::getY() const
{
    return y;
}

void Vaisseau::setY(const int &y)
{
    this->y = y;
}
