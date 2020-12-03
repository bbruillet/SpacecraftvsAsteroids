#ifndef ISTRATEGYINCREASE_H
#define ISTRATEGYINCREASE_H

#include "Character.h"

/*
    This is the interface of the design pattern --> STRATEGY !
*/
class IStrategyIncrease
{
    public:
        /*
            The 4 next lines are :
                - constructor
                - destructor
                - copy contructor
                - operator=
        */
        IStrategyIncrease();
        virtual ~IStrategyIncrease();
        IStrategyIncrease(const IStrategyIncrease& other);
        IStrategyIncrease& operator=(const IStrategyIncrease& other);

        /*
            This is the strategy to be redefined (by dependant classes) in case of our choice
        */
        virtual void increase(Character& ch) = 0;

};

#endif // ISTRATEGYINCREASE_H
