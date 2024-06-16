
#ifndef HANAMI_GAME_GAMESTATE_H
#define HANAMI_GAME_GAMESTATE_H
#include "State.h"
#include "Map.h"
#include "TileMap.h"

class GameState : public State
 {
 private:
     Map* gameMap;
   sf::Texture tex;
   TileMap map;
//    std::vector<sf::Texture> Btexture;
//
//    std::vector<sf::Sprite> sprites;

sf::RectangleShape background;
 Player* player;
 //functions
 void InitialMap();
 void InitialBackground();
 void InitialKeybinds() ;
 void InitialTexture();
 void InitialPlayer();

public:
     GameState(sf::RenderWindow* window,std::map<std::string,int>* supportedKey,std::stack<State*>* states);
    virtual ~GameState() ;
    //functions
    virtual void updateInput(const float& deltaT);
    void update(const float& deltaT);
    void render(sf::RenderTarget* target= NULL);
};


#endif //HANAMI_GAME_GAMESTATE_H
