#include "HitboxInitialiser.h"

HitboxInitialiser::HitboxInitialiser()
{
    initHitboxes();
}

HitboxInitialiser::~HitboxInitialiser()
{
    //dtor
}


void HitboxInitialiser::initHitboxes(){

    Wall* wall= new Wall(200,0,300,350);
    Wall* wall1= new Wall(500,200,100,300);
    Wall* wall2= new Wall(-200,800,300,250);
    Enemy* en= new Enemy(0,0,120,150);

    hitboxes.push_back(wall);
    hitboxes.push_back(en);
    hitboxes.push_back(wall1);
     hitboxes.push_back(wall2);

}

std::vector<Hitbox*> HitboxInitialiser::getHitboxes()const {
        return hitboxes;
}
