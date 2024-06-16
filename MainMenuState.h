

#ifndef HANAMI_GAME_MAINMENUSTATE_H
#define HANAMI_GAME_MAINMENUSTATE_H
#include "vector"
#include "GameState.h"
#include "Button.h"
#include "EditorState.h"

class MainMenuState :
 public State{
private:
    //Variables

    std::vector<sf::Texture> textures;
    sf::Texture BackgroundTexture;
    sf::Font font;
    sf::RectangleShape background;

   std::map<std::string,Button*> buttons;
    //functions
    void InitialVariables();
    void InitialBackground();
    void InitialFonts();
    void InitialKeybinds() ;
    void InitialButtons();
public:
    MainMenuState(sf::RenderWindow* window,std::map<std::string,int>* supportedKey,std::stack<State*>* states);
    virtual ~MainMenuState() ;
    //functions

    virtual void updateInput(const float& deltaT);
    void updateButtons();
    void update(const float& deltaT);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target= nullptr);


};


#endif //HANAMI_GAME_MAINMENUSTATE_H
