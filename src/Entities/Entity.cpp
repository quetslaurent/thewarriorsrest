#include "Entity.h"

Entity::Entity()
{
    this->hitbox.setSize(sf::Vector2f(120.f,120.f));
    this->movementSpeed=150.F;

    createTexture();

}

Entity::~Entity()
{
    //dtor
}

void Entity::update(const float& dt)
{
    //left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->move(dt,-1.f,0.f);
        this->hitbox.setTextureRect(sf::IntRect(1100,0,1100,1100));
    }
    //right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->move(dt,1.f,0.f);
        this->hitbox.setTextureRect(sf::IntRect(2200,0,1100,1100));
    }

    //up
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->move(dt,0.f,-1.f);
        this->hitbox.setTextureRect(sf::IntRect(0,1100,1100,1100));
    }

    //down
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->move(dt,0.f,1.f);
        this->hitbox.setTextureRect(sf::IntRect(0,0,1100,1100));
    }

}

void Entity::render(sf::RenderTarget* target)
{
    target->draw(this->hitbox);
}

//move the entity
void Entity::move(const float& dt,const float x,const float y)
{
    //the movement is calculated using the delta time and the movement speed
    this->hitbox.move(x* this->movementSpeed*dt,y * this->movementSpeed*dt);
}


void Entity::createTexture()
{
 if(!this->texture.loadFromFile("./image/playerAnimation.png")){
     EXIT_FAILURE;
    }
    this->hitbox.setTexture(&texture);
    this->hitbox.setTextureRect(sf::IntRect(0,0,1100,1100));
}
