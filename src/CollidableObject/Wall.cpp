#include "Wall.h"

Wall::Wall(float posX,float posY,float width,float height):Hitbox(posX, posY, width, height)
{
}

Wall::~Wall()
{
    //dtor
}

void Wall::collide(){
    cout<<"WALL"<<"\n";
}
