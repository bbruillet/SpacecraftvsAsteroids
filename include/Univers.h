#ifndef UNIVERS_H
#define UNIVERS_H

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include "Planete.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

class Univers : public sf::Drawable
{
    private:
        int x, y;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(univers_sprite);
        }

    public:
        Univers();
        virtual ~Univers();

        sf::Sprite univers_sprite;
        sf::Texture univers_texture;

        std::vector<Planete> planetes;

        void add(Planete pla);

        int getX() const;
        void setX(int x);

        int getY() const;
        void setY(int y);

    protected:

};

#endif // UNIVERS_H
