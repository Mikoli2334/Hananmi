#include "Game.h"
//Static function
//Initializer functiIon

void Game::InitialVariables() {
this->window=NULL;
this->fullscreen=false;
this->deltaT=0.f;

    std::cout<<deltaT<<"PPPPPPPP";
}
void Game::InitialWindow() {
    std::ifstream file("TextSettings/window.ini");
    this->VideoMode=sf::VideoMode::getFullscreenModes();
    std::string title="Null";
    sf::VideoMode window_size=sf::VideoMode::getDesktopMode();
    bool fullscreen=false;
    unsigned frame_rate=120;
    bool vertical_set=false;
    unsigned antialiasing_level=0;
    if(file.is_open()){
      std::getline(file,title);
      file >> window_size.width >>window_size.height;
        file >>fullscreen;
        file >>frame_rate;
      file >>vertical_set;
      file >>antialiasing_level;
    }
    file.close();
    this->fullscreen=fullscreen;
    this->window_settings.antialiasingLevel=antialiasing_level;
    if(fullscreen)
    this->window = new sf::RenderWindow(
            window_size, title,sf::Style::Fullscreen,window_settings);
    else
        this->window = new sf::RenderWindow(
                window_size, title,sf::Style::Titlebar | sf::Style::Close,window_settings);
    this->window->setFramerateLimit(frame_rate);
    this->window->setVerticalSyncEnabled(vertical_set);
}
void Game::InitialKey() {
    std::ifstream file("TextSettings/supportedKeys.ini");
    if(file.is_open()){
        std::string key="";
        int value=0;
        while(file>>key>>value){
            this->supportedKey[key]=value;
        }
    }
    file.close();


}
void Game::InitialStates() {
   // GameState* gm=new GameState(this->window,&this->supportedKey);
    //this->states.push(new GameState(this->window,&this->supportedKey));
    this->states.push(new MainMenuState(this->window,&this->supportedKey,&this->states));
}
//Constructor/Destructor
Game::Game(){
    this->InitialVariables();
        this->InitialWindow();
        this->InitialKey();
        this->InitialStates();

    };
Game::~Game(){
 delete this->window;
 while(!this->states.empty()){
     delete this->states.top();
      this->states.pop();
 }
};
//functions
void Game::endApplication() {
std::cout<<"Ending Application"<<"\n";
}

void Game::updateDt() {
    this->deltaT=this->clockDt.restart().asSeconds();
}
void Game::update() {
 this->updateEvent();
    if(!this->states.empty()){
        this->states.top()->update(this->deltaT);
        if(this->states.top()->GetQuit()){
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else{
        this->endApplication();
        this->window->close();
    }
}
void Game::render() {

    this->window->clear();
    if(!this->states.empty()){
        this->states.top()->render();
    }
    this->window->display();
}
void Game::run() {
    while (this->window->isOpen()) {
        this->updateDt();
       this->update();
       this->render();
    }
}
void Game::updateEvent() {
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }

}












