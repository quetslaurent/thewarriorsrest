#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "IDimensions.h"

class Game : public IDimensions
{
    private:
        //variables
        sf::RenderWindow *wGame;     //main window
        sf::Event sfEvent;

        sf::Vector2f position;//player position

        sf::Clock dtClock;
        float dt;   //delta time

        std::stack<State*> states;

        //initialization
        void initWindow();
        void initStates();

        //map
        sf::Texture mapTexture;
        sf::Sprite s;

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
