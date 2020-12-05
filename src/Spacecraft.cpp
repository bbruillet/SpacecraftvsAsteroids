#include "Spacecraft.h"
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

/*This is the getter of x coordinate*/
int Spacecraft::getX() const
{
    return x;
}

/*This is the setter of x coordinate*/
void Spacecraft::setX(const int &x)
{
    this->x = x;
}

/*This is the getter of y coordinate*/
int Spacecraft::getY() const
{
    return y;
}

/*This is the setter of y coordinate*/
void Spacecraft::setY(const int &y)
{
    this->y = y;
}
