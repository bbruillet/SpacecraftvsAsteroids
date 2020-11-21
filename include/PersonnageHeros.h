#ifndef PERSONNAGEHEROS_H
#define PERSONNAGEHEROS_H

#include "Personnage.h"

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

enum Race
{
    HUMAIN,
    VALDERA,
    VANDUUL,
    COVENANTE,
    AETWI
    //const Race=Race::HUMAIN
};

class PersonnageHeros : public Personnage/*, public sf::Drawable*/
{

    private:
        Race race;
        int regeneration;
        int compteurRegen;

//        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;


    public:
        PersonnageHeros(const string nom = "Joueur", const int ptsAttaque = 0, const int ptsVie = 0, const int ptsExperience = 0, const int niveau = 0,
                   const int ptsAttaqueSpeciale = 0, const int bouclier = 0 ,const double coupsCritique = 0.0, const double esquive = 0.0, const Race=Race::HUMAIN, int regeneration = 0);

        PersonnageHeros(const string nom = "Joueur", const Race=Race::HUMAIN);

        virtual ~PersonnageHeros();
        PersonnageHeros(const PersonnageHeros&);
        PersonnageHeros& operator=(const PersonnageHeros&);

        Race getRace()const;
        void setRace(const Race &);

        void categorieHeros();
        string str() const; //virtual -> héritage

        int getRegeneration() const;
        void setRegeneration(const int &);

//        sf::Sprite persoHeros_sprite;
//        sf::Texture persoHeros_texture;

};

#endif // PERSONNAGEHEROS_H
