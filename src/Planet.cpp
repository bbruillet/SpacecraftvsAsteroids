#include "Planet.h"
#include "BiomePlanet.h"
#include "CharacterBoss.h"
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>

/*
    This is the constructor.
*/
Planet::Planet(string name, string picture, int x, int y, const int xChar, const int yChar):name(name), picture(picture), x(x), y(y), xChar(xChar), yChar(yChar)
{
    /*A boss is initialized here and associated to a planet boss*/
    CharacterBoss *c1 = new CharacterBoss("Oblumandias",BLUE);
    this->bossPlan = c1;
}

/*
    This is the copy constructor
    it is also here that a planet is loaded
*/
Planet::Planet(const Planet& plan)
{
    name = plan.name;
    picture = plan.picture;
    x = plan.x;
    y = plan.y;
    xChar = plan.xChar;
    yChar = plan.yChar;
    bossPlan = plan.bossPlan;

    if (!planet_texture.loadFromFile(picture))
    {
        std::cout << "Problem while loading planet" << std::endl;
    }
    planet_sprite.setTexture(planet_texture);
    planet_sprite.setPosition(x, y);

}

/*
    This is the destructor
*/
Planet::~Planet()
{
    delete(bossPlan);
}

/*
    This is operator=='s function
*/
bool Planet::operator==(const Planet& plan)
{
    return (name==plan.name);
}

/*
    This is operator='s function
*/
Planet& Planet::operator=(const Planet& plan)
{
    if (this != &plan)
    {
        name = plan.name;
        picture = plan.picture;
        x = plan.x;
        y = plan.y;
        bossPlan = plan.bossPlan;
        xChar = plan.xChar;
        yChar = plan.yChar;

    }
    return *this;
}

/*These are the getter and setter of x*/
int Planet::getX() const
{
    return x;
}

void Planet::setX(int x)
{
    this->x = x;
}

/*These are the getter and setter of y*/
int Planet::getY() const
{
    return y;
}

void Planet::setY(int y)
{
    this->y = y;
}

/*These are the getter and setter of the name*/
void Planet::setName(const string &name)
{
    this->name = name;
}

string Planet::getName() const
{
    return name;
}

/*This is the getter of the boss*/
CharacterBoss* Planet::getBoss()const
{
    return bossPlan;
}

/*This is where a bos is setted*/
void Planet::giveBoss(CharacterBoss &boss)
{
    CharacterBoss* c1 = new CharacterBoss(boss);
    this->bossPlan = c1;
}

/*These are the getter and setter of Xchar*/
int Planet::getXChar() const
{
    return xChar;
}

void Planet::setXChar(int xChar)
{
    this->xChar = xChar;
}

/*These are the getter and setter of Ychar*/
int Planet::getYChar() const
{
    return yChar;
}

void Planet::setYChar(int yChar)
{
    this->yChar = yChar;
}

/*This is where a planet is cloned*/
Planet* Planet::clone() const
{
    return new Planet(*this);
}
