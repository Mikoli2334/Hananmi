//
// Created by Asus on 14.06.2024.
//

#ifndef HANAMI_GAME_COMPONENTBOX_H
#define HANAMI_GAME_COMPONENTBOX_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

class ComponentBox : public sf::Transformable{
private:
    sf::Sprite sprite;
    sf::RectangleShape hitbox;
    float offsetX;
    float offsetY;
public:
    ComponentBox(sf::Sprite& sprite,float offset_x,float  offset_y,float width,float height);
    bool checkIntersect(const sf::FloatRect& frect);
 virtual ~ComponentBox();
 void update();
 void render(sf::RenderTarget& targ);

};


#endif //HANAMI_GAME_COMPONENTBOX_H
