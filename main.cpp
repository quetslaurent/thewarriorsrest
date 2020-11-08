#include "Game.h"
#include "StateManager.h"
#include <ctime>
int StateManager::stateId = 0;

int main()
{
    Game game;
    game.run();
    return 0;
}
