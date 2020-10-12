#include "Game.h"

Game::Game()
{
    this->initWindow();     //call the function to set up the window
}

Game::~Game()
{
    delete this->wGame;
}

//initialization
void Game::initWindow(){
    // Create the main window
    this->wGame= new sf::RenderWindow(sf::VideoMode(800, 600), "The Warrior's Rest");
    this->wGame->setFramerateLimit(120);
    this->wGame->setVerticalSyncEnabled(false);

    //set the position of the window
    this->wGame->setPosition(sf::Vector2i(0,0));
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
}

//render the window
void Game::render(){
    // Clear screen
    this->wGame->clear();
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
