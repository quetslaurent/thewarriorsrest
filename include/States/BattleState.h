#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "State.h"
#include "TurnState.h"
#include "PlayerTurn.h"
#include "EnemyTurn.h"

class BattleState:public State
{
    private:
        //map
        sf::Texture mapTexture;
        sf::Sprite s;

        TurnState* turnState;//DP that checks who has to attack

    public:
        BattleState(sf::RenderWindow* window);
        virtual ~BattleState();

        //functions
        void updateKeybinds();
        void update(const float& dt);
        void render();
        void endState();
        void setTurnState(TurnState* turnState);

};

#endif // BATTLESTATE_H
