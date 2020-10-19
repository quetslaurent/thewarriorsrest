#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState :
    public State
{
    private:
        Entity player;
    public:
        GameState(sf::RenderWindow* window);
        virtual ~GameState();

        //functions

        void updateKeybinds(const float& dt);
        void update(const float& dt);
        void render(sf::RenderTarget* target= NULL);
        void endState();
};

#endif // GAMESTATE_H
