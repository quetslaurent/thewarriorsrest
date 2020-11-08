#include "BattleState.h"

BattleState::BattleState(sf::RenderWindow* window):State(window)
{
     //background image
    if(!this->mapTexture.loadFromFile("./image/battleground.png")){
     EXIT_FAILURE;
    }

    this->s.setTexture(mapTexture);//set the map texture on the sprite for the background

    this->ableToFight = true;

    this->player = new Player(200);
    this->enemy = new EnemyBattle(100);
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


   if(ableToFight){
       //first attack
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            std::cout<<"FIRST ATTACK  : A "<<"\n";
            //this->player->setStrategie(new DefaultAttack);
            ableToFight = false;
       }
       //second attack
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            std::cout<<"SECOND ATTACK  : Z "<<"\n";
            //this->player->setStrategie(new CriticalAttack);
            ableToFight = false;
       }
       //ultimate
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
            std::cout<<"ULTIMATE : R "<<"\n";
            //this->player->setStrategie(new UltimateAttack);
            ableToFight = false;
       }
//       if(!ableToFight) {
//        this->player->attack(this->enemy);
//        this->enemy->attack(this->player);
//       }
        ableToFight=true;
   }
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
