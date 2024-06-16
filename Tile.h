//
// Created by Asus on 15.06.2024.
//

#ifndef HANAMI_GAME_TILE_H
#define HANAMI_GAME_TILE_H
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Tile {
private:
protected:
    sf::RectangleShape shape;
public:
    Tile();
    Tile(float x,float y,float gridSizeF);
 virtual ~Tile();
    void update();
    void render(sf::RenderTarget& target);

};


#endif //HANAMI_GAME_TILE_H
