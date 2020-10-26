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
#include<vector>
#include<stack>
#include<map>

class Entity
{
    private:
        sf::RectangleShape hitbox;

        sf::RectangleShape player;

        float movementSpeed;

        sf::Texture texture;

    public:
        Entity();
        virtual ~Entity();

    //functions
    void update(const float& dt);
    void render(sf::RenderTarget* target);

    void move(const float& dt,const float x,const float y);

    //texture
    void createTexture();

    sf::RectangleShape getHitbox(){
        return hitbox;
    }

};

#endif // ENTITY_H
