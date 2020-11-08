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

/*void Planete::load()
        {
            for(int i = 0; i < 2; i++)
            {
                sf::Texture new_texture;
                new_texture.loadFromFile(this->nom_fichier[i]);
                textures.push_back(new_texture);
            }
            for(int i = 0; i < 2; i++)
            {
                sf::Sprite new_sprite;
                new_sprite.setTexture(textures[i]);
                sprites.push_back(new_sprite);
            }
        }*/

