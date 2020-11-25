#ifndef LOOSESTATE_H
#define LOOSESTATE_H
#include "State.h"

class LooseState:public State
{
    private:
        LooseView* looseView;
        ViewController* viewController;

    public:
        LooseState(sf::RenderWindow* window,ViewController* ViewController);
        virtual ~LooseState();

        //functions
        void updateKeybinds();
        void update(const float& dt);
        void render();
        void endState();


};


#endif // LOOSESTATE_H
