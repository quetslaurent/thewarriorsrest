#ifndef GAME_H
#define GAME_H

#include "BattleState.h"
#include "GameState.h"
#include "LooseState.h"
#include "IDimensions.h"
#include "IStateId.h"
#include "StateManager.h"
#include "ViewController.h"
#include <iostream>
using std::cout;

class Game : public IDimensions,IStateId
{
    private:
        //variables
        sf::RenderWindow *wGame;     //main window
        sf::Event sfEvent;

        sf::Clock dtClock;
        float dt;   //delta time

        //views
        ViewController* viewController;
        std::vector<State*> states;

        //initialization
        void initWindow();
        void initStates();
        void initViewController();

    public:
        Game();
        virtual ~Game();

        //fonctions
        void run();

        //update
        void updateSFMLEvents();
        void update();
        void updateDt();

        //render
        void render();

        //end
        void endApplication();

};

#endif // GAME_H
