#ifndef VAISSEAU_H
#define VAISSEAU_H

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

class Vaisseau
{
    private:
        int x, y;

        //Méthode pour les sprites du vaisseau
        //virtual void draw(sf::RenderTarget&, sf::RenderStates) const;


    public:
        Vaisseau(const int x = 7150, const int y = 3500);
        virtual ~Vaisseau();



        int getX() const;
        void setX(const int &);

        int getY() const;
        void setY(const int &);

        Vaisseau& operator=(const Vaisseau&);

};

#endif // VAISSEAU_H
