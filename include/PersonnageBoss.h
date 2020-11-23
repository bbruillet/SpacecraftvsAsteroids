#ifndef PERSONNAGEBOSS_H
#define PERSONNAGEBOSS_H

#include "Personnage.h"
#include "Planete.h"
enum Origine {
    BLEUE,
    ORANGE,
    MAUVE_DETRUITE,
    ANNEAU_ROUGE,
    VERTE,
    ANNEAU_BLEU
};

class PersonnageBoss : public Personnage
{

    private:
        Origine origine;


    public:
        PersonnageBoss(const string nom = "Boss", const int ptsAttaque = 0, const int ptsVie = 0, const int ptsExperience = 0, const int niveau = 0,
                   const int ptsAttaqueSpeciale = 0, const int bouclier = 0 ,const double coupsCritique = 0.0, const double esquive = 0.0, const int x = 0, const int y = 0,
                   const string image = "Dossier", const int regeneration = 0, const Origine=Origine::BLEUE);

        PersonnageBoss(const string nom = "Joueur", const Origine=Origine::BLEUE);

        virtual ~PersonnageBoss();
        PersonnageBoss(const PersonnageBoss&);
        PersonnageBoss& operator=(const PersonnageBoss&);



//        void categorieBoss();

        string str() const;

        Origine getOrigine()const;
        void setOrigine(const Origine &);

        virtual PersonnageBoss* clone()const;

        void categorieBoss();


};

#endif // PERSONNAGEBOSS_H
