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
        setPtsLife(100);
        setPtsAttack(100);
        setPtsSpecialAttack(100);
        setShield(100);

        setCriticalHit(100.00);
        setDodge(5.00);
        setRegeneration(100);
        setPicture("Images/Avatars/0_Heros.png");

        break;

    case VALDERA:
        setPtsLife(200);
        setPtsAttack(200);
        setPtsSpecialAttack(200);
        setShield(200);

        setCriticalHit(200.00);
        setDodge(200.00);
        setRegeneration(200);
        setPicture("Images/Avatars/1_Heros.png");

        break;
    case VANDUUL:
        setPtsLife(300);
        setPtsAttack(300);
        setPtsSpecialAttack(300);
        setShield(300);

        setCriticalHit(300.00);
        setDodge(300.00);
        setRegeneration(300);
        setPicture("Images/Avatars/2_Heros.png");

        break;
    case COVENANTE:
        setPtsLife(400);
        setPtsAttack(400);
        setPtsSpecialAttack(400);
        setShield(400);

        setCriticalHit(400.00);
        setDodge(400.00);
        setRegeneration(400);
        setPicture("Images/Avatars/3_Heros.png");

        break;

    case AETWI:
        setPtsLife(500);
        setPtsAttack(500);
        setPtsSpecialAttack(500);
        setShield(500);

        setCriticalHit(500.00);
        setDodge(500.00);
        setRegeneration(500);
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
