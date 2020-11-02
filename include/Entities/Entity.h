#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include<stack>
#include<map>

#include<vector>

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<HitboxInitialiser.h>

#include "IDimensions.h"
class Entity : public IDimensions
{
    private:
        sf::RectangleShape playerHitbox; //player hitbox

        sf::RectangleShape player; //player texture

        HitboxInitialiser hitbox;   //all hitboxes on the map

        float movementSpeed;

        sf::Texture texture;

    public:
        Entity();
        virtual ~Entity();

    //functions
    void update(const float& dt);
    void render(sf::RenderTarget* target);

    void move(const float& dt,const float x,const float y); //move the playerHitbox
    sf::RectangleShape getHitbox();

    //texture
    void createTexture(); //initialisation of the texture

    //hitbox
    void drawHitbox(sf::RenderTarget* target);

};

#endif // ENTITY_H
