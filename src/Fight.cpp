#include "Fight.h"
#include <stdlib.h>

#include <time.h>

#include "Character.h"
//#include "CharacterHero.h"

Fight::Fight()
{
    srand((int)time(0));
    nbRegen = 2;
}

Fight::~Fight()
{
    //dtor
}

Fight::Fight(const Fight& other)
{
    //copy ctor
}

Fight& Fight::operator=(const Fight& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


//Heros attaque Boss
int Fight::attack(Character &c1,Character &c2)
{
    int attackEvent(0);
    int attack;
    if(c1.getCounterSpe() == 3)
    {
        attack = c1.getPtsSpecialAttack();
        c1.setCounterSpe(-1);
        attackEvent = 3;
    }

    else
    {
        attack = c1.getPtsAttack();
        attackEvent = 1;

            nb = (rand()% 100) +1;

            if (nb <= c1.getCriticalHit())
            {
                attack = attack + (c1.getPtsAttack()/2);
                attackEvent = 4;
            }
    }

    nbDodge = (rand()%100) + 1;
    if(nbDodge <= c2.getDodge())
    {
        attack = 0;
        attackEvent = 2;
    }

    if(c2.getShield() > 0) {
            if(c2.getShield() > attack){
                c2.setShield(c2.getShield() - attack);
            }
            else if(c2.getShield() == attack)
                {
                    c2.setShield(0);
                }
                else
                {
                    attack = attack - c2.getShield();
                    c2.setShield(0);
                    c2.setPtsLife(c2.getPtsLife()-attack);
                }
    }
    else
    {
        c2.setPtsLife(c2.getPtsLife()-attack);
    }

    c1.setCounterSpe(c1.getCounterSpe() + 1);
    return attackEvent;
}

void Fight::regenHero(Character &c1, Character &c2)
{
    if(nbRegen == 0)
    {
//        attack(c1, c2);
    }

    else
    {
        c1.setPtsLife(c1.getPtsLife() + c1.getRegeneration());
        nbRegen--;
        return;
    }


}

string Fight::eventAttack(int attackEvent)
{
    if(attackEvent == 1)
    {
        return "Attack from ";
    }

    else if(attackEvent == 2)
    {
        return " dodged a hit";
    }

    else if(attackEvent == 3)
    {
        return "Special attack from ";
    }

    else
    {
        return "Critical hit from ";
    }
}


void Fight::setNbRegen(const int &nbRegen)
{
    this->nbRegen = nbRegen;
}
