#include "LooseState.h"

LooseState::LooseState(sf::RenderWindow* window,ViewController* viewController):State(window)
{
    this->looseView = viewController->getLooseView();
    this->viewController=viewController;
}

LooseState::~LooseState()
{
    //dtor
}

void LooseState::render()
{
    looseView->draw();
}

void LooseState::update(const float& dt)
{
    this->updateKeybinds();  //check if the player pressed a specific key
}

void LooseState::updateKeybinds()
{
    this->checkForQuit();   //check if the user pressed the "esc" key
}

//end of LooseState
void LooseState::endState()
{
    std::cout<<"END of LooseState"<<"\n";
}
