#ifndef INCREASEREGENERATION_H
#define INCREASEREGENERATION_H

#include "IStrategyIncrease.h"
#include "Character.h"

class IncreaseRegeneration : public IStrategyIncrease
{
    public:
        IncreaseRegeneration();
        virtual ~IncreaseRegeneration();
        IncreaseRegeneration(const IncreaseRegeneration& other);
        IncreaseRegeneration& operator=(const IncreaseRegeneration& other);
        void increase(Character& ch) override;

    protected:

    private:
};

#endif // INCREASEREGENERATION_H
