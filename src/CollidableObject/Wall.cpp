#include "Wall.h"

Wall::Wall(float posX,float posY,float width,float height):Hitbox(posX, posY, width, height)
{
}

Wall::~Wall()
{
    //dtor
}

void Wall::collide(sf::RectangleShape& playerHitbox){

    sf::FloatRect playerBounds = playerHitbox.getGlobalBounds();
    sf::FloatRect hitboxBounds = this->getHitbox().getGlobalBounds();

    //player informations
    int player_y = playerHitbox.getPosition().y;
    int player_left = playerBounds.left;
    int player_top = playerBounds.top;
    int player_height = playerBounds.height;
    int player_width = playerBounds.width;
    int player_bottom =player_top + player_height;
    int player_right = player_left + player_width;

    //hitbox informations
    int hitbox_height = hitboxBounds.height;
    int hitbox_top = hitboxBounds.top;
    int hitbox_left = hitboxBounds.left;
    int hitbox_width = hitboxBounds.width;
    int hitbox_right = hitbox_left + hitbox_width;
    int hitbox_bottom = hitbox_top + hitbox_height;

         //BOTTOM COLLISION
         //when the bottom side of the player collide with the top side of the collision

         if
         (player_y< hitbox_top
         && player_y + hitbox_height +(player_height-10) < hitbox_bottom
         && player_left < hitbox_right
         && player_right > hitbox_left)
         {
           playerHitbox.setPosition(player_left, hitbox_top - player_height);
         }

         //TOP COLLISION
         //when the top side of the player collide with the bottom side of the collision

         else if
         (player_y> hitbox_top
         && player_y + 10 > hitbox_bottom
         && player_left < hitbox_right
         && player_right > hitbox_left)
         {
            playerHitbox.setPosition(player_left, hitbox_bottom);
         }

        //RIGHT COLLISION
        //when the right side of the player collide with the left side of the collision
        else if
        (player_left < hitbox_left
        && player_right< hitbox_right
        && player_top < hitbox_bottom
        && player_bottom > hitbox_top)
        {
            playerHitbox.setPosition(hitbox_left - player_width, player_top);
        }

        //LEFT COLLISION
        //when the left side of the player collide with the right side of the collision
        else if
        (player_left > hitbox_left
        && player_right > hitbox_right
        && player_top < hitbox_bottom
        && player_bottom > hitbox_top)
        {
            playerHitbox.setPosition(hitbox_right, player_top);
        }
}
