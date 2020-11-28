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


    public:
    //Constructeur
        Fight();
        virtual ~Fight();
        Fight(const Fight& other);
        Fight& operator=(const Fight& other);

    //Méthode de combat
        void attackBoss(Character& c1, Character& c2, sf::RenderWindow &window);
        void attackHero(Character& c1, Character& c2);
        void fightBoss(Character& c1, Character& c2, sf::RenderWindow &window);


};

#endif // COMBAT_H
