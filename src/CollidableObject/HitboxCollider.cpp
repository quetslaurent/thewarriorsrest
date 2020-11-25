#include "HitboxCollider.h"

HitboxCollider::HitboxCollider(ViewController* viewController)
{
    this->viewController=viewController;
    this->hitboxInitialiser= new HitboxInitialiser();
}

HitboxCollider::~HitboxCollider()
{
    delete hitboxInitialiser;
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
    std::vector<Hitbox*> *listHitboxes= hitboxInitialiser->getHitboxes();

    //get the hitbox's player coordinates
    sf::FloatRect playerBounds = playerHitbox.getGlobalBounds();

    sf::FloatRect hitboxBounds;

    int counter=0;

    for(Hitbox* &collision :*listHitboxes){

            //get the hitbox coordinates from the lists
            hitboxBounds = collision->getHitbox().getGlobalBounds();

            //check if the hitboxes intersects
            if(hitboxBounds.intersects(playerBounds))
            {
                collision->collide(playerHitbox);
                //remove enemy from the map when collide
                if(dynamic_cast<Enemy*>(collision) != nullptr){
                        viewController->setViewId(1);
                        Hitbox* tmp=*(listHitboxes->begin()+counter);
                        hitboxInitialiser->getHitboxes()->erase(listHitboxes->begin() +counter);
                        delete tmp;
                }
            }
            counter++;
        }
}


//-----------------getters

HitboxInitialiser* HitboxCollider::getHitboxInitialiser()
{
    return hitboxInitialiser;
}

std::vector<Hitbox*>* HitboxCollider::getAllHitboxes()
{
    return getHitboxInitialiser()->getHitboxes();
}


