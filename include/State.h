#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include "IDimensions.h"

#include <iostream>
using std::cout;
//manage the resources
class State : public IDimensions
{
    private:
        sf::RenderWindow* window;
        std::vector<sf::Texture> textures;
        bool quit;

    public:
        State(sf::RenderWindow* window);
        virtual ~State();

        const bool& getQuit()const;
        sf::RenderWindow* getWindow()const;

        virtual void checkForQuit();
        virtual void endState()=0;

        virtual void updateKeybinds()=0;
        virtual void update(const float& dt) = 0;
        virtual void render()=0;


};

#endif // STATE_H
