#ifndef PLAYERTURN_H
#define PLAYERTURN_H
#include "TurnState.h"
#include <SFML/Graphics.hpp>

class PlayerTurn : public TurnState
{
    private:

    public:
        PlayerTurn();
        virtual ~PlayerTurn();

        void nextState();
        void attack();
};

#endif // PLAYERTURN_H
