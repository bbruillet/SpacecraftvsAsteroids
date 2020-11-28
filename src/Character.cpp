#include "Character.h"

#include <cstdio>
#include <iostream>


Character::Character(const string name, const int ptsAttack, const int ptsLife, const int ptsExperience, const int level,
    const int ptsSpecialAttack, const int shield, const double criticalHit, const double dodge, const int x, const int y, const string picture, const int regeneration)
:ptsAttack(ptsAttack), ptsExperience(ptsExperience), level(level), ptsSpecialAttack(ptsSpecialAttack), shield(shield),
criticalHit(criticalHit), dodge(dodge), x(x), y(y), picture(picture), regeneration(regeneration)
{
    this->name = name;
    this->picture = picture;

    setPtsLife(ptsLife);
    counterSpe = 0;
}

Character::~Character()
{
    //dtor
}

Character::Character(const Character& other):name(other.name), ptsAttack(other.ptsAttack), ptsLife(other.ptsLife), ptsExperience(other.ptsExperience), level(other.level),
ptsSpecialAttack(other.ptsSpecialAttack), shield(other.shield), criticalHit(other.criticalHit), dodge(other.dodge), x(other.x), y(other.y),
regeneration(other.regeneration)
{
    setPicture(other.picture);
    //copy ctor
}

Character& Character::operator=(const Character& c)
{
    if (this != &c)
    {
        name = c.name;
        ptsAttack = c.ptsAttack;
        ptsLife = c.ptsLife;
        ptsExperience = c.ptsExperience;
        level = c.level;
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

string Character::str() const
{
    std::stringstream ss;
    ss << "Nom : " << getName() << "\n\t" <<
        "Points d'attaque : " << to_string(ptsAttack) << "\n\t" <<
        "Points de vie : " << to_string(ptsLife) << "\n\t" <<
        "Points d'expérience : " << to_string(ptsExperience) << "\n\t" <<
        "Niveau : " << to_string(level) << "\n\t" <<
        "Points d'attaque spéciale : " << to_string(ptsSpecialAttack) << "\n\t" <<
        "Bouclier : " << to_string(shield) << "\n\t" <<
        "Coups critique : " << to_string(criticalHit) << "\n\t"
        "Esquive : " << to_string(dodge) << "\n\t" <<
        "Points de régénération : " << to_string(regeneration) << "\n\t" <<
        "Coordonnées [" << to_string(x) << "," << to_string(y)<<"]" << "\n\t" <<
        "Image : " << getPicture();
        return ss.str();
}

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

void Character::setPtsLife(const int &ptsLife)
{
    this->ptsLife = (ptsLife < 0) ? 0 : ptsLife;
}

int Character::getPtsLife() const
{
    return ptsLife;
}

void Character::setPtsExperience(const int &ptsExperience)
{
    this->ptsExperience = ptsExperience;
}

int Character::getPtsExperience() const
{
    return ptsExperience;
}

void Character::setLevel(const int &level)
{
    this->level = level;
}

int Character::getLevel() const
{
    return level;
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

Character* Character::clone()const
{
    return new Character(*this);
}
