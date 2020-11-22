#ifndef PERSONNAGEBOSS_H
#define PERSONNAGEBOSS_H

#include "Personnage.h"
#include "Planete.h"

class PersonnageBoss : public Personnage
{

    private:


    public:
        PersonnageBoss(const string nom = "Boss", const int ptsAttaque = 0, const int ptsVie = 0, const int ptsExperience = 0, const int niveau = 0,
                   const int ptsAttaqueSpeciale = 0, const int bouclier = 0 ,const double coupsCritique = 0.0, const double esquive = 0.0, const int x = 0, const int y = 0,
                   const string image = "Dossier", const int regeneration = 0);

//        PersonnageBoss(const string nom = "Boss");

        virtual ~PersonnageBoss();
        PersonnageBoss(const PersonnageBoss& other);
        PersonnageBoss& operator=(const PersonnageBoss& other);



        void categorieBoss();

        string str() const;




};

#endif // PERSONNAGEBOSS_H
