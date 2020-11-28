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

class Spacecraft
{
    private:
        int x, y;

        //Méthode pour les sprites du vaisseau
        //virtual void draw(sf::RenderTarget&, sf::RenderStates) const;


    public:
        Spacecraft(const int x = 7150, const int y = 3500);
        virtual ~Spacecraft();



        int getX() const;
        void setX(const int &);

        int getY() const;
        void setY(const int &);

        Spacecraft& operator=(const Spacecraft&);

};

#endif // VAISSEAU_H
