#include "Planete.h"

#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>

Planete::Planete(string nom, string image, int x, int y)
{
    this->nom = nom;
    this->image = image;
    if (!planete_texture.loadFromFile(image))
    {
        std::cout << "ok" << std::endl;
    }

    planete_sprite.setTexture(planete_texture);
    planete_sprite.setPosition(x, y);
}

Planete::Planete()
{

}

Planete::~Planete()
{
    //dtor
}
