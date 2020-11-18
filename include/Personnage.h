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
        Personnage(const string = "", const string = "", const int = 0, const int = 0, const int = 0, const int = 0);
//        Personnage();
        virtual ~Personnage();
        Personnage(const Personnage&);
        Personnage& operator=(const Personnage&);

        //Méthodes utiles
        string str() const; //virtual -> héritage

        //Getters et setters
        int getPtsAttaque() const;
        void setPtsAttaque(const int &);

        int getPtsVie() const;
        void setPtsVie(const int &);

        int getPtsExperience() const;
        void setPtsExperience(const int &);

        int getNiveau() const;
        void setNiveau(const int &);

        string getNom() const;
        void setNom(const string &);

        string getRace() const;
        void setRace(const string &);
};

#endif // PERSONNAGE_H
