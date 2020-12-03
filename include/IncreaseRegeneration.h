#ifndef INCREASEREGENERATION_H
#define INCREASEREGENERATION_H

#include "IStrategyIncrease.h"
#include "Character.h"

/*
    This is the class (used by dp) used to increase the regeneration of the hero !
    This class implements the interface
*/
class IncreaseRegeneration : public IStrategyIncrease
{
    public:
        /*
            The 4 next lines are :
                - constructor
                - destructor
                - copy contructor
                - operator=
        */
        IncreaseRegeneration();
        virtual ~IncreaseRegeneration();
        IncreaseRegeneration(const IncreaseRegeneration& other);
        IncreaseRegeneration& operator=(const IncreaseRegeneration& other);

        /*
            This strategy is defined here (from superclass).
            Here, the regeneration will be increased
        */
        void increase(Character& ch) override;

    protected:

    private:
};

#endif // INCREASEREGENERATION_H
