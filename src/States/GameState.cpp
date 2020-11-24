#include "GameState.h"

#include <iostream>
using std::cout;
GameState::GameState(sf::RenderWindow* window,ViewController* viewController):State(window)
{
    this->gameModel = new GameModel();
    this->gameView = viewController->getGameView();
    this->viewController=viewController;
    this->player= new Entity(viewController);

    //debug = false -> dont show the hitbox on the map
    //debug = true -> show the hitbox on the map
    this->debug=false;
}

GameState::~GameState()
{
    delete gameModel;
    delete player;
}

void GameState::update(const float& dt)
{
   this->updateKeybinds();  //check if the player pressed a specific key

   this->player->update(dt); //update and move the player
}

void GameState::render()
{
    //draw the background
    this->gameView->drawBackground(this->player->getHitboxPosition());
    //draw the player
    this->gameView->drawPlayer(this->player->getDirection());

    //draw enemies
    this->gameView->drawEnemies(*this->player->getAllHitboxes(),this->player->getPlayerHitbox());

    // show all the hitboxes, so we can debug
    if(debug){
       this->gameView->drawHitboxes(*this->player->getAllHitboxes(),this->player->getPlayerHitbox());
    }
}

void GameState::updateKeybinds()
{
    this->checkForQuit();   //check if the user pressed the "esc" key
}


//end of gameState
void GameState::endState()
{
    std::cout<<"END of gameState"<<"\n";
}

