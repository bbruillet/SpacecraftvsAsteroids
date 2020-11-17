#ifndef PERSONNAGE_H
#define PERSONNAGE_H


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

/*enum Race
{
    Humain,
    Valdera,
    Vanduul,
    Covenante
    Aetwi
};*/

class Personnage : public sf::Drawable, public sf::Event
{
    private:
        string nom, race;
        int ptsAttaque, ptsVie, ptsExperience, niveau;

    public:
        //Constucteurs et destructeurs
        Personnage(string nom, string race, int ptsAttaque, int ptsVie, int ptsExperience, int niveau);
        Personnage();
        virtual ~Personnage();
        Personnage(const Personnage& other);
        Personnage& operator=(const Personnage& other);

        //Méthodes utiles
        string str() const;

        //Getters et setters
        int getPtsAttaque() const;
        void setPtsAttaque(int ptsAttaque);

        int getPtsVie() const;
        void setPtsVie(int ptsVie);

        int getPtsExperience() const;
        void setPtsExperience(int ptsExperience);

        int getNiveau() const;
        void setNiveau(int ptsNiveau);

        string getNom() const;
        void setNom(string nom);

        string getRace() const;
        void setRace(string race);
};

#endif // PERSONNAGE_H
