#include "Spacecraft.h"
#include "IConstante.h"

#include <cstdio>
#include <iostream>

/*
    This is the constructor
*/
Spacecraft::Spacecraft(const int x, const int y)
:x(x), y(y)
{
 //ctor

}

/*
    This is the destructor
*/
Spacecraft::~Spacecraft()
{
    //dtor
}

/*
    This is operator='s function
*/
Spacecraft& Spacecraft::operator=(const Spacecraft& sc)
{
    if (this != &sc) {
        x = sc.x;
        y = sc.y;
    } // handle self assignment
    //assignment operator
    return *this;
}

/*These are getters and setters of coordinates*/
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
