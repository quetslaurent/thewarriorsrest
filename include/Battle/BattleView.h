#ifndef BATTLEVIEW_H
#define BATTLEVIEW_H
#include <SFML/Graphics.hpp>
using namespace std;
#include <cstring>

class BattleView
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


};

#endif // BATTLEVIEW_H
