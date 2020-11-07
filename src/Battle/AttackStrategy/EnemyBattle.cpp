#include "EnemyBattle.h"

EnemyBattle::EnemyBattle():Character()
{
    //ctor
}

EnemyBattle::~EnemyBattle()
{
    //dtor
}

EnemyBattle::EnemyBattle(Health health):Character(health)
{

}

void EnemyBattle::attack(Character& p){
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
    }
    else if (numOfAttack==2){
        Character::setStrategie(new CriticalAttack());
    }
    else{
        Character::setStrategie(new UltimateAttack());
    }

}
