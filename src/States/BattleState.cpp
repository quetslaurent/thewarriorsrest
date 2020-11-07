#include "BattleState.h"

BattleState::BattleState(sf::RenderWindow* window):State(window)
{
     //background image
    if(!this->mapTexture.loadFromFile("./image/battleground.png")){
     EXIT_FAILURE;
    }

    this->s.setTexture(mapTexture);//set the map texture on the sprite for the background

    PlayerTurn* playerTurn = new PlayerTurn();

    setTurnState(playerTurn);
}

BattleState::~BattleState()
{
    //dtor
//    delete playerTurn;
}


void BattleState::render()
{
    this->getWindow()->draw(s); // draw the background
}

void BattleState::update(const float& dt)
{
    this->updateKeybinds();  //check if the player pressed a specific key

    this->turnState->attack();

    /*
   if(ableToFight){
       //first attack
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            std::cout<<"FIRST ATTACK  : A "<<"\n";
            ableToFight = false;
       }
       //second attack
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            std::cout<<"SECOND ATTACK  : Z "<<"\n";
            ableToFight = false;
       }
       //heal
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            std::cout<<"HEAL  : E "<<"\n";
            ableToFight = false;
       }
       //ultimate
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            std::cout<<"ULTIMATE : R "<<"\n";
            ableToFight = false;
       }
   }*/
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

void BattleState::setTurnState(TurnState* turnState)
{
    this->turnState = turnState;
}
