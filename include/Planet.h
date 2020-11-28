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

class BiomePlanet;
class CharacterBoss;

class Planet : public sf::Drawable
{
    private:
        string name;
        string picture;
        int x, y;
        int xChar, yChar;
        CharacterBoss* bossPlan;
        BiomePlanet* biome;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(planet_sprite);
        }

    public:
        Planet(string nom = "Planet", string image = "Directory", int x = 0, int y = 0, const int xChar = 0, const int yChar = 0);

        Planet(const Planet& plan);

        virtual ~Planet();

        virtual bool operator==(const Planet& plan);
        Planet& operator=(const Planet& plan);

        sf::Sprite planet_sprite;
        sf::Texture planet_texture;

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

        void giveBiome(BiomePlanet&);
        BiomePlanet* getBiome()const;

        void giveBoss(CharacterBoss&);
        CharacterBoss* getBoss()const;

        virtual Planet* clone() const;

//        void ajouter(PersonnageBoss boss);

};

#endif // PLANETE_H
