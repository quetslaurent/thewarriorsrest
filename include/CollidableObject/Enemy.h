#ifndef ENEMY_H
#define ENEMY_H
#include "Hitbox.h"
#include "IStateId.h"
#include "StateManager.h"

class Enemy : public Hitbox,IStateId
{
    public:
        Enemy(float posX,float posY,float width,float height);
        virtual ~Enemy();

        void collide(sf::RectangleShape& playerHitbox);
};

#endif // ENEMY_H
