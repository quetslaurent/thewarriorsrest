#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"


class Player : public Character
{
    private:

    public:
        Player();
        Player(Health health);
        virtual ~Player();
        void attack(Character& p);
        void receiveDamage(double damage);
        void setStrategie(AttackStrategy* strategie);
};

#endif // PLAYER_H
