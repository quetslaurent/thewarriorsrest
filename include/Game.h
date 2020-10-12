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

    public:
        Game();
        virtual ~Game();

        //fonctions
        void updateSFMLEvents();
        void update();
        void render();
        void run();

        void updateDt();

};

#endif // GAME_H
