#include "State.h"

State::State(sf::RenderWindow* window)
{
    this->window=window;
    this->quit=false;
}

State::~State()
{

    //dtor
}

void State::checkForQuit()
{
    //if the user pressed the esc key
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->quit=true;    //then set the quit boolean to true
    }
}

const bool & State::getQuit() const
{
    return this->quit;
}

sf::RenderWindow* State::getWindow()const
{
    return this->window;
}



