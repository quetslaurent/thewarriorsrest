#ifndef ENEMY_H
#define ENEMY_H
#include "Hitbox.h"

class Enemy : public Hitbox
{
    private:

    public:
        Enemy(float posX,float posY,float width,float height);
        virtual ~Enemy();

        void collide();

};

#endif // ENEMY_H
