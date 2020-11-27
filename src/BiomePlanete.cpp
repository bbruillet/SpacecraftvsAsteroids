#include "BiomePlanete.h"

//constructeur
BiomePlanete::BiomePlanete(const string background):background(background)
{
    //ctor
}

BiomePlanete::~BiomePlanete()
{
    //dtor
}

//constructeur de copie
BiomePlanete::BiomePlanete(const BiomePlanete& b)
{
    //cpy
    background = b.background;
}

//operateur d'affectation
BiomePlanete& BiomePlanete::operator=(const BiomePlanete& rhs)
{
    if (this != &rhs) {
        background = rhs.background;
    } // handle self assignment
    //assignment operator
    return *this;
}

//Permet de changer la valeur du background et recharge la nouvelle image
void BiomePlanete::setBackground(const string& background)
{
    this->background = background;

}

//dessine un sprite dans une window
void BiomePlanete::draw(sf::RenderWindow& window)
{
     if (!biome_texture.loadFromFile(background))
    {
        std::cout << "Problème de planète" << std::endl;
    }
    biome_sprite.setTexture(biome_texture);
    biome_sprite.setPosition(0, 0);

    window.draw(biome_sprite);
}


