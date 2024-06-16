//
// Created by Asus on 14.06.2024.
//

#include "EditorState.h"

void EditorState::InitialBackground() {

}
void EditorState::InitialVariables() {

}

void EditorState::InitialKeybinds() {
    std::ifstream file("TextSettings/EditorStateKey.ini");
    if(file.is_open()){
        std::string key="";
        std::string key4="";
        while(file >> key >> key4){
            this->Keybinds[key]=this->supportedKey->at(key4);
        }
    }
    file.close();
}
void EditorState::InitialFonts() {
    if(!this->font.loadFromFile("Fonts/christmasscript/Christmas ScriptC.ttf")) {
        throw std::runtime_error("Error_EditorStateSTATE_Fonts");
        // std::cout<<"errrrrrrrrr";
    }
}

void EditorState::InitialButtons() {

}
EditorState::EditorState(sf::RenderWindow* window,std::map<std::string,int>* supportedKey,std::stack<State*>* states):
        State(window,supportedKey,states)
{
    this->InitialVariables();
    this->InitialBackground();
    this->InitialFonts();
    this->InitialKeybinds();
    this->InitialButtons();
    this->InitialTileMap();
}

EditorState::~EditorState() {
    auto it = this->buttons.begin();
    for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
        delete it->second;
    }
    delete this->tileMap;
}

void EditorState::updateButtons() {
    for(auto &it:this->buttons) {
        it.second->update(this->MousePosView);
    }
}

void EditorState::update(const float& deltaT) {
    this->updateMousePosition();
    this->updateInput(deltaT);
    this->updateButtons();
}

void EditorState::renderButtons(sf::RenderTarget& target) {
    for(auto &it:this->buttons){
        it.second->render(target);
    }
}
void EditorState::render(sf::RenderTarget* target) {
    if (!target) {
        target = this->window;
    }
    this->renderButtons(*target);
    this->tileMap->render(*target);
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
void EditorState::updateInput(const float &deltaT) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->Keybinds.at("CLOSE"))))
        this->endState();

}

void EditorState::InitialTileMap() {
this->tileMap=new TileMap();
}












