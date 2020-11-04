#ifndef PLANETE_H
#define PLANETE_H

#include <iostream>
#include <ostream>
#include <string>

#include <cstdio>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

class Planete : public sf::Drawable
{
    private:


        string nom;
        string image;
        int x, y;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(planete_sprite);
        }

    public:
        Planete();
        Planete(string nom, string image, int x, int y);
        virtual ~Planete();

        sf::Sprite planete_sprite;
        sf::Texture planete_texture;

};

#endif // PLANETE_H
