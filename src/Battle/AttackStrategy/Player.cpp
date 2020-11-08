#include "Player.h"

Player::Player():Character()
{

}

Player::Player(Health health):Character(health)
{

}

Player::~Player()
{

}

void Player::attack(Character* p){
     Character::attack(p);
}

void Player::receiveDamage(double damage){
    Character::receiveDamage(damage);
}

void Player::setStrategie(AttackStrategy* strategy){
    Character::setStrategie(strategy);
}
