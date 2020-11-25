#include "LooseView.h"

LooseView::LooseView(sf::RenderWindow* window)
{
     this->window=window;

    //init background image
    if(!this->looseTexture.loadFromFile("./image/loose.png")){
     EXIT_FAILURE;
    }

    this->looseSprite.setTexture(looseTexture);//set the loose texture on the sprite for the background
}

LooseView::~LooseView()
{
    //dtor
}

void LooseView::draw()
{
     this->window->draw(looseSprite); // draw the background
}
