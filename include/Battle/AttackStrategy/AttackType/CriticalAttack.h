#ifndef CRITICALATTACK_H
#define CRITICALATTACK_H
#include "AttackStrategy.h"

class CriticalAttack : public AttackStrategy
{
    public:
        CriticalAttack();
        virtual ~CriticalAttack();
        double giveDamage();
        bool isCritical()const;
        double howManyDamage()const;
        virtual string toString()const;
};

#endif // CRITICALATTACK_H
