#include "Vaisseau.h"
#include "IConstante.h"

#include <cstdio>
#include <iostream>


Vaisseau::Vaisseau(const int x, const int y)
:x(x), y(y)
{
 //ctor

}

Vaisseau::~Vaisseau()
{
    //dtor
}

Vaisseau& Vaisseau::operator=(const Vaisseau& v)
{
    if (this != &v) {
        x = v.x;
        y = v.y;
    } // handle self assignment
    //assignment operator
    return *this;
}


int Vaisseau::getX() const
{
    return x;
}

void Vaisseau::setX(const int &x)
{
    this->x = x;
}

int Vaisseau::getY() const
{
    return y;
}

void Vaisseau::setY(const int &y)
{
    this->y = y;
}
