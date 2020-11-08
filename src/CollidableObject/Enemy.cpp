#include "Enemy.h"

Enemy::Enemy(float posX,float posY,float width,float height):Hitbox(posX, posY, width, height)
{
    /*this->enemyTexture.loadFromFile("./image/enemyAnimation.png");
    this->enemySprite.setTexture(enemyTexture);//set the enemy texture on the sprite
    this->enemySprite.setTextureRect(sf::IntRect(2200,0,1100,1100));
    this->enemySprite.setScale(
    250 / enemySprite.getLocalBounds().width,
    250 / enemySprite.getLocalBounds().height);*/

    cout<<" test "<<"\n";
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::collide(sf::RectangleShape& playerHitbox){
    cout<<"ENEMY COLLISION"<<"\n";
    StateManager::stateId = 1;
}
