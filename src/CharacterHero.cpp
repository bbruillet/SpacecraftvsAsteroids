#include "CharacterHero.h"

#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>


CharacterHero::CharacterHero(const string name, const int ptsAttack, const int ptsLife, const int ptsExperience, const int level,
    const int ptsSpecialAttack, const int shield, const double criticalHit, const double dodge,
    const int x, const int y, const string picture, const int regeneration, const Race race ,IStrategyIncrease* strat)
:Character(name,ptsAttack,ptsLife,ptsExperience,level,ptsSpecialAttack,shield,criticalHit,dodge, x, y, picture, regeneration),race(race), strategy(strat)
{

    categoryHero();
}

CharacterHero::~CharacterHero()
{
    //dtor
}

CharacterHero::CharacterHero(const CharacterHero& cH):Character(cH),race(cH.race)
{

}

CharacterHero& CharacterHero::operator=(const CharacterHero& cH)
{
    if (this != &cH)
        {
            Character::operator=(cH);
            race = cH.race;
            categoryHero();
        } // handle self assignment
    //assignment operator
    return *this;
}

void CharacterHero::categoryHero() {
    switch(race) {
    case HUMAN:
        setPtsLife(300);
        setPtsAttack(100);
        setPtsSpecialAttack(75);
        setShield(10);

        setCriticalHit(35.00);
        setDodge(0.00);
        setRegeneration(15);
        setPicture("Images/Avatars/0_Heros.png");

        break;

    case VALDERA:
        setPtsLife(200);
        setPtsAttack(1000);
        setPtsSpecialAttack(200);
        setShield(50);

        setCriticalHit(200.00);
        setDodge(10.00);
        setRegeneration(20);
        setPicture("Images/Avatars/1_Heros.png");

        break;
    case VANDUUL:
        setPtsLife(300);
        setPtsAttack(300);
        setPtsSpecialAttack(300);
        setShield(300);

        setCriticalHit(300.00);
        setDodge(300.00);
        setRegeneration(10);
        setPicture("Images/Avatars/2_Heros.png");

        break;
    case COVENANTE:
        setPtsLife(300);
        setPtsAttack(30);
        setPtsSpecialAttack(50);
        setShield(30);

        setCriticalHit(35.00);
        setDodge(20.00);
        setRegeneration(80);
        setPicture("Images/Avatars/3_Heros.png");

        break;

    case AETWI:
        setPtsLife(260);
        setPtsAttack(700);
        setPtsSpecialAttack(66);
        setShield(15);

        setCriticalHit(23.00);
        setDodge(35.00);
        setRegeneration(50);
        setPicture("Images/Avatars/4_Heros.png");

        break;
    default:
        break;
    }
}

string CharacterHero::str() const
{
    std::stringstream ss;
    ss << Character::str() << "\n\t"
        << to_string(race);
        return ss.str();
}

void CharacterHero::setRace(const Race& race)
{
    this->race = race;
    categoryHero();
}

void CharacterHero::executeIncrease()
{
    strategy->increase(*this);
}

void CharacterHero::setIncrease(IStrategyIncrease* strategy)
{
    this->strategy = strategy;
}
