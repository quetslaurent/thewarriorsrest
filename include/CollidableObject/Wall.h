#ifndef WALL_H
#define WALL_H
#include "Hitbox.h"
#include<iostream>
using std::cout;
class Wall : public Hitbox
{
    private:

    public:
        Wall(float posX,float posY,float width,float height);
        virtual ~Wall();

        void collide(sf::RectangleShape& playerHitbox);

};

#endif // WALL_H
