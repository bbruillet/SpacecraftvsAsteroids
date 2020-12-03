#include "IStrategyIncrease.h"

/*
    This is the constructor
*/
IStrategyIncrease::IStrategyIncrease()
{

}

/*
    This is the destructor
*/
IStrategyIncrease::~IStrategyIncrease()
{
    //dtor
}

/*
    This the copy constructor
*/
IStrategyIncrease::IStrategyIncrease(const IStrategyIncrease& other)
{
    //copy ctor
}

/*
    This is operator='s function
*/
IStrategyIncrease& IStrategyIncrease::operator=(const IStrategyIncrease& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

