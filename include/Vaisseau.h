#ifndef VAISSEAU_H
#define VAISSEAU_H

#include <iostream>
#include <ostream>
#include <string>

#include "IConstante.h"

#include <cstdio>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

class Vaisseau : public sf::Drawable, public sf::Event, public IConstante
{
    private:
        int x, y;

        //Méthode pour les sprites du vaisseau
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;


    public:
        Vaisseau(const int x = 7150, const int y = 3500);
        virtual ~Vaisseau();

        //Sprite et texture du vaisseau
        sf::Sprite vaisseau_sprite;
        sf::Texture vaisseau_texture;

        //Méthodes de positions
        int seDeplacerX(Event event, int x);
        int seDeplacerY(Event event, int y);

        int getX() const;
        void setX(const int &);

        int getY() const;
        void setY(const int &);
};

#endif // VAISSEAU_H
