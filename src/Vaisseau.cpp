#include "Vaisseau.h"

#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>

Vaisseau::Vaisseau()
{
    if (!vaisseau_texture.loadFromFile("images/X-Wing.png"))
    {
        std::cout << "ok" << std::endl;
    }

    //Coordonnées de départ du personnage
    x = 7150;
    y = 3500;
    vaisseau_sprite.setTexture(vaisseau_texture);
    vaisseau_sprite.setPosition(x, y);
    vaisseau_sprite.setOrigin(62.5, 62.5);
}

Vaisseau::~Vaisseau()
{
    //dtor
}

int Vaisseau::seDeplacerX(Event event, int x)
{

    switch (event.key.code)
    {
        case sf::Keyboard::Left:
        {
            if(x>1000) {
                x = x - 50;
                vaisseau_sprite.setRotation(270);
                cout << "X: "<< x << endl;
            }
            else {
                vaisseau_sprite.setRotation(90);
            }
            break;
        }

        case sf::Keyboard::Right:
        {
            if(x<12000) {
                x = x + 50;
                vaisseau_sprite.setRotation(90);
                cout << "X: "<< x << endl;
            }
            else {
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
            if(y>1000){
            y = y - 50;
            vaisseau_sprite.setRotation(0);
            cout << "Y: "<< y << endl;
            }
            else {
                vaisseau_sprite.setRotation(180);
            }
            break;
        }

        case sf::Keyboard::Down:
        {
            if(y<6500){
            y = y + 50;
            vaisseau_sprite.setRotation(180);
            cout << "Y: "<< y << endl;
            }
            else {
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

void Vaisseau::setX(int x)
{
    this->x = x;
}

int Vaisseau::getY() const
{
    return y;
}

void Vaisseau::setY(int y)
{
    this->y = y;
}
