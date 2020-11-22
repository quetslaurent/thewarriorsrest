#include "BattleView.h"

BattleView::BattleView(sf::RenderWindow* window)
{
    this->window=window;

    initMapTexture();//init map texture

    //health bars
    initHealthBars();

    //text during the battle
    initTextBattle();

    //enemy texture
    initEnemyTexture();

    //player texture
    initPlayerTexture();

    //choice texture
    initChoiceTexture();
}

BattleView::~BattleView()
{
    //dtor
}

void BattleView::drawHealthPlayer(int hp){

    this->playerHealth.setSize(sf::Vector2f(hp,20));

    this->window->draw(playerHealth);

}

//draw the enemy health bar on the screen
void BattleView::drawHealthEnemy(int hp){

    this->enemyHealth.setSize(sf::Vector2f(hp,20));

    this->window->draw(enemyHealth);

}

//draw text during the battle
void BattleView::drawBattleText(){
    //put the text in the center
    this->battleText.setPosition(sf::Vector2f(WINDOW_WIDTH/2.0f,WINDOW_HEIGHT/2.0f));
    sf::FloatRect textRect = battleText.getLocalBounds();
    this->battleText.setOrigin(textRect.left + textRect.width/2.0f,
               textRect.top  + textRect.height/2.0f);

    this->window->draw(battleText);
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

//reset player texture
void BattleView::resetPlayerTexture()
{
    playerSprite.setTextureRect(sf::IntRect(2200,0,1100,1100));
}

//draw background
void BattleView::drawBackground(){
    this->window->draw(mapSprite); // draw the background
}
//draw battlechoice
void BattleView::drawBattleChoice(){
    this->window->draw(choiceSprite); // draw the battle choice
}

//draw all
void BattleView::drawAll(const double enemy_hp,const double player_hp){

    drawBackground();//draw the background
    //draw the health bars
    drawHealthEnemy(enemy_hp);
    drawHealthPlayer(player_hp);

    //draw the text
    drawBattleText();
    //draw battleChoice
    drawBattleChoice();

    drawPlayerTexture();//draw the player
    drawEnemyTexture();//draw the enemy
    this->window->display();
}

//----------TEXTURES INITIALIZATION ------

//background image
void BattleView::initMapTexture()
{
    if(!this->mapTexture.loadFromFile("./image/battleground1.png")){
     EXIT_FAILURE;
    }

    this->mapSprite.setTexture(mapTexture);//set the map texture on the sprite for the background
}

//health bars
void BattleView::initHealthBars()
{
    this->playerHealth.setPosition(475,450);
    this->playerHealth.setFillColor(sf::Color(179, 47, 11));

    this->enemyHealth.setPosition(1270,450);
    this->enemyHealth.setFillColor(sf::Color(179, 47, 11));
}

//text during the battle
void BattleView::initTextBattle()
{
    if(!font.loadFromFile("./image/HunDIN1451.ttf")){

    }
    this->battleText.setFont(font);
    this->battleText.setCharacterSize(30);
    this->battleText.setString("Start Battle !");
    //put the text in the center
    this->battleText.setPosition(sf::Vector2f(WINDOW_WIDTH/2.0f,WINDOW_HEIGHT/2.0f));
    sf::FloatRect textRect = battleText.getLocalBounds();
    this->battleText.setOrigin(textRect.left + textRect.width/2.0f,
               textRect.top  + textRect.height/2.0f);
}

//enemy texture
void BattleView::initEnemyTexture()
{

    this->enemyTexture.loadFromFile("./image/enemyBattle.png");
    this->enemySprite.setTexture(enemyTexture);//set the enemy texture on the sprite
    this->enemySprite.setTextureRect(sf::IntRect(2200,0,1100,1100));
    this->enemySprite.setPosition(1200,450);
    this->enemySprite.setScale(
    250 / enemySprite.getLocalBounds().width,
    250 / enemySprite.getLocalBounds().height);
}

//player texture
void BattleView::initPlayerTexture()
{
    this->playerTexture.loadFromFile("./image/playerAnimation.png");
    this->playerSprite.setTexture(playerTexture);//set the player texture on the sprite
    this->playerSprite.setTextureRect(sf::IntRect(2200,0,1100,1100));
    this->playerSprite.setPosition(400,450);
    this->playerSprite.setScale(
    250 / playerSprite.getLocalBounds().width,
    250 / playerSprite.getLocalBounds().height);
}

//choice texture
void BattleView::initChoiceTexture()
{
    if(!this->choiceTexture.loadFromFile("./image/battlechoice.png")){
     EXIT_FAILURE;
    }
    this->choiceSprite.setPosition(sf::Vector2f(250,WINDOW_HEIGHT-200));
    this->choiceSprite.setTexture(choiceTexture);//set the choice texture on the sprite
}
