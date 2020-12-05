#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include "Planet.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;
using std::vector;

/*
    This class is the universe (where you can move from planets to planets)
*/
class Universe
{
    private:
        /*
        It is our variables that will allow us to put our planets in the universe
        */
        int x, y;

        /*
            Here we find the list of planets as well as the list of unreachablePlanets
        */
        vector<Planet*> planets;
        vector<Planet*> unreachablePlanets;


        /*
            It’s the texture and the sprite of the universe
        */
        sf::Sprite universe_sprite;
        sf::Texture universe_texture;
    public:
         /*
            The 3 next lines are :
                - construcor
                - destructor
                - copy contructor

            The constructor is defined by default.
        */
        Universe();
        virtual ~Universe();
        Universe(const Universe& univ);

        /*
            These functions are used for add planets and unreachable planets to the list of planets and unreachable planets
        */
        void add(const Planet*);
        void addUnreachable(const Planet*);

        /*
            These functions are getters and setters of x and y
        */
        int getX() const;
        void setX(int x);
        int getY() const;
        void setY(int y);

        /*
            It's where you can recover a planet(with the index)
        */
        Planet* getPlanet(int index);

        /*
            This function is used to know the size of planets' list
        */
        int getSizePlanets()const;

        /*
            It's where you can recover a unreachable planet(with the index)
        */
        Planet* getPlanetUnreach(int index);

        /*
            This function is used to know the size of unreachablePlanets' list
        */
        int getSizePlanetsUnreach()const;

        /*
            This is the getter of universe's sprite
        */
        sf::Sprite getUniverse_sprite() const;
};

#endif // UNIVERS_H
