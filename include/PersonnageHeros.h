#ifndef PERSONNAGEHEROS_H
#define PERSONNAGEHEROS_H

#include "Personnage.h"

enum Race
{
    HUMAIN,
    VALDERA,
    VANDUUL,
    COVENANTE,
    AETWI
    //const Race=Race::HUMAIN
};

class PersonnageHeros : public Personnage
{

    private:
        Race race;
    public:
        PersonnageHeros(const string nom = "Joueur", const int ptsAttaque = 0, const int ptsVie = 0, const int ptsExperience = 0, const int niveau = 0,
                   const int ptsAttaqueSpeciale = 0, const int bouclier = 0 ,const double coupsCritique = 0.0, const double esquive = 0.0, const Race=Race::HUMAIN);

        PersonnageHeros(const string nom = "Joueur", const Race=Race::HUMAIN);

        virtual ~PersonnageHeros();
        PersonnageHeros(const PersonnageHeros&);
        PersonnageHeros& operator=(const PersonnageHeros&);

        Race getRace()const;
        void setRace(const Race &);

        void categorieHeros();
        string str() const; //virtual -> héritage

};

#endif // PERSONNAGEHEROS_H
