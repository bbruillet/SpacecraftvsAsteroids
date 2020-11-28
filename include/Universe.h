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


class Universe : public sf::Drawable
{
    private:
        int x, y;


        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(universe_sprite);
        }

    public:
        Universe();
        virtual ~Universe();
        Universe(const Universe& univ);

        vector<Planet*> planets;

        vector<Planet*> unreachablePlanets;

        sf::Sprite universe_sprite;
        sf::Texture universe_texture;

        void add(const Planet*);
        void addUnreachable(const Planet*);

        int getX() const;
        void setX(int x);

        int getY() const;
        void setY(int y);
};

#endif // UNIVERS_H
