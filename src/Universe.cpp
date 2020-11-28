#include "Universe.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

Universe::Universe()
{
    //Sf::Image image;
    //image.loadFromMemory("Images/Backgrounds/Universe.png")
    if (!universe_texture.loadFromFile("Images/Backgrounds/Universe.png"))
    {
        std::cout << "Problem while loading universe's background" << std::endl;
    }

    int x = 0;
    int y = 0;
    universe_sprite.setTexture(universe_texture);
    universe_sprite.setOrigin(1000,1000);
    universe_sprite.setPosition(x, y);
    universe_sprite.scale(3.0f, 3.0f);
}

Universe::Universe(const Universe& univ)
{
    for(size_t i(0);i<univ.planets.size();i++)
    {
        planets.push_back(univ.planets[i]->clone()); //AIP
    }

    for(size_t i(0);i<univ.unreachablePlanets.size();i++)
    {
        unreachablePlanets.push_back(univ.unreachablePlanets[i]); //AIP
    }
    //copy ctor
}

Universe::~Universe()
{
    //dtor
     for(size_t i(0);i<planets.size();i++)
    {
        delete planets[i]; //AIP
    }
    planets.clear();
    for(size_t i(0);i<unreachablePlanets.size();i++)
    {
        delete unreachablePlanets[i]; //AIP
    }
    unreachablePlanets.clear();
}

int Universe::getX() const
{
    return x;
}

void Universe::setX(int x)
{
    this->x = x;
}

int Universe::getY() const
{
    return y;
}

void Universe::setY(int y)
{
    this->y = y;
}

void Universe::add(const Planet* pla)
{
      planets.push_back(pla->clone());
}

void Universe::addUnreachable(const Planet* pla)
{
    unreachablePlanets.push_back(pla->clone());
}
