#include "Player.h"

Player::Player():Character()
{
    this->playerTexture.loadFromFile("./image/playerAnimation.png");
    this->playerSprite.setTexture(playerTexture);//set the player texture on the sprite
    this->playerSprite.setTextureRect(sf::IntRect(2200,0,1100,1100));
    this->playerSprite.setPosition(400,450);
    this->playerSprite.setScale(
    150 / playerSprite.getLocalBounds().width,
    150 / playerSprite.getLocalBounds().height);
}

Player::Player(Health health):Character(health)
{
    this->playerTexture.loadFromFile("./image/playerAnimation.png");
    this->playerSprite.setTexture(playerTexture);//set the player texture on the sprite
    this->playerSprite.setTextureRect(sf::IntRect(2200,0,1100,1100));
    this->playerSprite.setPosition(400,450);
    this->playerSprite.setScale(
    250 / playerSprite.getLocalBounds().width,
    250 / playerSprite.getLocalBounds().height);
}

Player::~Player()
{

}

void Player::attack(Character* c){
     Character::attack(c);
}

void Player::receiveDamage(double damage){
    Character::receiveDamage(damage);
}

void Player::setStrategie(AttackStrategy* strategy){
    Character::setStrategie(strategy);
}

void Player::render(sf::RenderWindow* window){
    window->draw(this->playerSprite);
}

sf::Sprite& Player::getSprite(){
    return playerSprite;
}

