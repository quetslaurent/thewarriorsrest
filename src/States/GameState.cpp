#include "GameState.h"

#include <iostream>
using std::cout;
GameState::GameState(sf::RenderWindow* window):State(window)
{

    //background image
    if(!this->mapTexture.loadFromFile("./image/map.png")){
     EXIT_FAILURE;
    }

    this->s.setTexture(mapTexture);//set the map texture on the sprite for the background

    //debug = false -> dont show the hitbox on the map
    //debug = true -> show the hitbox on the map
    this->debug=false;
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

void GameState::render()
{
    //draw the background
    position = player.getHitboxPosition();//get the player position
    s.setPosition(position.x-START_X,position.y-START_Y);  //move the background depending on the player position,the 490 and 1350 numbers are for set the start position

    this->getWindow()->draw(s); // draw the background

    this->player.render(this->getWindow()); // draw the player

    this->player.getHitboxCollider().drawEnemies(this->getWindow(),this->player.getPlayerHitbox());

    if(debug){
       this->player.getHitboxCollider().drawHitbox(this->getWindow(),this->player.getPlayerHitbox());  // show all the hitboxes, so we can debug
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

