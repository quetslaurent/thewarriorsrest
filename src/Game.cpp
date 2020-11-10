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
    for(State* s : states){
        delete s;
    }
}

//initialization
void Game::initWindow(){
    // Create the main window
    //this->wGame= new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "The Warrior's Rest",sf::Style::Fullscreen);
    this->wGame= new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "The Warrior's Rest");
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
    this->states.push_back(new GameState(this->wGame));
    this->states.push_back(new BattleState(this->wGame));
}

//fonctions

void Game::updateSFMLEvents(){
    // Process events
    while (this->wGame->pollEvent(this->sfEvent))
    {
        // Close window when we click the cross button
        if (this->sfEvent.type == sf::Event::Closed)
            this->wGame->close();
    }
}

void Game::update(){
    this->updateSFMLEvents();   //check if the window is closed

    //update states
    if(this->states.size() >0){

        this->states[StateManager::stateId]->update(this->dt);

        //when we quit the game
        if(this->states[StateManager::stateId]->getQuit())
        {
            //when we press esc button
            this->states[StateManager::stateId]->endState();
            delete this->states[StateManager::stateId];
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
    if(this->states.size() >0){
        this->states[StateManager::stateId]->render();
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


