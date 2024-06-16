#include <stdexcept>
#include "MainMenuState.h"

void MainMenuState::InitialVariables() {

}

void MainMenuState::InitialBackground() {
this->background.setSize(sf::Vector2f (
        static_cast<float>(this->window->getSize().x),
        static_cast<float>(this->window->getSize().y)
        ));
 if(!this->BackgroundTexture.loadFromFile("Resource/Images/BackGround/MainMenu.png")){
     throw"Erorr::MainMenuState::BackGround";
 }
  this->background.setTexture(&this->BackgroundTexture);
}
void MainMenuState::InitialKeybinds() {
    std::ifstream file("TextSettings/MainMenuKeybinds.ini");
    if(file.is_open()){
        std::string key="";
        std::string key4="";
        while(file >> key >> key4){
            this->Keybinds[key]=this->supportedKey->at(key4);
        }
    }
   file.close();
}
void MainMenuState::InitialFonts() {
if(!this->font.loadFromFile("Fonts/christmasscript/Christmas ScriptC.ttf")) {
    throw std::runtime_error("Error_MainMenuSTATE_Fonts");
   // std::cout<<"errrrrrrrrr";
}
}

void MainMenuState::InitialButtons() {

    this->buttons["GameStateButton"]=new Button(
            886.f,451.f,300.f,50.f,&this->font,"New Game",32,
            sf::Color(40,20,250,250),
            sf::Color(150,150,150,250),
            sf::Color(20,20,20,50),
            sf::Color(70,70,70,200),sf::Color(150,150,150,0),
            sf::Color(20,20,20,0));
    this->buttons["Settings"]=new Button(
            886,551,300,50,&this->font,"Settings",32,
            sf::Color(40,20,250,250),
            sf::Color(150,150,150,250),
            sf::Color(20,20,20,50),
            sf::Color(70,70,70,200),sf::Color(150,150,150,0),
            sf::Color(20,20,20,0));
    this->buttons["Map_Editor"]=new Button(
            886,651,300,50,&this->font,"Map Editor",32,
            sf::Color(40,20,250,250),
            sf::Color(150,150,150,250),
            sf::Color(20,20,20,50),
            sf::Color(70,70,70,200),sf::Color(150,150,150,0),
            sf::Color(20,20,20,0));
    this->buttons["Exit"]=new Button(
            886,751,300,50,&this->font,"Exit",32,
            sf::Color(40,20,250,250),
            sf::Color(150,150,150,250),
            sf::Color(20,20,20,50),
            sf::Color(70,70,70,200),sf::Color(150,150,150,0),
            sf::Color(20,20,20,0));
}
MainMenuState::MainMenuState(sf::RenderWindow* window,std::map<std::string,int>* supportedKey,std::stack<State*>* states):
        State(window,supportedKey,states)
{
    this->InitialVariables();
    this->InitialBackground();
    this->InitialFonts();
    this->InitialKeybinds();
    this->InitialButtons();
}

MainMenuState::~MainMenuState() {
    auto it = this->buttons.begin();
    for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
        delete it->second;
    }
}

void MainMenuState::updateButtons() {
for(auto &it:this->buttons) {
    it.second->update(this->MousePosView);
}
    if(this->buttons["GameStateButton"]->isPressed()){
        this->states->push(new GameState(this->window,this->supportedKey,this->states));
    }
    if(this->buttons["Map_Editor"]->isPressed()){
        this->states->push(new EditorState(this->window,this->supportedKey,this->states));
    }
    if(this->buttons["Exit"]->isPressed()){
        this->endState();
    }
}

void MainMenuState::update(const float& deltaT) {
    this->updateMousePosition();
    this->updateInput(deltaT);
    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget& target) {
    for(auto &it:this->buttons){
        it.second->render(target);
    }
}
void MainMenuState::render(sf::RenderTarget* target) {
    if (!target) {
        target = this->window;
    }
    target->draw(this->background);
    this->renderButtons(*target);
//
//    sf::Text mouseText;
//    mouseText.setPosition(this->MousePosView.x, this->MousePosView.y - 50);
//    mouseText.setFont(this->font);
//    mouseText.setCharacterSize(12);
//    std::stringstream ss;
//    ss << this->MousePosView.x<< " " << this->MousePosView.y;
//    mouseText.setString(ss.str());
//    target->draw(mouseText);
}
void MainMenuState::updateInput(const float &deltaT) {


}












