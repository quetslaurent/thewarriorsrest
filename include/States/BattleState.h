#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "State.h"
#include "Player.h"
#include "EnemyBattle.h"
#include <chrono>
#include <thread>
#include "StateManager.h"

class BattleState:public State
{
    private:
        //map
        sf::Texture mapTexture;
        sf::Sprite s;

        bool ableToFight; //if the player can attack

        Player* player;
        EnemyBattle* enemy;

        //healthbar
        sf::RectangleShape playerHealth;
        sf::RectangleShape enemyHealth;


    public:
        BattleState(sf::RenderWindow* window);
        virtual ~BattleState();

        //functions
        void updateKeybinds();
        void update(const float& dt);
        void render();
        void endState();

        //battle
        void makeRound();
        void enemyTurn();

        //draw health bars
        void drawHealthPlayer();
        void drawHealthEnemy();
        void sleep();

};

#endif // BATTLESTATE_H
