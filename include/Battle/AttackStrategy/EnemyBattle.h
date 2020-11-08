#ifndef ENEMYBATTLE_H
#define ENEMYBATTLE_H
#include "Character.h"
#include <cstdlib>
#include <ctime>



class EnemyBattle : public Character
{
    private:
        sf::Texture enemyTexture;
        sf::Sprite enemySprite;


    public:
        EnemyBattle();
        EnemyBattle(Health health);
        virtual ~EnemyBattle();
        void attack(Character* p);
        void receiveDamage(double damage);
        void setStrategie();

        void render(sf::RenderWindow* window);

};

#endif // ENEMYBATTLE_H
