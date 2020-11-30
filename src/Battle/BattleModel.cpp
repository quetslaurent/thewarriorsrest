#include "BattleModel.h"

BattleModel::BattleModel(std::vector<Hitbox*>* hitboxes)
{
   this->hitboxes=hitboxes;
   initFighters();
}

BattleModel::~BattleModel()
{
    //dtor
    delete healthP;
    delete healthE;
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

AttackStrategy* BattleModel::enemyAttacksPlayer(){
    //the enemy attacks the player
    this->enemy->attack(this->player);
    return this->enemy->getStrategy();
}

double BattleModel::getPlayerHp(){
    return player->getHealth()->getHpCurrent();
}

double BattleModel::getEnemyHp(){
   return enemy->getHealth()->getHpCurrent();
}

//return true if the player is alive
bool BattleModel::isPlayerAlive(){
    return this->player->getHealth()->isAlive();
}
//return true if the enemy is alive
bool BattleModel::isEnemyAlive(){
    return this->enemy->getHealth()->isAlive();
}

//init player and enemy
void BattleModel::initFighters()
{
     //creation of the player and the enemy
    healthP = new Health(100);
    healthE = new Health(100);
    this->player = new Player(healthP);
    this->enemy = new EnemyBattle(healthE);
}

bool BattleModel::isWin()
{
    std::vector<Hitbox*> listHitbox = *hitboxes;
    for(int i=0;i<(int)listHitbox.size();i++){
        if(dynamic_cast<Enemy*>(listHitbox[i]) != nullptr){
            return false;
        }
    }
    return true;
}





