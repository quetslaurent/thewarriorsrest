#ifndef HITBOXCOLLIDER_H
#define HITBOXCOLLIDER_H
#include "HitboxInitialiser.h"
#include <SFML/Graphics.hpp>
#include "IDimensions.h"

class HitboxCollider : public IDimensions
{
    private:
        HitboxInitialiser hitboxInitialiser;   //all hitboxes on the map
    public:
        HitboxCollider();
        virtual ~HitboxCollider();
        HitboxCollider(const HitboxCollider& other);
        HitboxCollider& operator=(const HitboxCollider& other);

        void collide(sf::RectangleShape& playerHitbox);
        void drawHitbox(sf::RenderWindow* target,sf::RectangleShape& playerHitbox);
        void drawEnemies(sf::RenderWindow* target,sf::RectangleShape& playerHitbox);

};

#endif // HITBOXCOLLIDER_H
