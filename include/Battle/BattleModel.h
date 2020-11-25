#ifndef BATTLEMODEL_H
#define BATTLEMODEL_H
#include "Player.h"
#include "EnemyBattle.h"
#include "Hitbox.h"
#include <vector>
#include "Enemy.h"

class BattleModel
{
    private:
        Player* player;
        EnemyBattle* enemy;
        std::vector<Hitbox*>* hitboxes;

    public:
        BattleModel(std::vector<Hitbox*>* hitboxes);
        virtual ~BattleModel();

    //set strategy
    void setPlayerStrategy(AttackStrategy* attack);

    //attacks
    void playerAttacksEnemy();
    AttackStrategy* enemyAttacksPlayer();

    //getHp
    double getPlayerHp();
    double getEnemyHp();

    //is alive ?
    bool isEnemyAlive();
    bool isPlayerAlive();

    //init
    void initFighters();

    //check if its win
    bool isWin();

};

#endif // BATTLEMODEL_H
