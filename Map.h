

#ifndef HANAMI_GAME_MAP_H
#define HANAMI_GAME_MAP_H
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <SFML/Graphics.hpp>
class Map {
private:
    std::vector<std::vector<int>> mapData;
    sf::Texture tileTextures[3];
    sf::Sprite tileSprite;
     int tileSize = 32; // Размер тайла (например, 32x32 пикселя)

    void loadMap(const std::string& filename);
    void loadTextures();
public:
    Map(const std::string& filename);
    void render(sf::RenderTarget* target);
    bool checkCollision(const sf::FloatRect& rect);
};


#endif //HANAMI_GAME_MAP_H
