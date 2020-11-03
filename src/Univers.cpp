#include "Univers.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

Univers::Univers()
{
    if (!univers_texture.loadFromFile("Universe.png"))
    {
        std::cout << "ok universe" << std::endl;
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
