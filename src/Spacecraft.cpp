#include "Spacecraft.h"
#include "IConstante.h"

#include <cstdio>
#include <iostream>


Spacecraft::Spacecraft(const int x, const int y)
:x(x), y(y)
{
 //ctor

}

Spacecraft::~Spacecraft()
{
    //dtor
}

Spacecraft& Spacecraft::operator=(const Spacecraft& sc)
{
    if (this != &sc) {
        x = sc.x;
        y = sc.y;
    } // handle self assignment
    //assignment operator
    return *this;
}


int Spacecraft::getX() const
{
    return x;
}

void Spacecraft::setX(const int &x)
{
    this->x = x;
}

int Spacecraft::getY() const
{
    return y;
}

void Spacecraft::setY(const int &y)
{
    this->y = y;
}
