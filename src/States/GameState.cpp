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
   this->updateKeybinds();  //check if the player pressed a specific key

   this->player.update(dt); //update and move the player
}

void GameState::render(sf::RenderTarget* target)
{
    this->player.render(this->getWindow()); // draw the player
}

void GameState::updateKeybinds()
{
    this->checkForQuit();   //check if the user pressed the "esc" key
}


Entity GameState::getPlayer()
{
    return player;
}

//end of gameState
void GameState::endState()
{
    std::cout<<"END of gameState"<<"\n";
}

