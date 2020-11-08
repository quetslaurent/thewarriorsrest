#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "State.h"
#include "Player.h"
#include "EnemyBattle.h"
#include <chrono>
#include <thread>

class BattleState:public State
{
    private:
        //map
        sf::Texture mapTexture;
        sf::Sprite s;

        bool ableToFight;

        Player* player;
        EnemyBattle* enemy;

    public:
        BattleState(sf::RenderWindow* window);
        virtual ~BattleState();

        //functions
        void updateKeybinds();
        void update(const float& dt);
        void render();
        void endState();

};

#endif // BATTLESTATE_H
