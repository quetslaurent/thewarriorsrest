#include "DefaultAttack.h"

DefaultAttack::DefaultAttack():AttackStrategy(10.,20.,30.)
{

}

DefaultAttack::~DefaultAttack()
{
    //dtor
}
double DefaultAttack::giveDamage(){
    double  damage = howManyDamage();
    if(isCritical()){
        damage*=1.3;
    }
cout<<"damage : "<<to_string(damage)<<"\n";
    return damage;

}


bool DefaultAttack::isCritical()const{
    srand(unsigned(time(0)));
        if(rand()%100+1 <= getCriticalRate()){
            return true;
        }
        return false;
}

double DefaultAttack::howManyDamage()const{
    srand(unsigned(time(0)));
    int damage =  rand()% ((int)getMaxAttack()-(int) getMinAttack()+1)+getMinAttack();
    cout<<"damage rand : "<<to_string(damage)<<"\n";
    return damage;
}

string DefaultAttack::toString()const{
    return "quick-attack";
}
