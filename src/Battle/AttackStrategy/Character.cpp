#include "Character.h"

Character::Character()
{
    this->health=Health();
}

Character::Character(Health health)
{
    this->health=health;
    //ctor
}

Character::~Character()
{
    delete m_strategie;
}
void Character::setStrategie(AttackStrategy* strategy){
    m_strategie=strategy;
}

void Character::attack(Character* p){
    double damage = m_strategie->giveDamage();
     p->receiveDamage(damage);
}

void Character::receiveDamage(double damage){
    this->health.receiveDamage(damage);
    cout<<"Vie : "<<health.str()<<"\n";
}

Health Character::getHealth()const{
    return health;
}

AttackStrategy* Character::getStrategy()const{
    return m_strategie;
}
