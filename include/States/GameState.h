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

        void updateKeybinds(const float& dt);
        void update(const float& dt);
        void render(sf::RenderTarget* target= NULL);
        void endState();

        Entity getPlayer(){
            return player;
        }

        int getXPosPlayer();

        string str()const{
            return "test";
        }
};

#endif // GAMESTATE_H
