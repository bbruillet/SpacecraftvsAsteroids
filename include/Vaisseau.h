#ifndef VAISSEAU_H
#define VAISSEAU_H

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

class Vaisseau : public sf::Drawable, public sf::Event
{
    private:
        int x, y;

        //Méthode pour les sprites du vaisseau
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(vaisseau_sprite);
        }

    public:
        Vaisseau();
        virtual ~Vaisseau();

        //Sprite et texture du vaisseau
        sf::Sprite vaisseau_sprite;
        sf::Texture vaisseau_texture;

        //Méthodes de positions
        int seDeplacerX(Event event, int x);
        int seDeplacerY(Event event, int y);

        int getX() const;
        void setX(int x);

        int getY() const;
        void setY(int y);
};

#endif // VAISSEAU_H
