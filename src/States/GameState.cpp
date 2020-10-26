#include "GameState.h"

#include <iostream>
using std::cout;
GameState::GameState(sf::RenderWindow* window):State(window)
{

}

GameState::~GameState()
{
    //dtor
}

void GameState::update(const float& dt)
{
   this->updateKeybinds(dt);

   this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    this->player.render(this->window);
}

void GameState::updateKeybinds(const float& dt)
{
    this->checkForQuit();
}

//end of gameState
void GameState::endState()
{
    std::cout<<"END of gameState"<<"\n";
}

