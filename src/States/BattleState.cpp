#include "BattleState.h"

BattleState::BattleState(sf::RenderWindow* window):State(window)
{
     //background image
    if(!this->mapTexture.loadFromFile("./image/battleground.png")){
     EXIT_FAILURE;
    }
    this->s.setTexture(mapTexture);//set the map texture on the sprite for the background

    this->ableToFight = true;

    //creation of the player and the enemy
    this->player = new Player(100);
    this->enemy = new EnemyBattle(100);

    //health bars
    this->playerHealth.setSize(sf::Vector2f(player->getHealth().getHpCurrent(),20));
    this->playerHealth.setPosition(475,450);
    this->playerHealth.setFillColor(sf::Color(179, 47, 11));

    this->enemyHealth.setSize(sf::Vector2f(enemy->getHealth().getHpCurrent(),20));
    this->enemyHealth.setPosition(1270,450);
    this->enemyHealth.setFillColor(sf::Color(179, 47, 11));
}

BattleState::~BattleState()
{
    //dtor
    delete player;
    delete enemy;
}


void BattleState::render()
{

}

void BattleState::update(const float& dt)
{
    this->updateKeybinds();  //check if the player pressed a specific key

   if(ableToFight){
        //draw the health bars
        drawHealthEnemy();
        drawHealthPlayer();
       //first attack
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            std::cout<<"FIRST ATTACK  : E "<<"\n";
            this->player->setStrategie(new DefaultAttack);
            ableToFight = false;
       }
       //second attack
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            std::cout<<"SECOND ATTACK  : R "<<"\n";
            this->player->setStrategie(new CriticalAttack);
            ableToFight = false;
       }
       //ultimate
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
            std::cout<<"ULTIMATE : T "<<"\n";
            this->player->setStrategie(new UltimateAttack);
            ableToFight = false;
       }
       if(!ableToFight) {
            //the player and the enemy fights

            this->getWindow()->draw(s); // draw the background
            this->player->render(getWindow()); //draw the player
            this->enemy->render(getWindow()); //draw the enemy

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

        this->player->attack(this->enemy);
        //change the texture for the animation
        this->player->getSprite().setTextureRect(sf::IntRect(0,2200,1100,1100));
        this->enemy->getSprite().setTextureRect(sf::IntRect(2200,0,1100,1100));

        drawHealthEnemy();
        drawHealthPlayer();
        //wait Xs
        sleep();
        //the enemy attacks the player
        enemyTurn();
        //change the texture for the animation
        this->player->getSprite().setTextureRect(sf::IntRect(2200,0,1100,1100));
        this->enemy->getSprite().setTextureRect(sf::IntRect(1100,0,1100,1100));
        drawHealthEnemy();
        drawHealthPlayer();

        //set the initial texture for the enemy
        sleep();
        this->enemy->getSprite().setTextureRect(sf::IntRect(2200,0,1100,1100));

        drawHealthEnemy();
        drawHealthPlayer();


        //if the player is dead
        if(!this->player->getHealth().isAlive()){
            StateManager::stateId = 0; //change view to BattleState
        }
        //if the player win
        if(!this->enemy->getHealth().isAlive()){
            StateManager::stateId = 0;//change view to BattleState
        }

       //set the possibility to choose a new attack to 'true'
       ableToFight=true;
}

void BattleState::enemyTurn(){
    //the enemy attacks the player
        this->enemy->attack(this->player);
}

//draw the player health bar on the screen
void BattleState::drawHealthPlayer(){

    this->playerHealth.setSize(sf::Vector2f(player->getHealth().getHpCurrent(),20));

    this->getWindow()->draw(enemyHealth);
    this->getWindow()->draw(playerHealth);
    this->getWindow()->display();
}

//draw the enemy health bar on the screen
void BattleState::drawHealthEnemy(){

    this->enemyHealth.setSize(sf::Vector2f(enemy->getHealth().getHpCurrent(),20));

    this->getWindow()->draw(s); // draw the background
    this->player->render(getWindow()); //draw the player
    this->enemy->render(getWindow()); //draw the enemy

    this->getWindow()->draw(playerHealth);
    this->getWindow()->draw(enemyHealth);
    this->getWindow()->display();
}

void BattleState::sleep(){
    std::this_thread::sleep_for(1500ms);
}


//end of BattleState
void BattleState::endState()
{
    std::cout<<"END of BattleState"<<"\n";
}
