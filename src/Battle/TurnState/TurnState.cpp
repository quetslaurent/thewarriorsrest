#include "TurnState.h"

TurnState::TurnState()
{
    //ctor
}

TurnState::~TurnState()
{
    //dtor
}

TurnState::TurnState(const TurnState& turnState){
    //copy ctor
}

TurnState& TurnState::operator=(const TurnState& turnState){
    if(&turnState != this) {
    }
    return *this;
}

Player TurnState::getPlayer()const
{
    return this->player;
}

EnemyBattle TurnState::getEnemy()const
{
    return this->enemy;
}
