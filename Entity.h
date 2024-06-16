#ifndef HANAMI_GAME_ENTITY_H
#define HANAMI_GAME_ENTITY_H
#include "Movement.h"
#include "Animation.h"
#include "ComponentBox.h"
#include "AnimationManager.h"
class Entity {
private:
    void InitialVariables();
protected:
   sf::Sprite sprite;
   ComponentBox* componentBox;
   Movement* movement;
   AnimationManager* animation;
 //float onGround;
public :
    Entity();
   virtual ~Entity();
    bool onGround;
    void setTexture(sf::Texture& texture);
    void CreateHitbox(sf::Sprite& sprite,float offset_x,float  offset_y,float width,float height);
    void Createmovement(const float maxSpeed,const float acceleration,const float deceleration);
    void CreateAnimation(sf::Texture& texture_sheet);
    //functions
   void checkCollisionWithMap(float dx,float dy);
    virtual void setPosition(const float x,const float y);
   virtual void move( const float x,const float y,const float& deltaT);

  virtual  void update(const float& deltaT);
  virtual void render(sf::RenderTarget& target);
};


#endif //HANAMI_GAME_ENTITY_H
