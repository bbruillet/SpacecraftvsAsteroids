#include "Universe.h"

Universe::Universe()
{
    /*
        it is a function used to load the background
    */
    if (!universe_texture.loadFromFile("Images/Backgrounds/Universe.png"))
    {
        std::cout << "Problem while loading universe's background" << std::endl;
    }
    /*
        Allows to give a texture and position
    */
    int x = 0;
    int y = 0;
    universe_sprite.setTexture(universe_texture);
    universe_sprite.setOrigin(1000,1000);
    universe_sprite.setPosition(x, y);
    universe_sprite.scale(3.0f, 3.0f);
}
/*
    This is the copy constructor
*/
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

/*
    This is the destructor
*/
Universe::~Universe()
{
    //dtor
     for(size_t i(0);i<planets.size();i++)
    {
        delete planets[i];
    }
    planets.clear();
    for(size_t i(0);i<unreachablePlanets.size();i++)
    {
        delete unreachablePlanets[i];
    }
    unreachablePlanets.clear();
}
/*
    It's a getter x
*/
int Universe::getX() const
{
    return x;
}
/*
    It's a setter of x
*/
void Universe::setX(int x)
{
    this->x = x;
}
/*
    It's a getter y
*/
int Universe::getY() const
{
    return y;
}
/*
    It's a setter of y
*/
void Universe::setY(int y)
{
    this->y = y;
}
/*
    The function adds planets to the list of planets
*/
void Universe::add(const Planet* pla)
{
      planets.push_back(pla->clone());
}
/*
    The function adds unreachable planets to the list of unreachable planets
*/
void Universe::addUnreachable(const Planet* pla)
{
    unreachablePlanets.push_back(pla->clone());
}

/*
    It's a function used to find a planet by it's index
*/
Planet* Universe::getPlanet(int index)
{
    return planets[index];
}

/*
    This is the function used to know size of planets' list
*/
int Universe::getSizePlanets()const
{
    return planets.size();
}

/*
    It's a function used to find a unreachablePlanets by it's index
*/
Planet* Universe::getPlanetUnreach(int index)
{
    return unreachablePlanets[index];
}

/*
    This function is used to know the size of the list : unreachablePlanets
*/
int Universe::getSizePlanetsUnreach()const
{
    return unreachablePlanets.size();
}

/*
    This is the getter to recover the prite of the universe
*/
sf::Sprite Universe::getUniverse_sprite() const
{
    return universe_sprite;
}
