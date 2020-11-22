#ifndef COMBAT_H
#define COMBAT_H

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
using std::cin;


class Personnage;

class Combat
{
    private:
        int nb;
        int nbEsquive;
        int nbPrem;
        int nbRegen;
        //int compteurSpe;

    public:
        Combat();
        virtual ~Combat();
        Combat(const Combat& other);
        Combat& operator=(const Combat& other);

        //Méthode de combat
        void attaquerBoss(Personnage& p1, Personnage& p2);
        void attaquerHeros(Personnage& p1, Personnage& p2);
        void combatBoss(Personnage& p1, Personnage& p2);
        void regen(Personnage& p1, Personnage& p2);


};

#endif // COMBAT_H
