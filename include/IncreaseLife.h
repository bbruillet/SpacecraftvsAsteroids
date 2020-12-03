#ifndef INCREASELIFE_H
#define INCREASELIFE_H

#include "IStrategyIncrease.h"
#include "Character.h"

/*
    This is the class (used by dp) used to increase the life of the hero !
    This class implements the interface
*/
class IncreaseLife : public IStrategyIncrease
{
    public:
        /*
            The 4 next lines are :
                - constructor
                - destructor
                - copy contructor
                - operator=
        */
        IncreaseLife();
        virtual ~IncreaseLife();
        IncreaseLife(const IncreaseLife& other);
        IncreaseLife& operator=(const IncreaseLife& other);

        /*
            This strategy is defined here (from superclass).
            Here, the life will be increased
        */
        void increase(Character& ch) override;

    protected:

    private:

};

#endif // INCREASELIFE_H
