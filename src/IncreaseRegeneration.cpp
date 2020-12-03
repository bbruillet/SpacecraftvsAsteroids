#include "IncreaseRegeneration.h"

/*
    This is the constructor
*/
IncreaseRegeneration::IncreaseRegeneration()
{
    //ctor
}

/*
    This is the destructor
*/
IncreaseRegeneration::~IncreaseRegeneration()
{
    //dtor
}

/*
    This the copy constructor
*/
IncreaseRegeneration::IncreaseRegeneration(const IncreaseRegeneration& other)
{
    //copy ctor
}

/*
    This is operator='s function
*/
IncreaseRegeneration& IncreaseRegeneration::operator=(const IncreaseRegeneration& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/*
    This is where the method (from interface --> dp) is redefined
    Here the regeneration will be increased by 10
*/
void IncreaseRegeneration::increase(Character& ch)
{
    ch.setRegeneration(ch.getRegeneration() + 10);
}
