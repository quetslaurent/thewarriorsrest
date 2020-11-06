#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "State.h"

class BattleState:public State
{
    private:
        //map
        sf::Texture mapTexture;
        sf::Sprite s;

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
