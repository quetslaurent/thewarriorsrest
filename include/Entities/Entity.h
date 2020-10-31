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
#include<stack>
#include<map>
#include<HitboxInitialiser.h>
class Entity
{
    private:
        sf::RectangleShape playerHitbox;

        sf::RectangleShape player;

        HitboxInitialiser hitbox;


        float movementSpeed;

        sf::Texture texture;

    public:
        Entity();
        virtual ~Entity();

    //functions
    void update(const float& dt);
    void render(sf::RenderTarget* target);

    void move(const float& dt,const float x,const float y);
    sf::RectangleShape getHitbox();

    //texture
    void createTexture();



};

#endif // ENTITY_H
