#include "Universe.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

Universe::Universe()
{
    /*
        it is a function to load the background
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
        delete planets[i]; //AIP
    }
    planets.clear();
    for(size_t i(0);i<unreachablePlanets.size();i++)
    {
        delete unreachablePlanets[i]; //AIP
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
    It's a  setter of x
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
