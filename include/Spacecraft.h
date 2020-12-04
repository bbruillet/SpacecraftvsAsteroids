#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <iostream>
#include <ostream>
#include <string>

#include "IConstante.h"

#include <cstdio>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

/*
    It is the class of a spacecraft
*/
class Spacecraft
{
    private:
        /*
            A spaceship has x and y coordinates
        */
        int x, y;


    public:
        /*
            The 3 next lines are :
                - constructor
                - destructor
                - operator=
        */
        Spacecraft(const int x = 7150, const int y = 3500);
        virtual ~Spacecraft();
        Spacecraft& operator=(const Spacecraft&);

        /*
            These lines are getters and setters of coordinates
        */
        int getX() const;
        void setX(const int &);
        int getY() const;
        void setY(const int &);

};

#endif // VSPACECRAFT_H
