#ifndef WINSTATE_H
#define WINSTATE_H
#include "State.h"

class WinState:public State
{
     private:
        WinView* winView;
        ViewController* viewController;


    public:
        WinState(sf::RenderWindow* window,ViewController* ViewController);
        virtual ~WinState();

        //functions
        void updateKeybinds();
        void update(const float& dt);
        void render();
        void endState();

};

#endif // WINSTATE_H
