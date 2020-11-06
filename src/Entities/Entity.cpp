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

    this->player.setSize(sf::Vector2f(120.f,120.f));//the player's texture
    this->player.setPosition((WINDOW_WIDTH/2)-PLAYERHITBOX_WIDTH, (WINDOW_HEIGHT/2)-PLAYERHITBOX_HEIGHT);//put the player in the center of the screen
    this->movementSpeed=150.F;


    //set a texture
    createTexture();

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
        this->player.setTextureRect(sf::IntRect(2200,0,1100,1100));

    }
    //left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->move(dt,1.f,0.f);
        this->player.setTextureRect(sf::IntRect(1100,0,1100,1100));
    }

    //down
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->move(dt,0.f,-1.f);
        this->player.setTextureRect(sf::IntRect(0,0,1100,1100));
    }

    //up
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->move(dt,0.f,1.f);

        this->player.setTextureRect(sf::IntRect(0,1100,1100,1100));
    }

}

void Entity::render(sf::RenderTarget* target)
{
    target->draw(this->player);

    drawHitbox(target);//show the hitboxes on the map
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

//set the texture to the player
void Entity::createTexture()
{
 if(!this->texture.loadFromFile("./image/playerAnimation.png")){
     EXIT_FAILURE;
    }
    this->player.setTexture(&texture);
    this->player.setTextureRect(sf::IntRect(0,0,1100,1100));
}

//get the position of the hitbox
sf::Vector2f Entity::getHitboxPosition()const{
    return playerHitbox.getPosition();
}

// show all the hitboxes, so we can debug
void Entity::drawHitbox(sf::RenderTarget* target){
  hitboxCollider.drawHitbox(target, playerHitbox);
}



