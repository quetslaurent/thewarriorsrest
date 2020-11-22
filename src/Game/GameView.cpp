#include "GameView.h"

GameView::GameView(sf::RenderWindow* window)
{
    this->window=window;

    //init background image
    initBackgroundTexture();

    //init player Texture
    initPlayerTexture();

    //init enemy Texture
    initEnemyTexture();
}

GameView::~GameView()
{
    //dtor
}

//draw background
void GameView::drawBackground(sf::Vector2f playerposition){
    mapSprite.setPosition(playerposition.x-START_X,playerposition.y-START_Y);  //move the background depending on the player position,the 490 and 1350 numbers are for set the start position
    this->window->draw(mapSprite); // draw the background
}

//change direction texture depending the player direction
void GameView::drawPlayer(EnumDirection playerDirection){
    if(playerDirection==EnumDirection::E)
    {
        this->player.setTextureRect(sf::IntRect(2200,0,1100,1100));

    }
    //left
    if(playerDirection==EnumDirection::W)
    {
        this->player.setTextureRect(sf::IntRect(1100,0,1100,1100));
    }

    //down
    if(playerDirection==EnumDirection::S)
    {
        this->player.setTextureRect(sf::IntRect(0,0,1100,1100));
    }

    //up
    if(playerDirection==EnumDirection::N)
    {
        this->player.setTextureRect(sf::IntRect(0,1100,1100,1100));
    }

    this->window->draw(player);
}

//draw the enemies
void GameView::drawEnemies(std::vector<Hitbox*> listHitboxes,sf::RectangleShape& playerHitbox)
{
    for(Hitbox* &collision :listHitboxes){
        if( dynamic_cast<Enemy*>(collision) != nullptr){

             //get the RectangleShape from the Hitbox class
             sf::RectangleShape hitboxdisplay = collision->getHitbox();

             hitboxdisplay.setTexture(&enemyTexture);
             hitboxdisplay.setTextureRect(sf::IntRect(1100,1100,1100,1100));
             hitboxdisplay.setSize(sf::Vector2f(120.f,120.f));//the enemy texture

             //modify the position , so the hitbox is at the good place on the screen
             hitboxdisplay.setPosition(hitboxdisplay.getPosition().x- (hitboxdisplay.getPosition().x*2),hitboxdisplay.getPosition().y- (hitboxdisplay.getPosition().y*2));

             hitboxdisplay.move((WINDOW_WIDTH/2)-PLAYERHITBOX_WIDTH/2 +playerHitbox.getPosition().x +PLAYERHITBOX_WIDTH+40, (WINDOW_HEIGHT/2)-PLAYERHITBOX_HEIGHT/2+playerHitbox.getPosition().y +PLAYERHITBOX_HEIGHT+30);

             hitboxdisplay.rotate(180);

             //draw the hitbox
             this->window->draw(hitboxdisplay);
        }
    }
}

//draw all the hitboxes on the map
void GameView::drawHitboxes(std::vector<Hitbox*> listHitboxes,sf::RectangleShape& playerHitbox)
{
    for(Hitbox* &collision :listHitboxes){

             //get the RectangleShape from the Hitbox class
             sf::RectangleShape hitboxdisplay = collision->getHitbox();

             //modify the position , so the hitbox is at the good place on the screen
             hitboxdisplay.setPosition(hitboxdisplay.getPosition().x- (hitboxdisplay.getPosition().x*2),hitboxdisplay.getPosition().y- (hitboxdisplay.getPosition().y*2));

             hitboxdisplay.move((WINDOW_WIDTH/2)-PLAYERHITBOX_WIDTH/2 +playerHitbox.getPosition().x +PLAYERHITBOX_WIDTH, (WINDOW_HEIGHT/2)-PLAYERHITBOX_HEIGHT/2+playerHitbox.getPosition().y +PLAYERHITBOX_HEIGHT);

             hitboxdisplay.rotate(180);

             //set a "random" color
             hitboxdisplay.setFillColor(sf::Color(100, hitboxdisplay.getPosition().x, 50));
             //draw the hitbox
             window->draw(hitboxdisplay);

    }
        //draw the player hitbox
        sf::RectangleShape player = playerHitbox;
        player.setPosition( (WINDOW_WIDTH/2)-PLAYERHITBOX_WIDTH/2 , (WINDOW_HEIGHT/2)-PLAYERHITBOX_HEIGHT/2 );
        window->draw(player);
}


//set the texture to the player
void GameView::initPlayerTexture()
{
 if(!this->playerTexture.loadFromFile("./image/playerAnimation.png")){
     EXIT_FAILURE;
    }
    this->player.setTexture(&playerTexture);
    this->player.setSize(sf::Vector2f(120.f,120.f));//the player's texture
    this->player.setPosition((WINDOW_WIDTH/2)-PLAYERHITBOX_WIDTH, (WINDOW_HEIGHT/2)-PLAYERHITBOX_HEIGHT);//put the player in the center of the screen
    this->player.setTextureRect(sf::IntRect(0,0,1100,1100));
}

//set the background texture
void GameView::initBackgroundTexture()
{
    if(!this->mapTexture.loadFromFile("./image/map.png")){
     EXIT_FAILURE;
    }

    this->mapSprite.setTexture(mapTexture);//set the map texture on the sprite for the background
}

//set the enemy texture
void GameView::initEnemyTexture()
{
     this->enemyTexture.loadFromFile("./image/enemyAnimation.png");
}
