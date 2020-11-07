#ifndef COLLIDE_H
#define COLLIDE_H
//game
#include "GameState.h"
#include "BattleState.h"
#include "IDimensions.h"
#include "IStateId.h"

#include <iostream>
using std::cout;

//enemy
#include "Hitbox.h"
#include "IStateId.h"

class Collide
{
    public:
        Collide();
        virtual ~Collide();

    protected:

    private:
};

#endif // COLLIDE_H
