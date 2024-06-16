#ifndef HANAMI_GAME_GAME_H
#define HANAMI_GAME_GAME_H
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainMenuState.h"
#include "Map.h"
#include "TileMap.h"
class Game {
private:
    //Variables
  sf::RenderWindow *window;
    sf::Event event;
    std::vector<sf::VideoMode> VideoMode;
    sf::ContextSettings window_settings;
    bool fullscreen;
    sf::Clock clockDt;
    float deltaT;
    std::stack<State*> states;
    std::map<std::string,int> supportedKey;

    //Initialization
    void InitialVariables();
    void InitialWindow();
    void InitialKey();
    void InitialStates();

public:
    //Constructor/Destructor
    Game();
virtual ~Game();
 //Functions
 void endApplication();
 void updateDt();
 void update();
 void render();
 void run();
 void updateEvent();
};


#endif //HANAMI_GAME_GAME_H
