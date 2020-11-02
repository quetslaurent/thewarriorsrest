#ifndef WALL_H
#define WALL_H
#include "Hitbox.h"

class Wall : public Hitbox
{
    private:

    public:
        Wall(float posX,float posY,float width,float height);
        virtual ~Wall();

        void collide();

};

#endif // WALL_H
