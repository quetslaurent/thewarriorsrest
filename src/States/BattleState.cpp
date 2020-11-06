#include "BattleState.h"

BattleState::BattleState(sf::RenderWindow* window):State(window)
{
     //background image
    if(!this->mapTexture.loadFromFile("./image/battleground.png")){
     EXIT_FAILURE;
    }

    this->s.setTexture(mapTexture);//set the map texture on the sprite for the background
}

BattleState::~BattleState()
{
    //dtor
}


void BattleState::render()
{
    //draw the background
    this->getWindow()->draw(s); // draw the background
}

void BattleState::update(const float& dt)
{
   this->updateKeybinds();  //check if the player pressed a specific key
}

void BattleState::updateKeybinds()
{
    this->checkForQuit();   //check if the user pressed the "esc" key
}


//end of BattleState
void BattleState::endState()
{
    std::cout<<"END of BattleState"<<"\n";
}
