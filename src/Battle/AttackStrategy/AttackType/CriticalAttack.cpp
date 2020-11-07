#include "CriticalAttack.h"

CriticalAttack::CriticalAttack():AttackStrategy(5.,10.,70.)
{
    //ctor
}

CriticalAttack::~CriticalAttack()
{
    //dtor
}
double CriticalAttack::giveDamage(){
    double  damage = howManyDamage();
    if(isCritical()){
         damage*=3;
    }
    cout<<"damage : "<<to_string(damage)<<"\n";
    return damage;

}


bool CriticalAttack::isCritical()const{
    srand(unsigned(time(0)));
        if(rand()%100+1 <= getCriticalRate()){
            return true;
        }
        return false;
}

double CriticalAttack::howManyDamage()const{
    srand(unsigned(time(0)));
    //int damage =  getMinAttack()+(rand()% (int)getMaxAttack());
    int damage =  rand()% ((int)getMaxAttack()-(int) getMinAttack()+1)+getMinAttack();

     cout<<"damage rand : "<<to_string(damage)<<"\n";
    return damage;
}
