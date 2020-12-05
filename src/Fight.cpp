#include "Fight.h"

/*This is the constructor*/
Fight::Fight()
{
    srand((int)time(0));
    nbRegen = 2;
}

/*This is the destructor*/
Fight::~Fight()
{

}

/*This the copy constructor*/
Fight::Fight(const Fight& other)
{
    //copy ctor
}

/*This is operator='s function*/
Fight& Fight::operator=(const Fight& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/*
    This function is (as said before) the most important one
    This is where he boss and the hero will fight
*/
int Fight::attack(Character &c1,Character &c2)
{
    /*attackEvent is a function. It will be explained later*/
    int attackEvent(0);
    int attack;

    /*
        A character can make a specila attack if the counter is at 3.
        Else it's going to be a normal attack
    */
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

            /*Random number to know if the character can make a critical hit*/
            nb = (rand()% 100) +1;

            if (nb <= c1.getCriticalHit())
            {
                attack = attack + (c1.getPtsAttack()/2);
                attackEvent = 4;
            }
    }

    /*Random number to know if the character can dodge the hit*/
    nbDodge = (rand()%100) + 1;
    if(nbDodge <= c2.getDodge())
    {
        attack = 0;
        attackEvent = 2;
    }

    /*If the character has no more shield, the life will be decreased.*/
    if(c2.getShield() > 0)
    {
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

/*This function is used by the hero. It's where the hero will regen his life !*/
void Fight::regenHero(Character &c1)
{
    c1.setPtsLife(c1.getPtsLife() + c1.getRegeneration());
    nbRegen--;
    return;
}

/*
    This methos is important, because it's where the user will be advertised.
    Advertised by what ?? By all evenements during the fight
*/
string Fight::eventAttack(int attackEvent)
{
    if(attackEvent == 1)
    {
        return "Attack from ";
    }
    else if(attackEvent == 2)
    {
        return "Dodge from ";
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
