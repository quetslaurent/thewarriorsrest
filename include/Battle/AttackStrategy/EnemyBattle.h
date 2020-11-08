#ifndef ENEMYBATTLE_H
#define ENEMYBATTLE_H
#include "Character.h"
#include <cstdlib>
#include <ctime>



class EnemyBattle : public Character
{
    public:
        EnemyBattle();
        EnemyBattle(Health health);
        virtual ~EnemyBattle();
        void attack(Character* p);
        void receiveDamage(double damage);
        void setStrategie();

};

#endif // ENEMYBATTLE_H
