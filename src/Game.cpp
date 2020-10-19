#include "Game.h"


#include <iostream>
using std::cout;
Game::Game()
{
    this->initWindow();     //call the function to set up the window
    this->initStates();
    this->map.loadFromFile("./image/map3.png");
}

Game::~Game()
{
    delete this->wGame;

    //remove all the states
    while(!this->states.empty()){
        delete this->states.top();
        this->states.pop();
    }
}

//initialization
void Game::initWindow(){
    // Create the main window
    this->wGame= new sf::RenderWindow(sf::VideoMode(1080, 920), "The Warrior's Rest");
    this->wGame->setFramerateLimit(120);
    this->wGame->setVerticalSyncEnabled(false);

    //set the position of the window
    this->wGame->setPosition(sf::Vector2i(400,0));

    sf::Image icon;
    if(!icon.loadFromFile("./image/logo.png")){
        EXIT_FAILURE;
    }

    this->wGame->setIcon(32,32,icon.getPixelsPtr());

}

void Game::initStates(){
    this->states.push(new GameState(this->wGame));
}

//fonctions

void Game::updateSFMLEvents(){
    // Process events
    while (this->wGame->pollEvent(this->sfEvent))
    {
        // Close window : exit
        if (this->sfEvent.type == sf::Event::Closed)
            this->wGame->close();
    }
}

void Game::update(){
    this->updateSFMLEvents();

    //update states
    if(!this->states.empty()){
        this->states.top()->update(this->dt);

        //when we quit the game
        if(this->states.top()->getQuit())
        {
            //when we press esc button
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    //en of the Application
    else
    {
        //call the end function
        this->endApplication();
        //close the window if the states are empty
        this->wGame->close();
    }
}

//render the window
void Game::render(){
    // Clear screen
    this->wGame->clear();

    //render items
    if(!this->states.empty()){
        //background image
        sf::Sprite s(map);
        this->wGame->draw(s);
        this->states.top()->render();
    }

    // Update the window
    this->wGame->display();
}

//run the game
void Game::run(){

	// Start the game loop
    while (this->wGame->isOpen())
    {
        this->updateDt();   //save the delta time
        this->update(); //update the window
        this->render();
    }

}

//update the delta time
void Game::updateDt()
{
    //save the delta time
    this->dt= this->dtClock.restart().asSeconds();
}

//called a the end of the application
void Game::endApplication()
{
     std::cout<<"End of the Application"<<"\n";
}
