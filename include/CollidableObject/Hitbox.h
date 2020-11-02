#ifndef HITBOX_H
#define HITBOX_H
#include <SFML/Graphics.hpp>
#include<iostream>
using std::cout;
class Hitbox
{
    private:
        sf::RectangleShape hitbox;
    public:
        Hitbox();
        Hitbox(float posX,float posY,float width,float height);
        virtual ~Hitbox();
        Hitbox(const Hitbox& other);
        Hitbox& operator=(const Hitbox& other);

        virtual void collide();

        sf::RectangleShape getHitbox()const;
};

#endif // HITBOX_H
