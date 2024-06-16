
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#ifndef HANAMI_GAME_MOVEMENT_H
#define HANAMI_GAME_MOVEMENT_H
enum movement_states{IDL=0,MOVING_LEFT,MOVING_RIGHT,MOVING_UP,MOVING_DOWN,MOVING};

class Movement {
private:
    sf::Sprite& sprite;
    float maxVelocity;
    sf::Vector2f velocity;
    float acceleration;
    float deceleration;
    //Initual functions
public :
    Movement(sf::Sprite& sprite,float maxVelocity,float acceleration,float deceleration);
  virtual  ~Movement();
  //const float& getMaxVelocity() const;
  const sf::Vector2f& getVelocity() const;
  //functions
  const bool  getState(const short unsigned state) const;

  void move(const float x,const float y,const float& deltaT);
  void update(const float & deltaT);
};


#endif //HANAMI_GAME_MOVEMENT_H
