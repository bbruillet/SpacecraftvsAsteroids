#include "BiomePlanete.h"

BiomePlanete::BiomePlanete(const string background):background(background)
{
    if (!biome_texture.loadFromFile(background))
    {
        std::cout << "Problème de planète" << std::endl;
    }

    biome_sprite.setTexture(biome_texture);
    biome_sprite.setPosition(0, 0);
}

BiomePlanete::~BiomePlanete()
{
    //dtor
}

BiomePlanete::BiomePlanete(const BiomePlanete& b)
{
    background = b.background;
}

BiomePlanete& BiomePlanete::operator=(const BiomePlanete& rhs)
{
    if (this != &rhs) {
        background = rhs.background;
    } // handle self assignment
    //assignment operator
    return *this;
}
