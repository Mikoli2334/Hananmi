//
// Created by Asus on 15.06.2024.
//

#include "Tile.h"


   // this->shape.setSize(sf::Vector2f (gridSizeF,gridSizeF));
  //  this->shape.setFillColor(sf::Color::Green);



Tile::~Tile() {
}

Tile::Tile(float x, float y, float gridSizeF) {
this->shape.setSize(sf::Vector2f (gridSizeF,gridSizeF));
      this->shape.setFillColor(sf::Color::Green);
      this->shape.setPosition(x,y);
}

Tile::Tile() {

}

void Tile::update() {

}

void Tile::render(sf::RenderTarget &target) {
target.draw(this->shape);
}



