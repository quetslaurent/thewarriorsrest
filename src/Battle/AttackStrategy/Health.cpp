#include "Health.h"

Health::Health(double hp)
{
    this->hp=hp;
    this->hp_current=hp;

}

Health::Health()
{
    this->hp=100;
    this->hp_current=hp;

}

Health::~Health()
{
    //dtor
}
void Health::receiveDamage(double damage){
    if(isAlive()){
        hp_current -= damage;
    }
}

bool Health::isAlive(){
    if(hp_current<=0){
        hp_current=0;
        return false;
    }
    return true;
}

double Health::getHpCurrent(){
    return hp_current;
}

string Health::str()const{
    return to_string(hp) + " hp_current "+ to_string(hp_current);
}
