#include "PlayerTurn.h"

PlayerTurn::PlayerTurn()
{
    //ctor
}

PlayerTurn::~PlayerTurn()
{
    //dtor
}

void PlayerTurn::nextState()
{

}

void PlayerTurn::attack()
{
       //first attack
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            getPlayer().setStrategie(new DefaultAttack());
       }
       //second attack
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            getPlayer().setStrategie(new CriticalAttack());
       }
//       //heal
//       if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
//            ableToFight = false;
//       }
       //ultimate
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
            getPlayer().setStrategie(new UltimateAttack());
       }

       //getPlayer().attack();
}
