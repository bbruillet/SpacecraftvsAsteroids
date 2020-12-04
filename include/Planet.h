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

class CharacterBoss;

/*
    This class is used by a planet. A planet is a place where you can land ! A planet is placed in the universe too !
*/
class Planet : public sf::Drawable
{
    private:
        /*
            A planet has a name, a picture (*.png), coordinates x and y (to be placed in the universe), coordinates to place the hero (x and y) and a boss.
            In fact a boss is associated to a planet !
        */
        string name;
        string picture;
        int x, y;
        int xChar, yChar;
        CharacterBoss* bossPlan;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(planet_sprite);
        }

    public:
        /*
            The 6 next lines are :
                - constructor
                - destructor
                - copy contructor
                - operator==
                - operator=
                - clone
        */
        Planet(string nom = "Planet", string image = "Directory", int x = 0, int y = 0, const int xChar = 0, const int yChar = 0);
        Planet(const Planet& plan);
        virtual ~Planet();
        virtual bool operator==(const Planet& plan);
        Planet& operator=(const Planet& plan);
        virtual Planet* clone() const;

        /*
            This is the sprite & the texture of a planet
        */
        sf::Sprite planet_sprite;
        sf::Texture planet_texture;

        /*
            Nex lines are getters and setters of planets (x, y, xChar, yChar, boss, name and picture)
        */
        int getX() const;
        void setX(int x);

        int getY() const;
        void setY(int y);

        int getXChar() const;
        void setXChar(int xChar);

        int getYChar() const;
        void setYChar(int yChar);

        string getName() const;
        void setName(const string &);

        /*GiveBoss is setter*/
        void giveBoss(CharacterBoss&);
        CharacterBoss* getBoss()const;
};

#endif // PLANETE_H
