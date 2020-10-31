#include "Hitbox.h"

Hitbox::Hitbox(float posX,float posY,float width,float height)
{
    this->hitbox.setSize(sf::Vector2f(width,height));
    this->hitbox.setPosition(posX,posY);
}

Hitbox::~Hitbox()
{
    //dtor
}

Hitbox::Hitbox(const Hitbox& other)
{
    //copy ctor
}

Hitbox& Hitbox::operator=(const Hitbox& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Hitbox::collide(){
    cout<<"COLLISION"<<"\n";
}

sf::RectangleShape Hitbox::getHitbox()const{
    return hitbox;
}
