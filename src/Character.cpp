#include "Character.h"

#include <cstdio>
#include <iostream>

/*
    This is the constructor of a character
*/
Character::Character(const string name, const int ptsAttack, const int ptsLife, const int badge,
    const int ptsSpecialAttack, const int shield, const double criticalHit, const double dodge, const int x, const int y, const string picture, const int regeneration)
:ptsAttack(ptsAttack), badge(badge), ptsSpecialAttack(ptsSpecialAttack), shield(shield),
criticalHit(criticalHit), dodge(dodge), x(x), y(y), picture(picture), regeneration(regeneration)
{
    this->name = name;
    this->picture = picture;

    setPtsLife(ptsLife);
    counterSpe = 0;
}

/*
    This is the destructor of a character
*/
Character::~Character()
{
    //dtor
}

/*
    This is the copy constructor of a character
*/
Character::Character(const Character& other):name(other.name), ptsAttack(other.ptsAttack), ptsLife(other.ptsLife), badge(other.badge),
ptsSpecialAttack(other.ptsSpecialAttack), shield(other.shield), criticalHit(other.criticalHit), dodge(other.dodge), x(other.x), y(other.y),
regeneration(other.regeneration)
{
    setPicture(other.picture);
    //copy ctor
}

/*
    This is operator='s of a character
*/
Character& Character::operator=(const Character& c)
{
    if (this != &c)
    {
        name = c.name;
        ptsAttack = c.ptsAttack;
        ptsLife = c.ptsLife;
        badge = c.badge;
        ptsSpecialAttack = c.ptsSpecialAttack;
        shield = c.shield;
        criticalHit = c.criticalHit;
        dodge = c.dodge;
        x = c.x;
        y = c.y;
        picture = c.picture;
        regeneration = c.regeneration;
    }// handle self assignment
    //assignment operator
    return *this;
}

/*
    This is str()'s function of a character
*/
string Character::str() const
{
    std::stringstream ss;
    ss << "Nom : " << getName() << "\n\t" <<
        "Points d'attaque : " << to_string(ptsAttack) << "\n\t" <<
        "Points de vie : " << to_string(ptsLife) << "\n\t" <<
        "Nombre de badges : " << to_string(badge) << "\n\t" <<
        "Points d'attaque spéciale : " << to_string(ptsSpecialAttack) << "\n\t" <<
        "Bouclier : " << to_string(shield) << "\n\t" <<
        "Coups critique : " << to_string(criticalHit) << "\n\t"
        "Esquive : " << to_string(dodge) << "\n\t" <<
        "Points de régénération : " << to_string(regeneration) << "\n\t" <<
        "Coordonnées [" << to_string(x) << "," << to_string(y)<<"]" << "\n\t" <<
        "Image : " << getPicture();
        return ss.str();
}

/*
    This is the clone's function
*/
Character* Character::clone()const
{
    return new Character(*this);
}

/*
    Setters and getters of character are implemented here
*/
void Character::setName(const string &name)
{
    this->name = name;
}

string Character::getName() const
{
    return name;
}

void Character::setPtsAttack(const int &ptsAttack)
{
    this->ptsAttack = ptsAttack;
}

int Character::getPtsAttack() const
{
    return ptsAttack;
}
/*
    This setter need a ternary operator, that said that we cant set our life at 0 !!!
*/
void Character::setPtsLife(const int &ptsLife)
{
    this->ptsLife = (ptsLife < 0) ? 0 : ptsLife;
}

int Character::getPtsLife() const
{
    return ptsLife;
}

void Character::setBadge(const int &badge)
{
    if(badge <= 12);
    this->badge = badge;
}

int Character::getBadge() const
{
    return badge;
}

void Character::setPtsSpecialAttack(const int &ptsSpecialAttack)
{
    this->ptsSpecialAttack = ptsSpecialAttack;
}

int Character::getPtsSpecialAttack() const
{
    return ptsSpecialAttack;
}

void Character::setShield(const int &shield)
{
    this->shield = shield;
}

int Character::getShield() const
{
    return shield;
}

void Character::setCriticalHit(const double &criticalHit)
{
    this->criticalHit = criticalHit;
}

double Character::getCriticalHit() const
{
    return criticalHit;
}

void Character::setDodge(const double &dodge)
{
    this->dodge = dodge;
}

double Character::getDodge() const
{
    return dodge;
}

void Character::setCounterSpe(const int &counterSpe)
{
    this->counterSpe = counterSpe;
}

int Character::getCounterSpe() const
{
    return counterSpe;
}

void Character::setY(const int &y)
{
    this->y = y;
}

int Character::getY() const
{
    return y;
}

void Character::setX(const int &x)
{
    this->x = x;
}

int Character::getX() const
{
    return x;
}

void Character::setPicture(const string &picture)
{
    this->picture = picture;
}

string Character::getPicture() const
{
    return picture;
}

void Character::setRegeneration(const int &regeneration)
{
    this->regeneration = regeneration;
}

int Character::getRegeneration() const
{
    return regeneration;
}
