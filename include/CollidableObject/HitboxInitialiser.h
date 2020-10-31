#ifndef HITBOXINITIALISER_H
#define HITBOXINITIALISER_H
#include <vector>
#include "Hitbox.h"
#include "Enemy.h"
#include "Wall.h"

class HitboxInitialiser
{
    private:
        std::vector<Hitbox*> hitboxes;
    public:
        HitboxInitialiser();
        virtual ~HitboxInitialiser();
    //initialisation
    void initHitboxes();

    //getter
    std::vector<Hitbox*> getHitboxes()const;

};

#endif // HITBOXINITIALISER_H
