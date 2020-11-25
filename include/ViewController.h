#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H
#include <SFML/Graphics.hpp>
#include "BattleView.h"
#include "GameView.h"
#include "LooseView.h"
#include "WinView.h"

class ViewController
{
    private:
        GameView* gameView; //id 0
        BattleView* battleView; // id 1
        LooseView* looseView; //id 2
        WinView* winView; //id 3
        int viewId;

    public:
        ViewController(sf::RenderWindow* window);
        virtual ~ViewController();

        //get views
        GameView* getGameView();
        BattleView* getBattleView();
        LooseView* getLooseView();
        WinView* getWinView();

        //get the enum value
        int getViewId()const;
        void setViewId(const int id);

};

#endif // VIEWCONTROLLER_H
