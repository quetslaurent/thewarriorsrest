#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
using std::string;
#include <string>

class GameState :
    public State
{
    private:
        Entity player;
    public:
        GameState(sf::RenderWindow* window);
        virtual ~GameState();

        //functions

        void updateKeybinds();
        void update(const float& dt);
        void render(sf::RenderTarget* target= nullptr);
        void endState();

        Entity getPlayer();
};

#endif // GAMESTATE_H
