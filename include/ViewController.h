#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H
#include <SFML/Graphics.hpp>
#include "BattleView.h"
#include "GameView.h"


class ViewController
{
    private:
        GameView* gameView; //id 1
        BattleView* battleView; // id 2
        int viewId;

    public:
        ViewController(sf::RenderWindow* window);
        virtual ~ViewController();

        //get views
        GameView* getGameView();
        BattleView* getBattleView();

        //get the enum value
        int getViewId()const;
        void setViewId(const int id);

};

#endif // VIEWCONTROLLER_H
