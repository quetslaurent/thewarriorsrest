#include "ViewController.h"

ViewController::ViewController(sf::RenderWindow* window)
{
    gameView = new GameView(window);
    battleView = new BattleView(window);
    this->viewId=0;
}

ViewController::~ViewController()
{
    delete gameView;
    delete battleView;
}

GameView* ViewController::getGameView(){
    return gameView;
}

BattleView* ViewController::getBattleView(){
    return battleView;
}

int ViewController::getViewId()const{
    return viewId;
}

void ViewController::setViewId(const int id){
    this->viewId=id;
}

