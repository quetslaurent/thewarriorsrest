#ifndef ATTACKSTRATEGY_H
#define ATTACKSTRATEGY_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class AttackStrategy
{
    private:
        double minAttack;
        double maxAttack;
        double criticalRate;

    public:
        AttackStrategy();
        AttackStrategy(double,double,double);
        virtual ~AttackStrategy();
        virtual double giveDamage()=0;
        virtual bool isCritical()const=0;
        virtual string toString()const=0;

        //getter
        double getCriticalRate()const;
        double getMinAttack()const;
        double getMaxAttack()const;
};

#endif // ATTACKSTRATEGY_H
