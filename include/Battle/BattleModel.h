#ifndef BATTLEMODEL_H
#define BATTLEMODEL_H
#include "Player.h"
#include "EnemyBattle.h"

class BattleModel
{
    private:
        Player* player;
        EnemyBattle* enemy;

    public:
        BattleModel();
        virtual ~BattleModel();

    //set strategy
    void setPlayerStrategy(AttackStrategy* attack);

    //attacks
    void playerAttacksEnemy();
    void enemyAttacksPlayer();

    //getHp
    double getPlayerHp();
    double getEnemyHp();

    //is alive ?
    bool isEnemyAlive();
    bool isPlayerAlive();
};

#endif // BATTLEMODEL_H
