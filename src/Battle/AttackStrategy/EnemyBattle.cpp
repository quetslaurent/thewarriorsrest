#include "EnemyBattle.h"

EnemyBattle::EnemyBattle():Character()
{

}

EnemyBattle::~EnemyBattle()
{
    //dtor
}

EnemyBattle::EnemyBattle(Health health):Character(health)
{

}

void EnemyBattle::attack(Character* p){
    setStrategy();
    Character::attack(p);
}


void EnemyBattle::setStrategy(){
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


