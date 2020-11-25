#ifndef LOOSEVIEW_H
#define LOOSEVIEW_H
#include <SFML/Graphics.hpp>

class LooseView
{
    sf::RenderWindow* window;
        //loose background
        sf::Texture looseTexture;
        sf::Sprite looseSprite;

    public:
        LooseView(sf::RenderWindow* window);
        virtual ~LooseView();

        //draw loose image on screen
        void draw();

};

#endif // LOOSEVIEW_H
