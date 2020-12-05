#ifndef CHARACTERBOSS_H
#define CHARACTERBOSS_H

#include "Character.h"
#include "Planet.h"

/*
    In this enum, you can se that there is all planet's name. We'll associate a boss to a planet !
*/
enum Origin {
    BLUE,
    ORANGE,
    PURPLE_DESTROYED,
    RING_RED,
    GREEN,
    RING_BLUE
};

/*
    This class inherited Character's class
    This class was created for a boss
*/
class CharacterBoss : public Character
{

    private:
        /*The enumeration is called here*/
        Origin origin;


    public:
        /*
            The 5 next lines are :
                - constructor
                - 2nd constructor
                - destructor
                - copy contructor
                - operator=

            The constructor is defined by default and Origin is added in.
        */
        CharacterBoss(const string name = "Boss", const int ptsAttack = 0, const int ptsLife = 0, const int badge = 0,
                   const int ptsSpecialAttack = 0, const int shield = 0 ,const double criticalHit = 0.0, const double dodge = 0.0, const int x = 0, const int y = 0,
                   const string picture = "Directory", const int regeneration = 0, const Origin=Origin::BLUE);

        CharacterBoss(const string name = "Boss", const Origin=Origin::BLUE);

        virtual ~CharacterBoss();
        CharacterBoss(const CharacterBoss&);
        CharacterBoss& operator=(const CharacterBoss&);

        /*
            This is str() function of a boss
        */
        string str() const;

        /*
            This is clone function of a boss
        */
        virtual CharacterBoss* clone()const;

        /*
            These are the getter of the origin
        */
        Origin getOrigin()const;

        /*
            This is where the enumeration is used
        */
        void categoryBoss();

        /*
            A boss can resurrect here (their points are augmented after boss' loss
        */
        void resurrection();


};

#endif // CHARACTERBOSS_H
