#include "Planet.h"
#include "BiomePlanet.h"
#include "CharacterBoss.h"
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>


Planet::Planet(string name, string picture, int x, int y, const int xChar, const int yChar):name(name), picture(picture), x(x), y(y), xChar(xChar), yChar(yChar)
{
//    this->bossPlan = bossPlan;
    CharacterBoss *c1 = new CharacterBoss("Boss",BLUE);
    this->bossPlan = c1;
    //planete_sprite.setOrigin(500, 500);
}

Planet::Planet(const Planet& plan)
{
    name = plan.name;
    picture = plan.picture;
    x = plan.x;
    y = plan.y;
    xChar = plan.xChar;
    yChar = plan.yChar;
    bossPlan = plan.bossPlan;
   // cout <<"2 " +bossPlan->str()<< endl;

    if (!planet_texture.loadFromFile(picture))
    {
        std::cout << "Problem when loading planet" << std::endl;
    }

    planet_sprite.setTexture(planet_texture);
    planet_sprite.setPosition(x, y);

}

Planet::~Planet()
{
    //dtor
}

bool Planet::operator==(const Planet& plan)
{
    return (name==plan.name);
}

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

int Planet::getX() const
{
    return x;
}

void Planet::setX(int x)
{
    this->x = x;
}

int Planet::getY() const
{
    return y;
}

void Planet::setY(int y)
{
    this->y = y;
}

void Planet::setName(const string &name)
{
    this->name = name;
}

string Planet::getName() const
{
    return name;
}


CharacterBoss* Planet::getBoss()const
{
    return bossPlan;
}

void Planet::giveBoss(CharacterBoss &boss)
{
    CharacterBoss* c1 = new CharacterBoss(boss);
    this->bossPlan = c1;
}

int Planet::getXChar() const
{
    return xChar;
}

void Planet::setXChar(int xChar)
{
    this->xChar = xChar;
}

int Planet::getYChar() const
{
    return yChar;
}

void Planet::setYChar(int yChar)
{
    this->yChar = yChar;
}

Planet* Planet::clone() const
{
    return new Planet(*this);
}
