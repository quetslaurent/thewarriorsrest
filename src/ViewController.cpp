#include "ViewController.h"

ViewController::ViewController(sf::RenderWindow* window)
{
    gameView = new GameView(window);
    battleView = new BattleView(window);
    looseView = new LooseView(window);
    this->viewId=0;
}

ViewController::~ViewController()
{
    delete gameView;
    delete battleView;
    delete looseView;
}

GameView* ViewController::getGameView(){
    return gameView;
}

BattleView* ViewController::getBattleView(){
    return battleView;
}

LooseView* ViewController::getLooseView(){
    return looseView;
}

int ViewController::getViewId()const{
    return viewId;
}

void ViewController::setViewId(const int id){
    this->viewId=id;
}

