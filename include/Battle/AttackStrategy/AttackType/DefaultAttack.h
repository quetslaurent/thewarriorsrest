#ifndef DEFAULTATTACK_H
#define DEFAULTATTACK_H
#include "AttackStrategy.h"


class DefaultAttack : public AttackStrategy
{
    public:
        DefaultAttack();
        virtual ~DefaultAttack();
        double giveDamage();
        bool isCritical()const;
        double howManyDamage()const;
};

#endif // DEFAULTATTACK_H
