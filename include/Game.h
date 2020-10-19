#ifndef GAME_H
#define GAME_H

#include "GameState.h"

class Game
{
    private:
        //variables
        sf::RenderWindow *wGame;     //main window
        sf::Event sfEvent;


        sf::Clock dtClock;
        float dt;   //delta time

        std::stack<State*> states;

        //initialization
        void initWindow();
        void initStates();


        //map
        sf::Texture map;

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
