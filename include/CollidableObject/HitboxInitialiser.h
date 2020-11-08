#ifndef HITBOXINITIALISER_H
#define HITBOXINITIALISER_H
#include <vector>
#include "Hitbox.h"
#include "Wall.h"
#include "Enemy.h"

class HitboxInitialiser
{
    private:
        std::vector<Hitbox*> hitboxes;
        //sf::Texture enemyTexture;
    public:
        HitboxInitialiser();
        virtual ~HitboxInitialiser();
    //initialisation
    void initHitboxes();

    //getter
    std::vector<Hitbox*> getHitboxes()const;

};

#endif // HITBOXINITIALISER_H
