#include "IncreaseShield.h"

/*
    This is the constructor
*/
IncreaseShield::IncreaseShield()
{
    //ctor
}

/*
    This is the destructor
*/
IncreaseShield::~IncreaseShield()
{
    //dtor
}

/*
    This the copy constructor
*/
IncreaseShield::IncreaseShield(const IncreaseShield& other)
{
    //copy ctor
}

/*
    This is operator='s function
*/
IncreaseShield& IncreaseShield::operator=(const IncreaseShield& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/*
    This is where the method (from interface --> dp) is redefined
    Here the shield will be increased by 10
*/
void IncreaseShield::increase(Character& ch)
{
    ch.setShield(ch.getShield() + 10);
}
