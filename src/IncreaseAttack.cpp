#include "IncreaseAttack.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;

/*
    This is the constructor
*/
IncreaseAttack::IncreaseAttack()
{
    //ctor
}

/*
    This is the destructor
*/
IncreaseAttack::~IncreaseAttack()
{
    //dtor
}

/*
    This the copy constructor
*/
IncreaseAttack::IncreaseAttack(const IncreaseAttack& other)
{
    //copy ctor
}

/*
    This is operator='s function
*/
IncreaseAttack& IncreaseAttack::operator=(const IncreaseAttack& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/*
    This is where the method (from interface --> dp) is redefined
    Here the attack will be increased by 5 and special attack will be increased by 5 too
*/
void IncreaseAttack::increase(Character& ch)
{
   ch.setPtsAttack(ch.getPtsAttack() + 5);
   ch.setPtsSpecialAttack(ch.getPtsSpecialAttack() + 5);
}
