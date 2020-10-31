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

    Wall* wall= new Wall(0,0,120,150);
    Wall* wall1= new Wall(200,0,120,150);

    hitboxes.push_back(wall);
    hitboxes.push_back(wall1);

}

std::vector<Hitbox*> HitboxInitialiser::getHitboxes()const {
        return hitboxes;
}
