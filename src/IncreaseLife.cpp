#include "IncreaseLife.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;

IncreaseLife::IncreaseLife()
{
    //ctor
}

IncreaseLife::~IncreaseLife()
{
    //dtor
}

IncreaseLife::IncreaseLife(const IncreaseLife& other)
{
    //copy ctor
}

IncreaseLife& IncreaseLife::operator=(const IncreaseLife& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void IncreaseLife::increase(Character& ch)
{
    ch.setPtsLife(ch.getPtsLife() + 10);
}
