#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include<vector>
//manage the resources
class State
{
    private:
        std::vector<sf::Texture> textures;

    public:
        State();
        virtual ~State();

};

#endif // STATE_H
