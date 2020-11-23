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
using std::vector;


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
        Univers(const Univers& univ);

        vector<Planete*> planetes;

        vector<Planete*> planetesInaccessibles;

        sf::Sprite univers_sprite;
        sf::Texture univers_texture;

        void add(const Planete*);
        void addInacc(const Planete*);

        int getX() const;
        void setX(int x);

        int getY() const;
        void setY(int y);
};

#endif // UNIVERS_H
