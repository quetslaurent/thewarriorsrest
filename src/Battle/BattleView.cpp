#include "BattleView.h"

BattleView::BattleView(sf::RenderWindow* window)
{
    this->window=window;

    //background image
    if(!this->mapTexture.loadFromFile("./image/battleground.png")){
     EXIT_FAILURE;
    }
    this->mapSprite.setTexture(mapTexture);//set the map texture on the sprite for the background

    //health bars
    this->playerHealth.setPosition(475,450);
    this->playerHealth.setFillColor(sf::Color(179, 47, 11));

    this->enemyHealth.setPosition(1270,450);
    this->enemyHealth.setFillColor(sf::Color(179, 47, 11));

    //text during the battle

    if(!font.loadFromFile("./image/HunDIN1451.ttf")){

    }
    this->battleText.setFont(font);
    this->battleText.setCharacterSize(50);
    this->battleText.setString("Start Battle !");
    this->battleText.setPosition(700,300);


    //enemy texture
    this->enemyTexture.loadFromFile("./image/enemyBattle.png");
    this->enemySprite.setTexture(enemyTexture);//set the enemy texture on the sprite
    this->enemySprite.setTextureRect(sf::IntRect(2200,0,1100,1100));
    this->enemySprite.setPosition(1200,450);
    this->enemySprite.setScale(
    250 / enemySprite.getLocalBounds().width,
    250 / enemySprite.getLocalBounds().height);

    //player texture

    this->playerTexture.loadFromFile("./image/playerAnimation.png");
    this->playerSprite.setTexture(playerTexture);//set the player texture on the sprite
    this->playerSprite.setTextureRect(sf::IntRect(2200,0,1100,1100));
    this->playerSprite.setPosition(400,450);
    this->playerSprite.setScale(
    250 / playerSprite.getLocalBounds().width,
    250 / playerSprite.getLocalBounds().height);

}

BattleView::~BattleView()
{
    //dtor
}

void BattleView::drawHealthPlayer(int hp){

    this->playerHealth.setSize(sf::Vector2f(hp,20));

    this->window->draw(enemyHealth);
    this->window->draw(playerHealth);
    this->window->display();
}

//draw the enemy health bar on the screen
void BattleView::drawHealthEnemy(int hp){

    this->enemyHealth.setSize(sf::Vector2f(hp,20));

    this->window->draw(mapSprite); // draw the background
    drawPlayerTexture();
    drawEnemyTexture();

    this->window->draw(playerHealth);
    this->window->draw(enemyHealth);
    this->window->display();
}

//draw text during the battle
void BattleView::drawBattleText(){
    this->window->draw(battleText);
    this->window->display();
}

//set the battle text
void BattleView::setBattleText(string text){
    battleText.setString(text);
}

//draw player texture
void BattleView::drawPlayerTexture(){
    this->window->draw(playerSprite);
}

//draw enemy texture
void BattleView::drawEnemyTexture(){
    this->window->draw(enemySprite);
}

//animation of the player
void BattleView::playerAttackAnimation(){
        //change the texture for the animation
        playerSprite.setTextureRect(sf::IntRect(0,2200,1100,1100));
        enemySprite.setTextureRect(sf::IntRect(2200,0,1100,1100));
}
//animation of the enemy
void BattleView::enemyAttackAnimation(){
    //change the texture for the animation
    playerSprite.setTextureRect(sf::IntRect(2200,0,1100,1100));
    enemySprite.setTextureRect(sf::IntRect(1100,0,1100,1100));
}

//reset enemy texture
void BattleView::resetEnemyTexture(){
    enemySprite.setTextureRect(sf::IntRect(2200,0,1100,1100));
}

//draw background
void BattleView::drawBackground(){
    this->window->draw(mapSprite); // draw the background
}
