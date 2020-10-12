#include "GameState.h"

#include <iostream>
using std::cout;
GameState::GameState(sf::RenderWindow* window):State(window)
{
    //ctor
}

GameState::~GameState()
{
    //dtor
}

void GameState::update(const float& dt)
{
    std::cout<<"Test"<<"\n";
}

void GameState::render(sf::RenderTarget* target)
{

}

void GameState::endState()
{

}
