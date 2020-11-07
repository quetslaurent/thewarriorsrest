#include "AttackStrategy.h"

AttackStrategy::AttackStrategy()
{
    //ctor
}

AttackStrategy::AttackStrategy(double minAttack, double maxAttack, double criticalRate)
{

    this->minAttack=minAttack;
    this->maxAttack=maxAttack;
    this->criticalRate=criticalRate;

}

AttackStrategy::~AttackStrategy()
{
    //dtor
}
double AttackStrategy::getCriticalRate()const{
    return criticalRate;

}

double AttackStrategy::getMaxAttack()const{
    return maxAttack;
}

double AttackStrategy::getMinAttack()const{
    return minAttack;
}
