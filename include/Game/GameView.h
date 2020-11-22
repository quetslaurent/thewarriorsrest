#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include "IDimensions.h"
#include "EnumDirection.h"
#include "Hitbox.h"
#include "Enemy.h"

class GameView : public IDimensions
{
    private:
        sf::RenderWindow* window;

        //map background
        sf::Texture mapTexture;
        sf::Sprite mapSprite;

        //player texture
        sf::RectangleShape player;
        sf::Texture playerTexture;

        //enemy texture
        sf::Texture enemyTexture;


    public:
        GameView(sf::RenderWindow* window);
        virtual ~GameView();

    //background
    void drawBackground(sf::Vector2f playerPosition);

    //player
    void drawPlayer(EnumDirection playerDirection);

    //enemies
    void drawEnemies(std::vector<Hitbox*> listHitboxes,sf::RectangleShape& playerHitbox);

    //hitbox for debug
    void drawHitboxes(std::vector<Hitbox*> listHitboxes,sf::RectangleShape& playerHitbox);

    //initialize textures
    void initBackgroundTexture();
    void initPlayerTexture();
    void initEnemyTexture();
};

#endif // GAMEVIEW_H
