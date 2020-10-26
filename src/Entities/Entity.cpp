#include "Entity.h"

#include<iostream>
#include <string>
using std::cout;
using std::to_string;
Entity::Entity()
{
    this->hitbox.setSize(sf::Vector2f(120.f,120.f));//the player's hitbox

    //this->hitbox.setPosition(-433,-1274);
    //this->hitbox.setPosition(540,470);
    this->hitbox.setPosition(0,0);

    this->hitbox.setFillColor(sf::Color(100, 250, 50));

    this->player.setSize(sf::Vector2f(120.f,120.f));//the player's texture
    this->player.setPosition(540,470);//put the player in the center
    //this->player.setPosition(0,0);
    this->movementSpeed=150.F;

    createTexture();

}

Entity::~Entity()
{
    //dtor
}

void Entity::update(const float& dt)
{
    //right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->move(dt,-1.f,0.f);
        //this->hitbox.setTextureRect(sf::IntRect(1100,0,1100,1100));
        this->player.setTextureRect(sf::IntRect(2200,0,1100,1100));

    }
    //left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->move(dt,1.f,0.f);
        //this->hitbox.setTextureRect(sf::IntRect(2200,0,1100,1100));
        this->player.setTextureRect(sf::IntRect(1100,0,1100,1100));
    }

    //down
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->move(dt,0.f,-1.f);
        //this->hitbox.setTextureRect(sf::IntRect(0,1100,1100,1100));
        this->player.setTextureRect(sf::IntRect(0,0,1100,1100));
    }

    //up
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->move(dt,0.f,1.f);
        /*this->hitbox.setTextureRect(sf::IntRect(0,0,1100,1100));*/

        this->player.setTextureRect(sf::IntRect(0,1100,1100,1100));
    }

}

void Entity::render(sf::RenderTarget* target)
{
    //target->draw(this->hitbox);
    target->draw(this->player);
}

//move the entity
void Entity::move(const float& dt,const float x,const float y)
{
    //the movement is calculated using the delta time and the movement speed
    this->hitbox.move(x* this->movementSpeed*dt,y * this->movementSpeed*dt);


    cout<<hitbox.getPosition().x<<" "<<hitbox.getPosition().y<<" "<<"\n";
    if(this->hitbox.getPosition().x < 100 && this->hitbox.getPosition().x > -100 && this->hitbox.getPosition().y <100 && this->hitbox.getPosition().y > -100 ){
        cout<<"TOUCHE LE SPAWN"<<"\n";
    }

}


void Entity::createTexture()
{
 if(!this->texture.loadFromFile("./image/playerAnimation.png")){
     EXIT_FAILURE;
    }
    /*this->hitbox.setTexture(&texture);
    this->hitbox.setTextureRect(sf::IntRect(0,0,1100,1100))*/
    //this->hitbox.setPosition(-433,-1274);

    this->player.setTexture(&texture);
    this->player.setTextureRect(sf::IntRect(0,0,1100,1100));
}



