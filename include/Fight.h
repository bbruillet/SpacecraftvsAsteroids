#ifndef FIGHT_H
#define FIGHT_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Character.h"
#include <cstdio>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class Character;

/*
    This class is really important.
    This is where the boss ant the hero'll fight against each other.
*/
class Fight
{
    private:
        /*
            This is members data used as counters and random numbers for the fight
        */
        /*Random number*/
        int nb;
        /*Random number to dodge*/
        int nbDodge;
        /*Counter of regeneration*/
        int nbRegen;


    public:
        /*
            The 4 next lines are :
                - constructor
                - destructor
                - copy contructor
                - operator=
        */
        Fight();
        virtual ~Fight();
        Fight(const Fight& other);
        Fight& operator=(const Fight& other);

        /*
            This function is the most important one here.
            In fact, a boss and a hero need to fight against each other.
            This is why 2 characters are placed as arguments
        */
        int attack(Character& c1, Character& c2);

        /*
            This function is mainly used by the hero.
            This where he can regen his life ! After regeneration, the boss will fight against him
        */
        void regenHero(Character& c2, Character& c1);

        /*
            This is a function used to prevent the user that what is happening during the fight
        */
        string eventAttack(int attackEvent);

        /*
            This is where nbRegen's counter is setted
        */
        void setNbRegen(const int &);
};

#endif // COMBAT_H
