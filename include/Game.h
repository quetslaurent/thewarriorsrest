#ifndef GAME_H
#define GAME_H

#include "BattleState.h"
#include "GameState.h"
#include "IDimensions.h"
#include "IStateId.h"
#include "StateManager.h"

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
        std::vector<State*> states;
        int stateId; //th id of the state, referenced in IStateId

        //initialization
        void initWindow();
        void initStates();

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
