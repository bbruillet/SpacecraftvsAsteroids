#ifndef CHARACTERHERO_H
#define CHARACTERHERO_H

#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "IConstante.h"
#include "IStrategyIncrease.h"
#include "IncreaseAttack.h"
#include "IncreaseLife.h"
#include "IncreaseShield.h"
#include "IncreaseRegeneration.h"
#include "Character.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

/*
    In this enumeration(?), you can se that there is all races's types. We'll associate some stats to a race !
*/
enum Race
{
    HUMAN,
    VALDERA,
    VANDUUL,
    COVENANTE,
    AETWI
};

/*
    This class inherited Character's class
    This class was created for a hero
*/
class CharacterHero : public Character
{

    private:
        /*The enumeration is called here*/
        Race race;
        //int regeneration;
        /*This is a counter for hero's regeneration*/
        int counterRegen;

        /*This is where our design pattern 'strategy' is used*/
        IStrategyIncrease* strategy;

    public:
        /*
            The 4 next lines are :
                - constructor (the class for dp strategy is called here)
                - destructor
                - copy contructor
                - operator=

            The constructor is defined by default and Origin is added in.
        */
        CharacterHero(const string name = "Player", const int ptsAttack = 0, const int ptsLife = 0, const int badge = 0,
                   const int ptsSpecialAttack = 0, const int shield = 0 ,const double criticalHit = 0.0, const double dodge = 0.0, const int x = 0, const int y = 0,
                   const string picture = "Directory", const int regeneration = 0, const Race=Race::HUMAN,IStrategyIncrease* strat = new IncreaseAttack);
        virtual ~CharacterHero();
        CharacterHero(const CharacterHero&);
        CharacterHero& operator=(const CharacterHero&);

        /*
            This is the getter and setter of our race
        */
        Race getRace()const;
        void setRace(const Race &);

        /*
            This is where the enumeration is used
        */
        void categoryHero();

        /*
            This is str() function of a boss
        */
        string str() const;

        /*
            This is a function used by the dp. This is where the instruction is executed
        */
        void executeIncrease();

        /*
            This is the setter of dp's class
        */
        void setIncrease(IStrategyIncrease* strategy);

};

#endif // CHARACTERHERO_H
