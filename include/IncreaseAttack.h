#ifndef INCREASEATTACK_H
#define INCREASEATTACK_H
#include "IStrategyIncrease.h"
#include "Character.h"

class IncreaseAttack : public IStrategyIncrease
{
    public:
        IncreaseAttack();
        virtual ~IncreaseAttack();
        IncreaseAttack(const IncreaseAttack& other);
        IncreaseAttack& operator=(const IncreaseAttack& other);
        void increase(Character& ch) override;

    protected:

    private:

};

#endif // INCREASEATTACK_H
