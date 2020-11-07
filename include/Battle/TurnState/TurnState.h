#ifndef TURNSTATE_H
#define TURNSTATE_H
#include "Player.h"
#include "EnemyBattle.h"


class TurnState
{

    private:
        Player player;
        EnemyBattle enemy;
    public:
        TurnState();
        //canonique / poly
        TurnState(const TurnState& turnState);
        TurnState& operator=(const TurnState& turnState);
        virtual ~TurnState();

        virtual void nextState()=0;
        virtual void attack()=0;

        Player getPlayer()const;
        EnemyBattle getEnemy()const;


};

#endif // TURNSTATE_H
