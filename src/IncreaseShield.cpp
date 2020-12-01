#include "IncreaseShield.h"

IncreaseShield::IncreaseShield()
{
    //ctor
}

IncreaseShield::~IncreaseShield()
{
    //dtor
}

IncreaseShield::IncreaseShield(const IncreaseShield& other)
{
    //copy ctor
}

IncreaseShield& IncreaseShield::operator=(const IncreaseShield& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void IncreaseShield::increase(Character& ch)
{
    ch.setShield(ch.getShield() + 10);
}
