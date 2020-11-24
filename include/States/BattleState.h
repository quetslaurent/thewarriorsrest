#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "State.h"
#include <chrono>
#include <thread>
#include "StateManager.h"
#include "BattleModel.h"
#include "ViewController.h"

class BattleState:public State
{
    private:
        BattleView* battleView;
        BattleModel* battleModel;
        ViewController* viewController;

        bool ableToFight; //if the player can attack

    public:
        BattleState(sf::RenderWindow* window,ViewController* ViewController);
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
