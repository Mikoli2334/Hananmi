#ifndef HANAMI_GAME_STATE_H
#define HANAMI_GAME_STATE_H
#include "Player.h"
class State {
private:
protected:
    std::stack<State*>* states;
    sf::RenderWindow* window;
    std::map<std::string,int>* supportedKey;
    std::map<std::string,int> Keybinds;
    bool quit;

    sf::Vector2i MousePosWindow;
    sf::Vector2i MousePosScreen;
    sf::Vector2f MousePosView;
    //Resources
    std::map<std::string,sf::Texture> textures;
    //Functions
   virtual void InitialKeybinds()=0;
public:
    State(sf::RenderWindow* window,std::map<std::string,int>* supportedKey,std::stack<State*>* states);
    virtual ~State();
     const bool& GetQuit() const;
    //functions
    virtual void updateMousePosition();
    void endState();
    virtual void updateInput(const float& deltaT)=0;
   virtual void update(const float& deltaT)=0;
   virtual void render(sf::RenderTarget* target=nullptr)=0;
};


#endif //HANAMI_GAME_STATE_H
