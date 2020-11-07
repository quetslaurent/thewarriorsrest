#ifndef DEFENSIVEATTACK_H
#define DEFENSIVEATTACK_H
#include "AttackStrategy.h"


class DefensiveAttack : public AttackStrategy
{
    public:
        DefensiveAttack();
        virtual ~DefensiveAttack();
        double giveDamage();
        bool isCritical()const;
        double howManyDamage()const;
};

#endif // DEFENSIVEATTACK_H
