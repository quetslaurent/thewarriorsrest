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
    drawHitbox(target);
}

//move the entity
void Entity::move(const float& dt,const float x,const float y)
{
    //the movement is calculated using the delta time and the movement speed
    this->playerHitbox.move(x* this->movementSpeed*dt,y * this->movementSpeed*dt);


    cout<<playerHitbox.getPosition().x<<" "<<playerHitbox.getPosition().y<<" "<<"\n";

    std::vector<Hitbox*> listHitboxes= hitbox.getHitboxes();

    for(Hitbox* &collision :listHitboxes){

            //get the hitbox's player coordinates
            sf::FloatRect playerBounds = playerHitbox.getGlobalBounds();
            //get the hitbox coordinates from the lists
            sf::FloatRect hitboxBounds = collision->getHitbox().getGlobalBounds();

            //check if the hitboxes intersects
            if(hitboxBounds.intersects(playerBounds))
            {
                collision->collide();

               //BOTTOM COLLISION
               //when the bottom side of the player collide with the top side of the collision

               if

               (playerHitbox.getPosition().y < hitboxBounds.top
               && playerHitbox.getPosition().y + hitboxBounds.height +(playerBounds.height-10) < hitboxBounds.top + hitboxBounds.height
               && playerBounds.left < hitboxBounds.left + hitboxBounds.width
               && playerBounds.left + playerBounds.width > hitboxBounds.left)

               {
                   playerHitbox.setPosition(playerBounds.left, hitboxBounds.top - playerBounds.height);
                   //cout<<"BOTTOM"<<"hitbox bottom: "<<hitboxBounds.top<<" HEIGHT: "<<hitboxBounds.height<<"\n";
                   cout<<"TOP-Player : "<<playerHitbox.getPosition().y<<" Bottom-player: "<<playerBounds.height <<" hitbox top: "<<hitboxBounds.top <<"HEIGHT: "<<hitboxBounds.height<<"\n";

               }

               //TOP COLLISION
               //when the top side of the player collide with the bottom side of the collision

               else if
               (playerHitbox.getPosition().y> hitboxBounds.top
               && playerHitbox.getPosition().y + 10 > hitboxBounds.top + hitboxBounds.height
               && playerBounds.left < hitboxBounds.left + hitboxBounds.width
               && playerBounds.left + playerBounds.width > hitboxBounds.left)
               {
                    playerHitbox.setPosition(playerBounds.left, hitboxBounds.top + hitboxBounds.height);
                    //cout<<"TOP-Player : "<<-playerBounds.top<<" Bottom-player: "<<-playerBounds.top-playerBounds.height <<" hitbox top: "<<hitboxBounds.top <<"HEIGHT: "<<hitboxBounds.height<<"\n";
                    cout<<"TOP-Player : "<<playerHitbox.getPosition().y<<" Bottom-player: "<<playerBounds.height <<" hitbox top: "<<hitboxBounds.top <<"HEIGHT: "<<hitboxBounds.height<<"\n";

               }

                //RIGHT COLLISION
                //when the right side of the player collide with the left side of the collision
                else if(playerBounds.left < hitboxBounds.left
                   && playerBounds.left + playerBounds.width < hitboxBounds.left + hitboxBounds.width
                   && playerBounds.top < hitboxBounds.top + hitboxBounds.height
                   && playerBounds.top + playerBounds.height > hitboxBounds.top)
                {
                    playerHitbox.setPosition(hitboxBounds.left - playerBounds.width, playerBounds.top);
                    //cout<<"RIGHT"<<"\n";
                }

                //LEFT COLLISION
                //when the left side of the player collide with the right side of the collision
                else
                if(playerBounds.left > hitboxBounds.left
                   && playerBounds.left + playerBounds.width > hitboxBounds.left + hitboxBounds.width
                   && playerBounds.top < hitboxBounds.top + hitboxBounds.height
                   && playerBounds.top + playerBounds.height > hitboxBounds.top)
                   {
                        playerHitbox.setPosition(hitboxBounds.left + hitboxBounds.width, playerBounds.top);
                        //cout<<"LEFT"<<"\n";
                   }
            }
        }
}


void Entity::createTexture()
{
 if(!this->texture.loadFromFile("./image/playerAnimation.png")){
     EXIT_FAILURE;
    }
    this->player.setTexture(&texture);
    this->player.setTextureRect(sf::IntRect(0,0,1100,1100));
}

sf::RectangleShape Entity::getHitbox(){
    return playerHitbox;
}


// show all the hitboxes, so we can debug
void Entity::drawHitbox(sf::RenderTarget* target){

//drawing of the player's hitbox
    sf::RectangleShape player = this->playerHitbox;
    player.setPosition( (WINDOW_WIDTH/2)-PLAYERHITBOX_WIDTH/2 , (WINDOW_HEIGHT/2)-PLAYERHITBOX_HEIGHT/2 );

//draw all the hitboxes of the map
std::vector<Hitbox*> listHitboxes= hitbox.getHitboxes();

for(Hitbox* &collision :listHitboxes){

             sf::RectangleShape hitboxdisplay = collision->getHitbox();

             hitboxdisplay.setPosition(hitboxdisplay.getPosition().x- (hitboxdisplay.getPosition().x*2),hitboxdisplay.getPosition().y- (hitboxdisplay.getPosition().y*2));

             hitboxdisplay.move((WINDOW_WIDTH/2)-PLAYERHITBOX_WIDTH/2 +playerHitbox.getPosition().x +PLAYERHITBOX_WIDTH, (WINDOW_HEIGHT/2)-PLAYERHITBOX_HEIGHT/2+playerHitbox.getPosition().y +PLAYERHITBOX_HEIGHT);

             hitboxdisplay.rotate(180);

             hitboxdisplay.setFillColor(sf::Color(100, hitboxdisplay.getPosition().x, 50));

             target->draw(hitboxdisplay);

    }

target->draw(player);
}



