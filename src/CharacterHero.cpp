#include "CharacterHero.h"

#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>


CharacterHero::CharacterHero(const string name, const int ptsAttack, const int ptsLife, const int ptsExperience, const int level,
    const int ptsSpecialAttack, const int shield, const double criticalHit, const double dodge, const int x, const int y, const string picture, const int regeneration, const Race race)
:Character(name,ptsAttack,ptsLife,ptsExperience,level,ptsSpecialAttack,shield,criticalHit,dodge, x, y, picture, regeneration),race(race)
{
    categoryHero();
//    if (!persoHeros_texture.loadFromFile("Images/Avatars/Heros.png"))
//    {
//        std::cout << "Problème" << std::endl;
//    }
//
//    persoHeros_sprite.setTexture(persoHeros_texture);
//    persoHeros_sprite.setPosition(50, 50);
//    persoHeros_sprite.setOrigin(1000, 1000);
}

CharacterHero::CharacterHero(const string name, const Race race)
:Character(name),race(race)
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
        setPtsLife(150);
        setPtsAttack(10);
        setPtsSpecialAttack(15);
        setShield(10);

        setCriticalHit(25.00);
        setDodge(50.00);
        setRegeneration(10);
        setPicture("Images/Avatars/0_Heros.png");

        break;

    case VALDERA:
        setPtsLife(150);
        setPtsAttack(10);
        setPtsSpecialAttack(15);
        setShield(10);

        setCriticalHit(25.00);
        setDodge(50.00);
        setRegeneration(10);
        setPicture("Images/Avatars/1_Heros.png");

        break;
    case VANDUUL:
        setPtsLife(150);
        setPtsAttack(10);
        setPtsSpecialAttack(15);
        setShield(10);

        setCriticalHit(25.00);
        setDodge(50.00);
        setRegeneration(10);
        setPicture("Images/Avatars/2_Heros.png");

        break;
    case COVENANTE:
        setPtsLife(150);
        setPtsAttack(10);
        setPtsSpecialAttack(15);
        setShield(10);

        setCriticalHit(25.00);
        setDodge(50.00);
        setRegeneration(10);
        setPicture("Images/Avatars/3_Heros.png");

        break;

    case AETWI:
        setPtsLife(150);
        setPtsAttack(10);
        setPtsSpecialAttack(15);
        setShield(10);

        setCriticalHit(25.00);
        setDodge(50.00);
        setRegeneration(10);
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
