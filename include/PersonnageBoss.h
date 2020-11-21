#ifndef PERSONNAGEBOSS_H
#define PERSONNAGEBOSS_H

#include "Personnage.h"




 enum Origine
{
    POLAIRE,
    TERRE,
    FEU
};

class PersonnageBoss : public Personnage
{

    private:
        Origine origine;



    public:
        PersonnageBoss(const string nom = "Boss", const int ptsAttaque = 0, const int ptsVie = 0, const int ptsExperience = 0, const int niveau = 0,
                   const int ptsAttaqueSpeciale = 0, const int bouclier = 0 ,const double coupsCritique = 0.0, const double esquive = 0.0, const Origine=Origine::TERRE);

        PersonnageBoss(const string nom = "Boss", const Origine=Origine::TERRE);

        virtual ~PersonnageBoss();
        PersonnageBoss(const PersonnageBoss& other);
        PersonnageBoss& operator=(const PersonnageBoss& other);


        Origine getOrigine()const;
        void setOrigine(const Origine &);

        void categorieBoss();
        string str() const;



};

#endif // PERSONNAGEBOSS_H
