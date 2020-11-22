#include "HitboxCollider.h"

HitboxCollider::HitboxCollider()
{
        this->hitboxInitialiser= HitboxInitialiser();
        //this->enemyTexture.loadFromFile("./image/enemyAnimation.png");
}

HitboxCollider::~HitboxCollider()
{
}

HitboxCollider::HitboxCollider(const HitboxCollider& other)
{
    //copy ctor
}

HitboxCollider& HitboxCollider::operator=(const HitboxCollider& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

//check if the player hits an hitbox
void HitboxCollider::collide(sf::RectangleShape& playerHitbox){

    //get all the hitboxes of the map
    std::vector<Hitbox*> listHitboxes= hitboxInitialiser.getHitboxes();

    //get the hitbox's player coordinates
    sf::FloatRect playerBounds = playerHitbox.getGlobalBounds();

    sf::FloatRect hitboxBounds;

    for(Hitbox* &collision :listHitboxes){

            //get the hitbox coordinates from the lists
            hitboxBounds = collision->getHitbox().getGlobalBounds();

            //check if the hitboxes intersects
            if(hitboxBounds.intersects(playerBounds))
            {
                collision->collide(playerHitbox);
            }
        }
}


//-----------------getters

HitboxInitialiser HitboxCollider::getHitboxInitialiser()
{
    return hitboxInitialiser;
}

std::vector<Hitbox*> HitboxCollider::getAllHitboxes()
{
    return getHitboxInitialiser().getHitboxes();
}

