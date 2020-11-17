#include "Planete.h"

#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>

Planete::Planete(string nom, string image, int x, int y)
{
    this->nom = nom;
    this->image = image;
    this->x=x;
    this->y=y;
    if (!planete_texture.loadFromFile(image))
    {
        std::cout << "Problème de planète" << std::endl;
    }

    planete_sprite.setTexture(planete_texture);
    planete_sprite.setPosition(x, y);
    //planete_sprite.setOrigin(500, 500);
}

Planete::Planete()
{

}

Planete::~Planete()
{
    //dtor
}

int Planete::getX() const
{
    return x;
}

void Planete::setX(int x)
{
    this->x = x;
}

int Planete::getY() const
{
    return y;
}

void Planete::setY(int y)
{
    this->y = y;
}

