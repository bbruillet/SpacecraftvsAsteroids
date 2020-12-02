#include "BiomePlanet.h"

/*
    This is the constructor
*/
BiomePlanet::BiomePlanet(const string background):background(background)
{

}

/*
    This is the destructor
*/
BiomePlanet::~BiomePlanet()
{

}

/*
    This is the copy constructor
*/
BiomePlanet::BiomePlanet(const BiomePlanet& b)
{

    background = b.background;
}

/*
    This is operator='s function
*/
BiomePlanet& BiomePlanet::operator=(const BiomePlanet& rhs)
{
    if (this != &rhs) {
        background = rhs.background;
    }

    return *this;
}

/*
    This function allow you to change the value of a background
*/
void BiomePlanet::setBackground(const string& background)
{
    this->background = background;

}

/*
    This function will load a texture and put it in a sprite.
    After that it'll draw this sprite in the window
*/
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


