#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "State.h"

class BattleState:public State
{
    private:
        //map
        sf::Texture mapTexture;
        sf::Sprite s;

        bool ableToFight; //check if the player can choose an attack

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
