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

class Character /*: public sf::Drawable, public sf::Event*/
{
    private:
        string name;
        int ptsAttack, ptsLife, ptsExperience, level, ptsSpecialAttack, shield;
        double criticalHit, dodge;
        int counterSpe;
        int x,y;
        string picture;
        int regeneration;



    public:
        //Constucteurs et destructeurs
        Character(const string name = "Joueur", const int ptsAttack = 0, const int ptsLife = 10, const int ptsExperience = 0, const int level = 0,
                   const int ptsSpecialAttack = 0, const int shield = 0 ,const double criticalHit = 0.0, const double dodge = 0.0, const int x = 0, const int y = 0,
                   const string picture = "Directory", const int regeneration = 0);

        virtual ~Character();
        Character(const Character&);
        Character& operator=(const Character&);

        //Méthodes utiles
        virtual string str() const;
        virtual Character* clone()const;
        //Getters et setters
        string getName() const;
        void setName(const string &);

        int getPtsAttack() const;
        void setPtsAttack(const int &);

        int getPtsLife() const;
        void setPtsLife(const int &);

        int getPtsExperience() const;
        void setPtsExperience(const int &);

        int getLevel() const;
        void setLevel(const int &);

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

#endif // PERSONNAGE_H
