#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "Entity.h"
#include "GameModel.h"

class GameState :public State
{
    private:
        Entity* player;
        bool debug; // set to know if we show the hitboxes or not

        GameView* gameView;
        GameModel* gameModel;
        ViewController* viewController;

    public:
        GameState(sf::RenderWindow* window,ViewController* viewController);
        virtual ~GameState();

        //functions

        void updateKeybinds();
        void update(const float& dt);
        void render();
        void endState();

};

#endif // GAMESTATE_H
