#ifndef BATTLE_H
#define BATTLE_H
#include "BattleState.h"

class Battle
{
    private:
        BattleState* battleState;//the battle view
    public:
        Battle(BattleState* battleState);
        virtual ~Battle();

};

#endif // BATTLE_H
