#include "CharacterHero.h"

/*
    This is the constructor
    As you can see, we call categoryHero()', because a hero is initialized here with his own statistics
*/
CharacterHero::CharacterHero(const string name, const int ptsAttack, const int ptsLife, const int badge,
    const int ptsSpecialAttack, const int shield, const double criticalHit, const double dodge,
    const int x, const int y, const string picture, const int regeneration, const Race race ,IStrategyIncrease* strat)
:Character(name,ptsAttack,ptsLife,badge,ptsSpecialAttack,shield,criticalHit,dodge, x, y, picture, regeneration),race(race), strategy(strat)
{
    categoryHero();
}

/*
    This is the destructor
*/
CharacterHero::~CharacterHero()
{
    delete strategy;
}

/*
    This is the copy constructor
*/
CharacterHero::CharacterHero(const CharacterHero& cH):Character(cH),race(cH.race)
{

}


/*
    This is operator='s function
*/
CharacterHero& CharacterHero::operator=(const CharacterHero& cH)
{
    if (this != &cH)
        {
            Character::operator=(cH);
            race = cH.race;
        } // handle self assignment
    //assignment operator
    return *this;
}

/*
    This the most important function of a hero (with a dp).
    It's where all statistics of a hero are initialized.
    A race has his own statitics.
*/
void CharacterHero::categoryHero() {
    switch(race) {
    case HUMAN:
        setPtsLife(175);
        setPtsAttack(20);
        setPtsSpecialAttack(35);
        setShield(25);

        setCriticalHit(50.00);
        setDodge(30.00);
        setRegeneration(20);
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
        setPtsLife(1000);
        setPtsAttack(10000);
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
        setPtsLife(150);
        setPtsAttack(400);
        setPtsSpecialAttack(500);
        setShield(10);

        setCriticalHit(20.00);
        setDodge(10.00);
        setRegeneration(10);
        setPicture("Images/Avatars/4_Heros.png");

        break;
    default:
        break;
    }
}

/*
    This is the str() of a boss
*/
string CharacterHero::str() const
{
    std::stringstream ss;
    ss << Character::str() << "\n\t"
        << to_string(race);
        return ss.str();
}

/*
    This is the setter of the race
*/
void CharacterHero::setRace(const Race& race)
{
    this->race = race;
    categoryHero();
}

/*
    This is the getter of the race
*/
Race CharacterHero::getRace()const
{
    return race;
}

/*
    This is the method used to execute dp's functions
*/
void CharacterHero::executeIncrease()
{
    strategy->increase(*this);
}

/*
    This is where we're setting increase function from dp
*/
void CharacterHero::setIncrease(IStrategyIncrease* strategy)
{
    this->strategy = strategy;
}
