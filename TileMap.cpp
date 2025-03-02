//
// Created by Asus on 15.06.2024.
//

#include "TileMap.h"

TileMap::TileMap() {
    this->gridSizeF=50.f;
    this->gridSizeU = static_cast<unsigned >(this->gridSizeF);
    this->maxSize.x = 10;
    this->maxSize.y = 10;
    this->layers = 1;
    this->map.resize(this->maxSize.x);
    for (size_t x = 0; x < this->maxSize.x; x++) {
        this->map.push_back(std::vector<std::vector<Tile> >());
        for (size_t y = 0; y < this->maxSize.y; y++) {
            this->map[x].resize(this->maxSize.y);
            this->map[x].push_back(std::vector<Tile>());
            for (size_t z = 0; z < this->layers; z++) {
                this->map[x][y].resize(this->layers);//Tile(x*gridSizeF,y*gridSizeF,gridSizeF));
                this->map[x][y].push_back(Tile(x*gridSizeF,y*gridSizeF,gridSizeF));
            }
        }
    }
}

TileMap::~TileMap() {

}

void TileMap::render(sf::RenderTarget& target) {
    for (auto &x: this->map) {
        for (auto &y: x) {
            for (auto &z: y) {
                z.render(target);
            }
        }
    }
}
void TileMap::update() {

}
