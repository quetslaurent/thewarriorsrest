#ifndef BATTLEVIEW_H
#define BATTLEVIEW_H
#include <SFML/Graphics.hpp>
using namespace std;
#include <cstring>
#include "IDimensions.h"

class BattleView : public IDimensions
{
    private:
        //the window
        sf::RenderWindow* window;

        //map
        sf::Texture mapTexture;
        sf::Sprite mapSprite;

        //healthbar
        sf::RectangleShape playerHealth;
        sf::RectangleShape enemyHealth;

        //text during the battle
        sf::Font font;
        sf::Text battleText;

        //player texture
        sf::Texture playerTexture;
        sf::Sprite playerSprite;

        //enemy texture
        sf::Texture enemyTexture;
        sf::Sprite enemySprite;

    public:
        BattleView(sf::RenderWindow* window);
        virtual ~BattleView();

        //init textures
        void initMapTexture();
        void initHealthBars();
        void initTextBattle();
        void initEnemyTexture();
        void initPlayerTexture();



        //draw health bars
        void drawHealthPlayer(int hp);
        void drawHealthEnemy(int hp);

        //text
        void drawBattleText();
        void setBattleText(string text);

        //draw player and enemy
        void drawPlayerTexture();
        void drawEnemyTexture();

        //animations
        void playerAttackAnimation();
        void enemyAttackAnimation();
        void resetEnemyTexture();

        //background
        void drawBackground();

        //draw all
        void drawAll(const double enemy_hp,const double player_hp);


};

#endif // BATTLEVIEW_H
