#include "WinView.h"

WinView::WinView(sf::RenderWindow* window)
{
     this->window=window;

    //init background image
    if(!this->winTexture.loadFromFile("./image/win.png")){
     EXIT_FAILURE;
    }

    this->winSprite.setTexture(winTexture);//set the win texture on the sprite for the background
}

WinView::~WinView()
{
    //dtor
}

void WinView::draw()
{
     this->window->draw(winSprite); // draw the background
}

