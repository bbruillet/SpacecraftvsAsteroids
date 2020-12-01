#include "IncreaseRegeneration.h"

IncreaseRegeneration::IncreaseRegeneration()
{
    //ctor
}

IncreaseRegeneration::~IncreaseRegeneration()
{
    //dtor
}

IncreaseRegeneration::IncreaseRegeneration(const IncreaseRegeneration& other)
{
    //copy ctor
}

IncreaseRegeneration& IncreaseRegeneration::operator=(const IncreaseRegeneration& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void IncreaseRegeneration::increase(Character& ch)
{
    ch.setRegeneration(ch.getRegeneration() + 10);
}
