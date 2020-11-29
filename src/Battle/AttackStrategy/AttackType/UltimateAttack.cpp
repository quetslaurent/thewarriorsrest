#include "UltimateAttack.h"

UltimateAttack::UltimateAttack():AttackStrategy(15.,25.,10.)
{
    //ctor
}

UltimateAttack::~UltimateAttack()
{
    //dtor
}
double UltimateAttack::giveDamage(){
    double  damage = howManyDamage();
    if(isCritical()){
        damage*=1.5;
    }
cout<<"damage : "<<to_string(damage)<<"\n";
    return damage;

}


bool UltimateAttack::isCritical()const{
    srand(unsigned(time(0)));
        if(rand()%100+1 <= getCriticalRate()){
            return true;
        }
        return false;
}

double UltimateAttack::howManyDamage()const{
    srand(unsigned(time(0)));
    int damage =  rand()% ((int)getMaxAttack()-(int) getMinAttack()+1)+getMinAttack();
    cout<<"damage rand : "<<to_string(damage)<<"\n";
    return damage;
}

string UltimateAttack::toString()const{
    return "double-edge";
}

