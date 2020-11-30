#ifndef BATTLEVIEW_H
#define BATTLEVIEW_H
#include <SFML/Graphics.hpp>
using namespace std;
#include <cstring>
#include "IDimensions.h"
#include <iostream>

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

        //battle choice
        sf::Texture choiceTexture;
        sf::Sprite choiceSprite;

    public:
        BattleView(sf::RenderWindow* window);
        virtual ~BattleView();

        //init textures
        void initMapTexture();
        void initHealthBars();
        void initTextBattle();
        void initEnemyTexture();
        void initPlayerTexture();
        void initChoiceTexture();



        //draw health bars
        void drawHealthPlayer(int hp);
        void drawHealthEnemy(int hp);

        //text
        void drawBattleText();
        void setBattleText(string text);

        //choice
        void drawBattleChoice();

        //draw player and enemy
        void drawPlayerTexture();
        void drawEnemyTexture();

        //animations
        void playerAttackAnimation();
        void enemyAttackAnimation();
        void resetEnemyTexture();
        void resetPlayerTexture();

        //background
        void drawBackground();

        //draw all
        void drawAll(const double enemy_hp,const double player_hp);


};

#endif // BATTLEVIEW_H
