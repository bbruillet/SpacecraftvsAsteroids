#include "BiomePlanet.h"

//constructeur
BiomePlanet::BiomePlanet(const string background):background(background)
{
    //ctor
}

BiomePlanet::~BiomePlanet()
{
    //dtor
}

//constructeur de copie
BiomePlanet::BiomePlanet(const BiomePlanet& b)
{
    //cpy
    background = b.background;
}

//operateur d'affectation
BiomePlanet& BiomePlanet::operator=(const BiomePlanet& rhs)
{
    if (this != &rhs) {
        background = rhs.background;
    } // handle self assignment
    //assignment operator
    return *this;
}

//Permet de changer la valeur du background et recharge la nouvelle image
void BiomePlanet::setBackground(const string& background)
{
    this->background = background;

}

//dessine un sprite dans une window
void BiomePlanet::drawBiome(sf::RenderWindow& window)
{
     if (!biome_texture.loadFromFile(background))
    {
        std::cout << "Problem for loading the biome" << std::endl;
    }
    biome_sprite.setTexture(biome_texture);
    biome_sprite.setPosition(0, 0);

    window.draw(biome_sprite);
}


