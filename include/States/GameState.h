#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "Entity.h"

class GameState :public State
{
    private:
        Entity player;
    public:
        GameState(sf::RenderWindow* window);
        virtual ~GameState();

        //map
        sf::Texture mapTexture;
        sf::Sprite s;
        sf::Vector2f position;//player position

        //functions

        void updateKeybinds();
        void update(const float& dt);
        void render();
        void endState();

};

#endif // GAMESTATE_H
