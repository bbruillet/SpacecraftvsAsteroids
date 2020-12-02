#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <ostream>
#include <string>
#include <sstream>

#include <cstdio>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;


/*
    This class is the primary class of CharacterHero and CharacterBoss
*/
class Character
{
    private:
        /*
            The are members data of a character
            A character has a name, a picture (this the directory of his avatar), a number of :
                - Attack points, life points, special attack points, a shield, a number of badges, coordinates in a biome (x and y), and a number of regeneration points.
                He has also a capacity of doing a critical hit and a capacity to dodge an attack

                counterSpe is a counter used to prevent a special attack
                maxLife is an amount of life initialized at the beginning of the game
        */
        string name;
        int ptsAttack, ptsLife, badge, ptsSpecialAttack, shield;
        double criticalHit, dodge;
        int x,y;
        string picture;
        int regeneration;

        int counterSpe;

        int maxlife;



    public:
        /*
            The 4 next lines are :
                - construcor
                - destructor
                - copy contructor
                - operator=

            The constructor is defined by default.
        */
        Character(const string name = "Player", const int ptsAttack = 0, const int ptsLife = 10, const int badge = 0,
                   const int ptsSpecialAttack = 0, const int shield = 0 ,const double criticalHit = 0.0, const double dodge = 0.0, const int x = 0, const int y = 0,
                   const string picture = "Directory", const int regeneration = 0);

        virtual ~Character();
        Character(const Character&);
        Character& operator=(const Character&);

        /*
            These are str() fucntion of a character and a clone function
        */
        virtual string str() const;
        virtual Character* clone()const;


        /*
            These are all setters and getters of character's members data
        */
        string getName() const;
        void setName(const string &);


        /*
            This is all getters and setters of a charater
        */
        int getPtsAttack() const;
        void setPtsAttack(const int &);

        int getPtsLife() const;
        void setPtsLife(const int &);

        int getBadge() const;
        void setBadge(const int &);

        int getPtsSpecialAttack() const;
        void setPtsSpecialAttack(const int &);

        int getShield() const;
        void setShield(const int &);

        double getCriticalHit() const;
        void setCriticalHit(const double &);

        double getDodge() const;
        void setDodge(const double &);

        int getCounterSpe() const;
        void setCounterSpe(const int &);

        int getX() const;
        void setX(const int &);

        int getY() const;
        void setY(const int &);

        string getPicture() const;
        void setPicture(const string &);

        int getRegeneration() const;
        void setRegeneration(const int &);


};

#endif // CHARACTER_H
