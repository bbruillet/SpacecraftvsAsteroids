#ifndef ISTRATEGYINCREASE_H
#define ISTRATEGYINCREASE_H

#include "Character.h"


class IStrategyIncrease
{
    public:
        IStrategyIncrease();
        virtual ~IStrategyIncrease();
        IStrategyIncrease(const IStrategyIncrease& other);
        IStrategyIncrease& operator=(const IStrategyIncrease& other);

        virtual void increase(Character& ch) = 0;


    protected:

    private:


};

#endif // ISTRATEGYINCREASE_H
