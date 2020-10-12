#include "Game.h"

Game::Game()
{
    this->initWindow();     //call the function to set up the window
    this->initStates();
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

    //update items
    if(!this->states.empty()){
        this->states.top()->update(this->dt);
    }
}

//render the window
void Game::render(){
    // Clear screen
    this->wGame->clear();

    //render items
    if(!this->states.empty()){
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
