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
    StateManager::stateId = 1;

}
