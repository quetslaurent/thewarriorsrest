#include "BattleState.h"

BattleState::BattleState(sf::RenderWindow* window,ViewController* viewController):State(window)
{
    this->ableToFight = true;
    battleModel = new BattleModel();
    this->battleView = viewController->getBattleView();
    this->viewController=viewController;
}

BattleState::~BattleState()
{
    delete battleModel;
}


void BattleState::render()
{
    if(ableToFight){
        //draw the background, the health bars,the text,the player, the enemy
        battleView->drawAll(battleModel->getEnemyHp(),battleModel->getPlayerHp());

       //first attack
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            battleModel->setPlayerStrategy(new DefaultAttack);
            battleView->setBattleText("player   launch   quick-attack  !");
            ableToFight = false;
       }
       //second attack
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            battleModel->setPlayerStrategy(new CriticalAttack);
            battleView->setBattleText("player   launch   dizzy-punch  !");
            ableToFight = false;
       }
       //ultimate
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
            battleModel->setPlayerStrategy(new UltimateAttack);
            battleView->setBattleText("player   launch   double-edge  !!");
            ableToFight = false;
       }

       if(!ableToFight) {
            //the player and the enemy fights
            makeRound();
       }
   }
}

void BattleState::update(const float& dt)
{
    this->updateKeybinds();  //check if the player pressed a specific key
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

        //draw the background, the health bars,the text,the player, the enemy
        battleView->drawAll(battleModel->getEnemyHp(),battleModel->getPlayerHp());
        //wait Xs
        sleep();

        //if the player win
        if(!battleModel->isEnemyAlive()){
            battleModel->initFighters();
            battleView->setBattleText("Start Battle !");
            battleView->resetEnemyTexture();
            battleView->resetPlayerTexture();
            viewController->setViewId(0);//change view to BattleState
        }else{
            //the enemy attacks the player
            AttackStrategy* strategy = battleModel->enemyAttacksPlayer();

            if(dynamic_cast<DefaultAttack*>(strategy) != nullptr){
            battleView->setBattleText("enemy   launch   quick-attack  !");
            ableToFight = false;
            }
           //second attack
           if(dynamic_cast<CriticalAttack*>(strategy) != nullptr){
                battleView->setBattleText("enemy   launch   dizzy-punch  !");
                ableToFight = false;
           }
           //ultimate
           if(dynamic_cast<UltimateAttack*>(strategy) != nullptr){
                battleView->setBattleText("enemy   launch   double-edge  !!");
                ableToFight = false;
           }

            battleView->enemyAttackAnimation();//enemy animation

            //draw the background, the health bars,the text,the player, the enemy
            battleView->drawAll(battleModel->getEnemyHp(),battleModel->getPlayerHp());

            //set the initial texture for the enemy
            sleep();
            battleView->resetEnemyTexture();//reset the enemy texture

            //draw the background, the health bars,the text,the player, the enemy
            battleView->drawAll(battleModel->getEnemyHp(),battleModel->getPlayerHp());
        }

        //if the player is dead
        if(!battleModel->isPlayerAlive()){
            battleModel->initFighters();
            battleView->setBattleText("Start Battle !");
            battleView->resetEnemyTexture();
            battleView->resetPlayerTexture();
            viewController->setViewId(0); //change view to BattleState
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
