#ifndef WINVIEW_H
#define WINVIEW_H
#include <SFML/Graphics.hpp>
class WinView
{
    sf::RenderWindow* window;
        //win background
        sf::Texture winTexture;
        sf::Sprite winSprite;

    public:
        WinView(sf::RenderWindow* window);
        virtual ~WinView();

        //draw win image on screen
        void draw();
};

#endif // WINVIEW_H
