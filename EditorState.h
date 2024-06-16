
#ifndef HANAMI_GAME_EDITORSTATE_H
#define HANAMI_GAME_EDITORSTATE_H
#include "Button.h"
#include "State.h"
#include "TileMap.h"

class EditorState:
        public State
        {
private:
    //Variables
    sf::Font font;

    std::map<std::string,Button*> buttons;
    TileMap* tileMap;
    //functions
    void InitialVariables();
    void InitialBackground();
    void InitialFonts();
    void InitialKeybinds() ;
    void InitialButtons();
    void InitialTileMap();
public:
    EditorState(sf::RenderWindow* window,std::map<std::string,int>* supportedKey,std::stack<State*>* states);
    virtual ~EditorState() ;
    //functions

    virtual void updateInput(const float& deltaT);
    void updateButtons();
    void update(const float& deltaT);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target= nullptr);


};


#endif //HANAMI_GAME_EDITORSTATE_H
