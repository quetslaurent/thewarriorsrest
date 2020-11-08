#include "Enemy.h"

Enemy::Enemy(float posX,float posY,float width,float height):Hitbox(posX, posY, width, height)
{

}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::collide(sf::RectangleShape& playerHitbox){
    cout<<"ENEMY COLLISION"<<"\n";
    playerHitbox.setPosition(playerHitbox.getPosition().x,playerHitbox.getPosition().y-20);
    StateManager::stateId = BATTLE_STATE; //change view to BattleState
}
