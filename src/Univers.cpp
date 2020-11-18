#include "Univers.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

Univers::Univers()
{
    //Sf::Image image;
    //image.loadFromMemory("Images/Backgrounds/Universe.png")
    if (!univers_texture.loadFromFile("Images/Backgrounds/Universe2.png"))
    {
        std::cout << "Problème" << std::endl;
    }

    int x = 0;
    int y = 0;
    univers_sprite.setTexture(univers_texture);
    univers_sprite.setOrigin(1000,1000);
    univers_sprite.setPosition(x, y);
    univers_sprite.scale(3.0f, 3.0f);
   // univers_sprite.setTextureRect(sf::IntRect(13000, 13000, 13000, 13000));//ctor
}

Univers::~Univers()
{
    //dtor
}

int Univers::getX() const
{
    return x;
}

void Univers::setX(int x)
{
    this->x = x;
}

int Univers::getY() const
{
    return y;
}

void Univers::setY(int y)
{
    this->y = y;
}

void Univers::add(Planete pla)
{
      this->planetes.push_back(pla);
}

void Univers::addInacc(Planete pla)
{
    this->planetesInaccessibles.push_back(pla);
}
