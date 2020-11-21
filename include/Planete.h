#ifndef PLANETE_H
#define PLANETE_H

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include "PersonnageBoss.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

class BiomePlanete;

class Planete : public sf::Drawable
{
    private:
//        std::vector<PersonnageBoss> bosses;
        BiomePlanete* biom;
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

        Planete(const Planete& plan);

        virtual ~Planete();

        virtual bool operator==(const Planete& plan);


        sf::Sprite planete_sprite;
        sf::Texture planete_texture;

        int getX() const;
        void setX(int x);

        int getY() const;
        void setY(int y);

        string getNom() const;
        void setNom(const string &);

        void DonnerBiome(BiomePlanete&);
        BiomePlanete* getBiome()const;

//        void ajouter(PersonnageBoss boss);

};

#endif // PLANETE_H
