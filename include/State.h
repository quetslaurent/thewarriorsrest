#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include<stack>
#include<map>

#include<vector>
//manage the resources
class State
{
    private:
        sf::RenderWindow* window;
        std::vector<sf::Texture> textures;

    public:
        State(sf::RenderWindow* window);
        virtual ~State();

        virtual void endState() =0;
        virtual void update(const float& dt) = 0;
        virtual void render(sf::RenderTarget* target = nullptr)=0;

};

#endif // STATE_H
