#include "Univers.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

Univers::Univers()
{
    if (!univers_texture.loadFromFile("images/Universe.png"))
    {
        std::cout << "Problème" << std::endl;
    }

    int x = 0;
    int y = 0;
    univers_sprite.setTexture(univers_texture);
    univers_sprite.setPosition(x, y);
    //ctor
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
