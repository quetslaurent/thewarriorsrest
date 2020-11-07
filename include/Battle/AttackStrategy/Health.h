#ifndef HEALTH_H
#define HEALTH_H
#include <iostream>
#include <string>

using namespace std;

class Health
{
    private:
        double hp;
        double hp_current;

    public:
        Health(double);
        Health();
        virtual ~Health();
        void receiveDamage(double damage);
        bool isAlive()const;
        string str()const;

};

#endif // HEALTH_H
