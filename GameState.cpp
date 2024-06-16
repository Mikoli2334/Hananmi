#include "GameState.h"
void GameState::InitialBackground() {
    this->background.setSize(sf::Vector2f(
            static_cast<float>(this->window->getSize().x),
            static_cast<float>(this->window->getSize().y)
    ));

    if(!this->tex.loadFromFile("Resource/Images/BackGround/FirstVersion.png")){
        throw"Erorr::GameState::BackGround";
    }
    this->background.setTexture(&this->tex);
}

void GameState::InitialMap() {
    this->gameMap=new Map("TextSettings/map.ini");
}

void GameState::InitialKeybinds() {
    std::ifstream file("TextSettings/Keybinds.ini");
    if(file.is_open()){
        std::string key="";
        std::string key1="";
        while(file >> key >> key1){
            this->Keybinds[key]=this->supportedKey->at(key1);
        }
    }
    file.close();


}
void GameState::InitialTexture() {
    if (!this->textures["Player_Idle"].loadFromFile("Resource/Images/Sprites/Player/char_blue_1.png")){
        throw "Error::GameState::Texture::player";
    }
}
void GameState::InitialPlayer() {
    this->player=new Player(0,0, this->textures["Player_Idle"]);
}

GameState::GameState(sf::RenderWindow* window,std::map<std::string,int>* supportedKey,std::stack<State*>* states):
        State(window,supportedKey,states)
{

   // this->InitialBackground();
    this->InitialKeybinds();
    this->InitialTexture();
    this->InitialPlayer();
    this->InitialMap();

};

GameState::~GameState() {
    delete this->player;
    delete this->gameMap;
}

void GameState::update(const float& deltaT) {
    this->updateMousePosition();
    this->updateInput(deltaT);
    this->player->update(deltaT);
}

void GameState::render(sf::RenderTarget* target) {
    if(!target){
        target= this->window;
    }
 //this->map.render(*target);
   // target->draw(this->background);
    //target->draw(this->background);
    this->gameMap->render(target);
    this->player->render(*target);
}

void GameState::updateInput(const float &deltaT) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->Keybinds.at("MOVE_LEFT"))))
        this->player->move(-1.f,0.f,deltaT);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->Keybinds.at("MOVE_RIGHT"))))
        this->player->move(1.f,0.f,deltaT);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->Keybinds.at("JUMP")))) /*&& (this->player.onGround))*/
        this->player->move(0.f,-1.f,deltaT);
    //  this->player.onGround=false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->Keybinds.at("MOVE_DOWN"))))
        this->player->move(0.f,1.f,deltaT);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->Keybinds.at("CLOSE"))))
        this->endState();
}