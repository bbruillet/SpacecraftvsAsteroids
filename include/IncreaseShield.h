#ifndef INCREASESHIELD_H
#define INCREASESHIELD_H

#include "IStrategyIncrease.h"
#include "Character.h"

class IncreaseShield : public IStrategyIncrease
{
    public:
        IncreaseShield();
        virtual ~IncreaseShield();
        IncreaseShield(const IncreaseShield& other);
        IncreaseShield& operator=(const IncreaseShield& other);
        void increase(Character& ch) override;

    protected:

    private:
};

#endif // INCREASESHIELD_H
