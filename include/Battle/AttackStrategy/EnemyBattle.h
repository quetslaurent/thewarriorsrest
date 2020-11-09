#ifndef ENEMYBATTLE_H
#define ENEMYBATTLE_H
#include "Character.h"
#include <cstdlib>
#include <ctime>

class EnemyBattle : public Character
{
    private:


    public:
        EnemyBattle();
        EnemyBattle(Health health);
        virtual ~EnemyBattle();
        void attack(Character* p);
        void setStrategy();
};

#endif // ENEMYBATTLE_H
