#include "EnemyBattle.h"

EnemyBattle::EnemyBattle():Character()
{
    this->enemyTexture.loadFromFile("./image/enemyBattle.png");
    this->enemySprite.setTexture(enemyTexture);//set the enemy texture on the sprite
    this->enemySprite.setTextureRect(sf::IntRect(2200,0,1100,1100));
    this->enemySprite.setPosition(1200,450);
    this->enemySprite.setScale(
    250 / enemySprite.getLocalBounds().width,
    250 / enemySprite.getLocalBounds().height);
}

EnemyBattle::~EnemyBattle()
{
    //dtor
}

EnemyBattle::EnemyBattle(Health health):Character(health)
{
    this->enemyTexture.loadFromFile("./image/enemyBattle.png");
    this->enemySprite.setTexture(enemyTexture);//set the enemy texture on the sprite
    this->enemySprite.setTextureRect(sf::IntRect(2200,0,1100,1100));
    this->enemySprite.setPosition(1200,450);
    this->enemySprite.setScale(
    250 / enemySprite.getLocalBounds().width,
    250 / enemySprite.getLocalBounds().height);
}

void EnemyBattle::attack(Character* p){
    setStrategie();
     Character::attack(p);
}

void EnemyBattle::receiveDamage(double damage){
    Character::receiveDamage(damage);
}

void EnemyBattle::setStrategie(){
    srand(unsigned(time(0)));
    int numOfAttack =  rand()% (3)+1;
    if(numOfAttack==1){
        Character::setStrategie(new DefaultAttack());
        cout<<"Ennemy launched a default attack !"<<"\n";
    }
    else if (numOfAttack==2){
        Character::setStrategie(new CriticalAttack());
          cout<<"Ennemy launched a critical attack !"<<"\n";
    }
    else{
        Character::setStrategie(new UltimateAttack());
          cout<<"Ennemy launched an ultimate attack !"<<"\n";
    }

}

void EnemyBattle::render(sf::RenderWindow* window){
    window->draw(this->enemySprite);
}

sf::Sprite& EnemyBattle::getSprite(){
    return enemySprite;
}

