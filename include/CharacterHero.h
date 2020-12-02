#ifndef PERSONNAGEHEROS_H
#define PERSONNAGEHEROS_H

#include "Character.h"

#include <iostream>
#include <ostream>
#include <string>

#include "IConstante.h"
#include "IStrategyIncrease.h"
#include "IncreaseAttack.h"
#include "IncreaseLife.h"
#include "IncreaseShield.h"
#include "IncreaseRegeneration.h"

#include <cstdio>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

enum Race
{
    HUMAN,
    VALDERA,
    VANDUUL,
    COVENANTE,
    AETWI
};

class CharacterHero : public Character
{

    private:
        Race race;
        int regeneration;
        int counterRegen;

        IStrategyIncrease* strategy;

    public:
        CharacterHero(const string name = "Player", const int ptsAttack = 0, const int ptsLife = 0, const int badge = 0,
                   const int ptsSpecialAttack = 0, const int shield = 0 ,const double criticalHit = 0.0, const double dodge = 0.0, const int x = 0, const int y = 0,
                   const string picture = "Directory", const int regeneration = 0, const Race=Race::HUMAN,IStrategyIncrease* strat = new IncreaseAttack);

        virtual ~CharacterHero();
        CharacterHero(const CharacterHero&);
        CharacterHero& operator=(const CharacterHero&);

        Race getRace()const;
        void setRace(const Race &);

        void categoryHero();
        string str() const;

        void executeIncrease();

        void setIncrease(IStrategyIncrease* strategy);

};

#endif // PERSONNAGEHEROS_H
