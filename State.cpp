//
// Created by Asus on 18.05.2024.
//

#include "State.h"

State::State(sf::RenderWindow* window,std::map<std::string,int>* supportedKey,std::stack<State*>* states) {
  this->window=window;
  this->supportedKey=supportedKey;
  this->states=states;
  this->quit=false;
}

State::~State() {

}



const bool &State::GetQuit() const {
   return this->quit;
}

void State::updateMousePosition() {
  this->MousePosScreen=sf::Mouse::getPosition();
  this->MousePosWindow=sf::Mouse::getPosition(*this->window);
  this->MousePosView=this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void State::endState() {
this->quit=true;
}

