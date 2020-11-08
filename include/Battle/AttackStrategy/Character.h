#ifndef CHARACTER_H
#define CHARACTER_H

#include "AttackStrategy.h"
#include "DefaultAttack.h"
#include "UltimateAttack.h"
#include "CriticalAttack.h"
#include "Health.h"

class Character
{
    private:
        Health health;
        AttackStrategy* m_strategie;

    public:
        Character();
        Character(Health health);
        virtual ~Character();
        void attack(Character* p);
        void receiveDamage(double damage);
        void setStrategie(AttackStrategy* strategie);
        Health getHealth()const;

};

#endif // CHARACTER_H
