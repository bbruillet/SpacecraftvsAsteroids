#include "IncreaseAttack.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;

IncreaseAttack::IncreaseAttack()
{
    //ctor
}

IncreaseAttack::~IncreaseAttack()
{
    //dtor
}

IncreaseAttack::IncreaseAttack(const IncreaseAttack& other)
{
    //copy ctor
}

IncreaseAttack& IncreaseAttack::operator=(const IncreaseAttack& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void IncreaseAttack::increase(Character& ch)
{
   ch.setPtsAttack(ch.getPtsAttack() + 5);
   ch.setPtsSpecialAttack(ch.getPtsSpecialAttack() + 5);
}
