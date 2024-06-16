

#ifndef HANAMI_GAME_BUTTON_H
#define HANAMI_GAME_BUTTON_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

enum ButtonStates{IDLE=0,HOVER,ACTIVE};
class Button {
private:
    short unsigned buttonState;
    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;
    sf::Color textIdle;
    sf::Color textActive;
    sf::Color textHover;
    sf::Color activecol;
    sf::Color idlecol;
    sf::Color hovercol;
public:
    Button(float x,float y,float w,float h,
    sf::Font* font,std::string text,unsigned char_size,
           sf::Color t_idle_col,sf::Color t_hover_col,sf::Color t_active_col,
    sf::Color idecol,sf::Color hovercol,sf::Color activecol);
    virtual ~Button();
    //Accessor
    const bool isPressed() const;
    //functions
    void update(const sf::Vector2f mousePosition);
    void render(sf::RenderTarget& target);
};


#endif //HANAMI_GAME_BUTTON_H
