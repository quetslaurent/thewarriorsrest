#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include<iostream>

#include "IDimensions.h"
#include "HitboxCollider.h"

class Entity : public IDimensions
{
    private:
        sf::RectangleShape playerHitbox; //player hitbox

        sf::RectangleShape player; //player texture

        HitboxCollider hitboxCollider;

        float movementSpeed;

        sf::Texture texture;

    public:
        Entity();
        virtual ~Entity();

    //functions
    void update(const float& dt);
    void render(sf::RenderTarget* target);

    void move(const float& dt,const float x,const float y); //move the playerHitbox
    sf::Vector2f getHitboxPosition()const; //get the position of the hitbox

    //texture
    void createTexture(); //initialisation of the texture

    HitboxCollider& getHitboxCollider();
    sf::RectangleShape& getPlayerHitbox();

};

#endif // ENTITY_H
