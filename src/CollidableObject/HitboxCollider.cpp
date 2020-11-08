#include "HitboxCollider.h"

HitboxCollider::HitboxCollider()
{
        this->hitboxInitialiser= HitboxInitialiser();
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

//draw the hitbox on the screen, so we can debug
void HitboxCollider::drawHitbox(sf::RenderWindow* target,sf::RectangleShape& playerHitbox){

    //pick all the hitboxes of the map
    std::vector<Hitbox*> listHitboxes= hitboxInitialiser.getHitboxes();

    for(Hitbox* &collision :listHitboxes){

             //get the RectangleShape from the Hitbox class
             sf::RectangleShape hitboxdisplay = collision->getHitbox();

             //modify the position , so the hitbox is at the good place on the screen
             hitboxdisplay.setPosition(hitboxdisplay.getPosition().x- (hitboxdisplay.getPosition().x*2),hitboxdisplay.getPosition().y- (hitboxdisplay.getPosition().y*2));

             hitboxdisplay.move((WINDOW_WIDTH/2)-PLAYERHITBOX_WIDTH/2 +playerHitbox.getPosition().x +PLAYERHITBOX_WIDTH, (WINDOW_HEIGHT/2)-PLAYERHITBOX_HEIGHT/2+playerHitbox.getPosition().y +PLAYERHITBOX_HEIGHT);

             hitboxdisplay.rotate(180);

             //set a "random" color
             hitboxdisplay.setFillColor(sf::Color(100, hitboxdisplay.getPosition().x, 50));
             //draw the hitbox
             target->draw(hitboxdisplay);

    }
        //draw the player hitbox
        sf::RectangleShape player = playerHitbox;
        player.setPosition( (WINDOW_WIDTH/2)-PLAYERHITBOX_WIDTH/2 , (WINDOW_HEIGHT/2)-PLAYERHITBOX_HEIGHT/2 );
        target->draw(player);
}

void HitboxCollider::drawEnemies(sf::RenderWindow* target,sf::RectangleShape& playerHitbox){

    std::vector<Hitbox*> listHitboxes= hitboxInitialiser.getHitboxes();

    for(Hitbox* &collision :listHitboxes){
            if( dynamic_cast<Enemy*>(collision) != nullptr){

                 //get the RectangleShape from the Hitbox class
                 sf::RectangleShape hitboxdisplay = collision->getHitbox();

                 //modify the position , so the hitbox is at the good place on the screen
                 hitboxdisplay.setPosition(hitboxdisplay.getPosition().x- (hitboxdisplay.getPosition().x*2),hitboxdisplay.getPosition().y- (hitboxdisplay.getPosition().y*2));

                 hitboxdisplay.move((WINDOW_WIDTH/2)-PLAYERHITBOX_WIDTH/2 +playerHitbox.getPosition().x +PLAYERHITBOX_WIDTH, (WINDOW_HEIGHT/2)-PLAYERHITBOX_HEIGHT/2+playerHitbox.getPosition().y +PLAYERHITBOX_HEIGHT);

                 hitboxdisplay.rotate(180);

                 //draw the hitbox
                 target->draw(hitboxdisplay);
            }
    }

}

