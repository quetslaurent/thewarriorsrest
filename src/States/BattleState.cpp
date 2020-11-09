#include "BattleState.h"

BattleState::BattleState(sf::RenderWindow* window):State(window)
{
    this->ableToFight = true;
    battleModel = new BattleModel();
    battleView = new BattleView(window);
}

BattleState::~BattleState()
{
    delete battleModel;
    delete battleView;
}


void BattleState::render()
{
}

void BattleState::update(const float& dt)
{
    this->updateKeybinds();  //check if the player pressed a specific key

   if(ableToFight){
        //draw the health bars
        battleView->drawHealthEnemy(battleModel->getEnemyHp());
        battleView->drawHealthPlayer(battleModel->getPlayerHp());

        //draw the text
        battleView->drawBattleText();

       //first attack
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            battleModel->setPlayerStrategy(new DefaultAttack);
            battleView->setBattleText("Player launch QUICK ATTACK");
            ableToFight = false;
       }
       //second attack
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            battleModel->setPlayerStrategy(new CriticalAttack);
            battleView->setBattleText("Player launch DIZZY PUNCH");
            ableToFight = false;
       }
       //ultimate
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
            battleModel->setPlayerStrategy(new UltimateAttack);
            battleView->setBattleText("Player launch DOUBLE-EDGE");
            ableToFight = false;
       }

       if(!ableToFight) {
            battleView->drawBackground();//draw the background
            battleView->drawPlayerTexture();//draw the player
            battleView->drawEnemyTexture();//draw the enemy
            //the player and the enemy fights
            makeRound();
       }
   }
}

void BattleState::updateKeybinds()
{
    this->checkForQuit();   //check if the user pressed the "esc" key
}

//the player and the enemy fights

void BattleState::makeRound(){

        //the player attacks the enemy
        battleModel->playerAttacksEnemy();

        battleView->playerAttackAnimation();

        battleView->drawHealthEnemy(battleModel->getEnemyHp());
        battleView->drawHealthPlayer(battleModel->getPlayerHp());
        //wait Xs
        sleep();
        //the enemy attacks the player
        battleModel->enemyAttacksPlayer();

        battleView->enemyAttackAnimation();

        battleView->drawHealthEnemy(battleModel->getEnemyHp());
        battleView->drawHealthPlayer(battleModel->getPlayerHp());

        //set the initial texture for the enemy
        sleep();
        battleView->resetEnemyTexture();

        battleView->drawHealthEnemy(battleModel->getEnemyHp());
        battleView->drawHealthPlayer(battleModel->getPlayerHp());

        //if the player is dead
        if(!battleModel->isPlayerAlive()){
            StateManager::stateId = 0; //change view to BattleState
        }
        //if the player win
        if(!battleModel->isEnemyAlive()){
            StateManager::stateId = 0;//change view to BattleState
        }

       //set the possibility to choose a new attack to 'true'
       ableToFight=true;
}


void BattleState::sleep(){
    std::this_thread::sleep_for(1500ms);
}

//end of BattleState
void BattleState::endState()
{
    std::cout<<"END of BattleState"<<"\n";
}
