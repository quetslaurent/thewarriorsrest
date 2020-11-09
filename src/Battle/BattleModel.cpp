#include "BattleModel.h"

BattleModel::BattleModel()
{
    //creation of the player and the enemy
    this->player = new Player(100);
    this->enemy = new EnemyBattle(100);
}

BattleModel::~BattleModel()
{
    //dtor
    delete player;
    delete enemy;
}


void BattleModel::setPlayerStrategy(AttackStrategy* attack){
    this->player->setStrategie(attack);
}

//the player attacks the enemy
void BattleModel::playerAttacksEnemy(){
    this->player->attack(this->enemy);
}

void BattleModel::enemyAttacksPlayer(){
    //the enemy attacks the player
    this->enemy->attack(this->player);
}

double BattleModel::getPlayerHp(){
    return player->getHealth().getHpCurrent();
}

double BattleModel::getEnemyHp(){
   return enemy->getHealth().getHpCurrent();
}

//return true if the player is alive
bool BattleModel::isPlayerAlive(){
    return this->player->getHealth().isAlive();
}
//return true if the enemy is alive
bool BattleModel::isEnemyAlive(){
    return this->enemy->getHealth().isAlive();
}



