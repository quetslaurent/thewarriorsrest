#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include<iostream>

#include "IDimensions.h"
#include "HitboxCollider.h"
#include "EnumDirection.h"
#include "ViewController.h"

class Entity : public IDimensions
{
    private:
        sf::RectangleShape playerHitbox; //player hitbox

        HitboxCollider* hitboxCollider;

        float movementSpeed;

        EnumDirection playerDirection;

        ViewController* viewController;

    public:
        Entity(ViewController* viewController);
        virtual ~Entity();

        //functions
        void update(const float& dt);

        void move(const float& dt,const float x,const float y); //move the playerHitbox
        sf::Vector2f getHitboxPosition()const; //get the position of the hitbox


        //hitbox
        HitboxCollider& getHitboxCollider();
        sf::RectangleShape& getPlayerHitbox();
        std::vector<Hitbox*>* getAllHitboxes();

        //direction
        EnumDirection getDirection();

};

#endif // ENTITY_H
