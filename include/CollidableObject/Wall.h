#ifndef WALL_H
#define WALL_H
#include "Hitbox.h"

class Wall : public Hitbox
{
    private:

    public:
        Wall(float posX,float posY,float width,float height);
        virtual ~Wall();

};

#endif // WALL_H
