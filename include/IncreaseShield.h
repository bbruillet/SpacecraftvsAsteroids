#ifndef INCREASESHIELD_H
#define INCREASESHIELD_H

#include "IStrategyIncrease.h"
#include "Character.h"

/*
    This is the class (used by dp) used to increase the shield of the hero !
    This class implements the interface
*/
class IncreaseShield : public IStrategyIncrease
{
    public:
        /*
            The 4 next lines are :
                - constructor
                - destructor
                - copy contructor
                - operator=
        */
        IncreaseShield();
        virtual ~IncreaseShield();
        IncreaseShield(const IncreaseShield& other);
        IncreaseShield& operator=(const IncreaseShield& other);

        /*
            This strategy is defined here (from superclass).
            Here, the shield will be increased
        */
        void increase(Character& ch) override;
};

#endif // INCREASESHIELD_H
