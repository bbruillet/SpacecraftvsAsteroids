#ifndef INCREASELIFE_H
#define INCREASELIFE_H

#include "IStrategyIncrease.h"
#include "Character.h"


class IncreaseLife : public IStrategyIncrease
{
    public:
        IncreaseLife();
        virtual ~IncreaseLife();
        IncreaseLife(const IncreaseLife& other);
        IncreaseLife& operator=(const IncreaseLife& other);
        void increase(Character& ch) override;

    protected:

    private:

};

#endif // INCREASELIFE_H
