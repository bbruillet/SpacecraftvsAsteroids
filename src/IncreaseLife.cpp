#include "IncreaseLife.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;

/*
    This is the constructor
*/
IncreaseLife::IncreaseLife()
{
    //ctor
}

/*
    This is the destructor
*/
IncreaseLife::~IncreaseLife()
{
    //dtor
}

/*
    This the copy constructor
*/
IncreaseLife::IncreaseLife(const IncreaseLife& other)
{
    //copy ctor
}

/*
    This is operator='s function
*/
IncreaseLife& IncreaseLife::operator=(const IncreaseLife& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/*
    This is where the method (from interface --> dp) is redefined
    Here the life will be increased by 10
*/
void IncreaseLife::increase(Character& ch)
{
    ch.setPtsLife(ch.getPtsLife() + 10);
}
