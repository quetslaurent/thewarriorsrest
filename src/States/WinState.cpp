#include "WinState.h"

WinState::WinState(sf::RenderWindow* window,ViewController* viewController):State(window)
{
    this->winView = viewController->getWinView();
    this->viewController=viewController;
}

WinState::~WinState()
{
    //dtor
}

void WinState::render()
{
    winView->draw();
}

void WinState::update(const float& dt)
{
    this->updateKeybinds();  //check if the player pressed a specific key
}

void WinState::updateKeybinds()
{
    this->checkForQuit();   //check if the user pressed the "esc" key
}

//end of WinState
void WinState::endState()
{
    std::cout<<"END of WinState"<<"\n";
}

