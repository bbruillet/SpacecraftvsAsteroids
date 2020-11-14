#ifndef PLANETE_H
#define PLANETE_H

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
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
        Planete(string nom, string image, int x, int y);
        Planete();

        virtual ~Planete();

        sf::Sprite planete_sprite;
        sf::Texture planete_texture;

        int getX() const;
        void setX(int x);

        int getY() const;
        void setY(int y);

};

#endif // PLANETE_H
