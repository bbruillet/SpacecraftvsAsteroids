#ifndef COMBAT_H
#define COMBAT_H

#include <iostream>
#include <string>

#include <cstdio>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;
using std::string;
using std::to_string;



class Personnage;

class Combat
{
    //variables
    private:
        int nb;
        int nbEsquive;
        int nbPrem;
        int nbRegen;


    public:
    //Constructeur
        Combat();
        virtual ~Combat();
        Combat(const Combat& other);
        Combat& operator=(const Combat& other);

    //Méthode de combat
        void attaquerBoss(Personnage& p1, Personnage& p2, sf::RenderWindow &window);
        void attaquerHeros(Personnage& p1, Personnage& p2);
        void combatBoss(Personnage& p1, Personnage& p2, sf::RenderWindow &window);


};

#endif // COMBAT_H
