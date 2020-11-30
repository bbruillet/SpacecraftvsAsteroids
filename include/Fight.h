#ifndef FIGHT_H
#define FIGHT_H

#include <iostream>
#include <string>

#include <cstdio>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;
using std::string;
using std::to_string;



class Character;

class Fight
{
    //variables
    private:
        int nb;
        int nbDodge;
        int nbFirst;
        int nbRegen;
        int health;


    public:
    //Constructeur
        Fight();
        virtual ~Fight();
        Fight(const Fight& other);
        Fight& operator=(const Fight& other);

    //Méthode de combat
        void attackBoss(Character& c1, Character& c2);
        void attackHero(Character& c1, Character& c2);
        void fightBoss(Character& c1, Character& c2);
        void regenHero(Character& c2, Character& c1);

        int getHealth() const;
        void setHealth(const int &);




};

#endif // COMBAT_H
