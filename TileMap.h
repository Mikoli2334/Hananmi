
#ifndef HANAMI_GAME_TILEMAP_H
#define HANAMI_GAME_TILEMAP_H
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
 #include <memory>
 #include <set>
 #include <thread>
  #include <utility>
  #include <vector>
   #include <list>
    #include <stack>
    #include <string>
    #include <sstream>
    #include <fstream>
    #include <cmath>
//SFML
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
 #include <SFML\Audio.hpp>
 #include <SFML\Network.hpp>


#include "Tile.h"

class TileMap {
private:
    float gridSizeF;
    unsigned gridSizeU;
    sf::Vector2f maxSize;
    unsigned layers;
    std::vector<std::vector<std::vector<Tile>>> map;
public:
    TileMap();
    virtual ~TileMap();
    void update();
    void render(sf::RenderTarget& target);
};


#endif //HANAMI_GAME_TILEMAP_H
