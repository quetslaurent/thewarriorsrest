#include "HitboxInitialiser.h"

HitboxInitialiser::HitboxInitialiser()
{
    initHitboxes();

    cout<<"Construction HitboInitialiser"<<"\n";

}

HitboxInitialiser::~HitboxInitialiser()
{
    //dtor
}


void HitboxInitialiser::initHitboxes(){

    Wall* wall_bottom_left = new Wall(80,-230,500,500); // left, -top,width,height
    Wall* house_bottom_left = new Wall(530,250,500,300);
    Wall* furnace_bottom_right = new Wall(-80,380,500,200);
    Wall* wall_bottom_right = new Wall(-220,-150,200,500);
    Wall* bottom_spawn = new Wall(-100,-200,200,50);
    Wall* village_bottom_left = new Wall(510,530,500,435);
    Wall* village_bottom_right = new Wall(-660,500,750,435);
    Wall* village_well = new Wall(100,1100,150,80);
    Wall* village_right_middle = new Wall(-570,1070,500,200);
    Wall* north_houses = new Wall(-570,1400,1605,100);
    Wall* north_west_houses = new Wall(440,1060,600,220);
    Wall* west_fence = new Wall(1035,510,100,890);
    Wall* est_fence = new Wall(-650,510,100,890);

    Enemy* enemy = new Enemy(100,1000,80,80);

    cout<<"init Hitbox"<<"\n";


    hitboxes.push_back(wall_bottom_left);
    hitboxes.push_back(house_bottom_left);
    hitboxes.push_back(furnace_bottom_right);
    hitboxes.push_back(wall_bottom_right);
    hitboxes.push_back(bottom_spawn);
    hitboxes.push_back(village_bottom_left);
    hitboxes.push_back(village_bottom_right);
    hitboxes.push_back(village_well);
    hitboxes.push_back(village_right_middle);
    hitboxes.push_back(north_west_houses);
    hitboxes.push_back(north_houses);
    hitboxes.push_back(west_fence);
    hitboxes.push_back(est_fence);
    hitboxes.push_back(enemy);
}

std::vector<Hitbox*> HitboxInitialiser::getHitboxes()const {
        return hitboxes;
}
