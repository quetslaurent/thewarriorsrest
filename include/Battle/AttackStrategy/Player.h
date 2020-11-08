#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"


class Player : public Character
{
    private:
        sf::Texture playerTexture;
        sf::Sprite playerSprite;

    public:
        Player();
        Player(Health health);
        virtual ~Player();
        void attack(Character* p);
        void receiveDamage(double damage);
        void setStrategie(AttackStrategy* strategie);

        void render(sf::RenderWindow* window);

        sf::Sprite& getSprite();
};

#endif // PLAYER_H
