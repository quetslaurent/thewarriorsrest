#include "BattleState.h"

BattleState::BattleState(sf::RenderWindow* window,ViewController* viewController,std::vector<Hitbox*>* hitboxes):State(window)
{
    this->ableToFight = true;
    this->battleModel = new BattleModel(hitboxes);
    this->battleView = viewController->getBattleView();
    this->viewController=viewController;

}

BattleState::~BattleState()
{
    delete strategy;
    delete battleModel;
}


void BattleState::render()
{
    if(ableToFight){

        //draw the background, the health bars,the text,the player, the enemy
        battleView->drawAll(battleModel->getEnemyHp(),battleModel->getPlayerHp());

       //first attack
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            strategy = new DefaultAttack;
            battleModel->setPlayerStrategy(strategy);
            battleView->setBattleText("player   launch   "+strategy->toString()+"!!");
            ableToFight = false;
       }
       //second attack
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            strategy = new CriticalAttack;
            battleModel->setPlayerStrategy(strategy);
            battleView->setBattleText("player   launch   "+strategy->toString()+"!!");
            ableToFight = false;
       }
       //ultimate
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
            strategy = new UltimateAttack;
            battleModel->setPlayerStrategy(strategy);
            battleView->setBattleText("player   launch   "+strategy->toString()+"!!");
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

            if(battleModel->isWin()){
                viewController->setViewId(3);//change view to WinState
            }else{
                viewController->setViewId(0);//change view to BattleState
            }


        }else{
            //the enemy attacks the player
            AttackStrategy* strategy = battleModel->enemyAttacksPlayer();
            //change the battle text
            battleView->setBattleText("enemy   launch   "+strategy->toString()+"  !!");
            //set ableToFight to False, so the player cant attack
            ableToFight = false;

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
            viewController->setViewId(2); //change view to LooseState
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
