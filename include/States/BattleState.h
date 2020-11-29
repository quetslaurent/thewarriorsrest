#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "State.h"
#include <chrono>
#include <thread>
#include "StateManager.h"
#include "BattleModel.h"


class BattleState:public State
{
    private:
        BattleView* battleView;
        BattleModel* battleModel;
        ViewController* viewController;
        AttackStrategy* strategy;

        bool ableToFight; //if the player can attack

    public:
        BattleState(sf::RenderWindow* window,ViewController* ViewController,std::vector<Hitbox*>* hitboxes);
        virtual ~BattleState();

        //functions
        void updateKeybinds();
        void update(const float& dt);
        void render();
        void endState();

        //battle
        void makeRound();

        //waiting
        void sleep();

};

#endif // BATTLESTATE_H
