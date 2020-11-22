#include "Entity.h"

#include<iostream>
#include <string>
using std::cout;
using std::to_string;
Entity::Entity()
{
    this->playerHitbox.setSize(sf::Vector2f(PLAYERHITBOX_WIDTH,PLAYERHITBOX_HEIGHT));//the player's hitbox

    this->playerHitbox.setPosition(0,0);

    this->playerHitbox.setFillColor(sf::Color(100, 250, 50));

    this->movementSpeed=250.F;

}

Entity::~Entity()
{
}

//check if a key is pushed and move the player
void Entity::update(const float& dt)
{
    //right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->move(dt,-1.f,0.f);
        playerDirection=EnumDirection::E;
    }
    //left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->move(dt,1.f,0.f);
        playerDirection=EnumDirection::W;
    }

    //down
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->move(dt,0.f,-1.f);
        playerDirection=EnumDirection::S;
    }

    //up
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->move(dt,0.f,1.f);
        playerDirection=EnumDirection::N;
    }

}



//move the entity
void Entity::move(const float& dt,const float x,const float y)
{
    //move the playerHitbox
    //the movement is calculated using the delta time and the movement speed
    this->playerHitbox.move(x* this->movementSpeed*dt,y * this->movementSpeed*dt);

    cout<<playerHitbox.getPosition().x<<" "<<playerHitbox.getPosition().y<<" "<<"\n";

    //check if the playerHitbox hits a hitbox
    hitboxCollider.collide(playerHitbox);
}


//get the position of the hitbox
sf::Vector2f Entity::getHitboxPosition()const{
    return playerHitbox.getPosition();
}

//getters

HitboxCollider& Entity::getHitboxCollider(){

    return hitboxCollider;
}

sf::RectangleShape&  Entity::getPlayerHitbox(){
    return playerHitbox;
}

EnumDirection Entity::getDirection()
{
    return playerDirection;
}

std::vector<Hitbox*> Entity::getAllHitboxes()
{
    return hitboxCollider.getAllHitboxes();
}


