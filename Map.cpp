#include "Map.h"
#include <fstream>
#include <stdexcept>

// Constructor for Map class
Map::Map(const std::string& filename) {
    this->tileSize = 32; // Assuming a default tile size of 32
    this->loadMap(filename);
    this->loadTextures();
}

// Load map from file
void Map::loadMap(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open map file.");
    }
    int value;
    std::vector<int> row;
    while (file >> value) {
        row.push_back(value); // Вставляем значение в конец вектора
        if (file.peek() == '\n' || file.eof()) {
            mapData.push_back(row);
            row.clear();
        }
    }
    file.close();
}

// Load textures for tiles
void Map::loadTextures() {
    if (!tileTextures[0].loadFromFile("Resource/Images/Tiles/tile.png") ||
        !tileTextures[1].loadFromFile("Resource/Images/Tiles/tile2.png") ||
        !tileTextures[2].loadFromFile("Resource/Images/Tiles/tile3.png")) {
        throw std::runtime_error("Could not load tile textures.");
    }
}

// Render the map
void Map::render(sf::RenderTarget* target) {
    for (size_t i = 0; i < mapData.size(); ++i) {
        for (size_t j = 0; j < mapData[i].size(); ++j) {
            int tileType = mapData[i][j];
            if (tileType > 0) { // Пропускаем нулевые значения
                tileSprite.setTexture(tileTextures[tileType - 1]);
                tileSprite.setPosition(j * tileSize, target->getSize().y - (i + 1) * tileSize);
                target->draw(tileSprite);
            }
        }
    }
}

// Check collision with the map
bool Map::checkCollision(const sf::FloatRect& rect) {
    int leftTile = rect.left / tileSize;
    int rightTile = (rect.left + rect.width) / tileSize;
    int topTile = rect.top / tileSize;
    int bottomTile = (rect.top + rect.height) / tileSize;

    for (int i = topTile; i <= bottomTile; ++i) {
        for (int j = leftTile; j <= rightTile; ++j) {
            if (i >= 0 && i < mapData.size() && j >= 0 && j < mapData[i].size()) {
                int tileType = mapData[i][j];
                if (tileType > 0) { // Столкновение, если значение больше 0
                    return true;
                }
            }
        }
    }
    return false; // Столкновение не найдено
}