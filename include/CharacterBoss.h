#ifndef PERSONNAGEBOSS_H
#define PERSONNAGEBOSS_H

#include "Character.h"
#include "Planet.h"
enum Origin {
    BLUE,
    ORANGE,
    PURPLE_DESTROYED,
    RING_RED,
    GREEN,
    RING_BLUE
};

class CharacterBoss : public Character
{

    private:
        Origin origin;


    public:
        CharacterBoss(const string name = "Boss", const int ptsAttack = 0, const int ptsLife = 0, const int ptsExperience = 0, const int level = 0,
                   const int ptsSpecialAttack = 0, const int shield = 0 ,const double criticalHit = 0.0, const double dodge = 0.0, const int x = 0, const int y = 0,
                   const string picture = "Dossier", const int regeneration = 0, const Origin=Origin::BLUE);

        CharacterBoss(const string name = "Joueur", const Origin=Origin::BLUE);

        virtual ~CharacterBoss();
        CharacterBoss(const CharacterBoss&);
        CharacterBoss& operator=(const CharacterBoss&);



//        void categorieBoss();

        string str() const;

        Origin getOrigin()const;
        void setOrigin(const Origin &);

        virtual CharacterBoss* clone()const;

        void categoryBoss();


};

#endif // PERSONNAGEBOSS_H
