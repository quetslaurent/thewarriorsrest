#ifndef STATE_H
#define STATE_H

#include "Entity.h"
//manage the resources
class State
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
        virtual void render(sf::RenderTarget* target = nullptr)=0;

        virtual Entity getPlayer()=0;

};

#endif // STATE_H
