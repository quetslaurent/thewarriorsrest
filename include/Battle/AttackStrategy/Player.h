#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"


class Player : public Character
{
    private:


    public:
        Player();
        Player(Health health);
        virtual ~Player();

        void render(sf::RenderWindow* window);

};

#endif // PLAYER_H
