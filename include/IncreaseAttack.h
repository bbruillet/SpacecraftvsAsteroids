#ifndef INCREASEATTACK_H
#define INCREASEATTACK_H

#include "IStrategyIncrease.h"
#include "Character.h"

/*
    This is the class (used by dp) used to increase the attack of the hero !
    This class implements the interface
*/
class IncreaseAttack : public IStrategyIncrease
{
    public:
        /*
            The 4 next lines are :
                - constructor
                - destructor
                - copy contructor
                - operator=
        */
        IncreaseAttack();
        virtual ~IncreaseAttack();
        IncreaseAttack(const IncreaseAttack& other);
        IncreaseAttack& operator=(const IncreaseAttack& other);

        /*
            This strategy is defined here (from superclass).
            Here, the attack will be increased
        */
        void increase(Character& ch) override;
};

#endif // INCREASEATTACK_H
