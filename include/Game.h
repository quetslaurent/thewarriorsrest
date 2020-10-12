#ifndef GAME_H
#define GAME_H

#include "State.h"

class Game
{
    private:
        //variables
        sf::RenderWindow *wGame;     //main window
        sf::Event sfEvent;

        sf::Clock dtClock;
        float dt;   //delta time

        //initialization
        void initWindow();

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
