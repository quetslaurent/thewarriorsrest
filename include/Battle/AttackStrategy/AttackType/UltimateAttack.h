#ifndef ULTIMATEATTACK_H
#define ULTIMATEATTACK_H
#include "AttackStrategy.h"

class UltimateAttack : public AttackStrategy
{
    public:
        UltimateAttack();
        virtual ~UltimateAttack();
        double giveDamage();
        bool isCritical() const;
        double howManyDamage()const;
        virtual string toString()const;
};

#endif // ULTIMATEATTACK_H
