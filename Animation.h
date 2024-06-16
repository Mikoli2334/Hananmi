#include <iostream>
#include <string>
#include <map>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

#ifndef HANAMI_GAME_ANIMATION_H
#define HANAMI_GAME_ANIMATION_H


class Animation {
private:
    class AnimationComponent{
    public:
        sf::Sprite& sprite;
        sf::Texture& textureSheet;
        float Animationtimer;
        float timer;
        int width;
        int height;
        sf::IntRect  Startrect;
        sf::IntRect currentRec;
        sf::IntRect EndRect;
        AnimationComponent(sf::Sprite& sprite,sf::Texture& textureSheet,float animationTimer,
                           int start_frames_x,int start_frames_y,int frames_x,int frames_y,
                           int width,int height):
                sprite(sprite),textureSheet(textureSheet),Animationtimer(animationTimer),width(width),height(height)
        {
            this->timer=0.f;
            this->Startrect=sf::IntRect(start_frames_x*width,start_frames_y*height,width,height);
            this->currentRec=this->Startrect;
            this->EndRect=sf::IntRect(frames_x*width,frames_y*height,width,height);
            this->sprite.setTexture(this->textureSheet,true);
            this->sprite.setTextureRect(this->Startrect);
        };
        void play(const float& dt){
            this->timer+=100.f*dt;
            if(this->timer>=this->Animationtimer){
                this->timer=0.f;
                if(this->currentRec!=this->EndRect){
                    this->currentRec.left+=this->width;
                }else//reset
                {
                    this->currentRec.left+=this->Startrect.left;
                }
                this->sprite.setTextureRect(this->currentRec);
            }
        }
//        void play(const float& dt,const float& modifier,const float& modifier_max ){
//            this->timer+=(modifier/modifier_max)*100.f*dt;
//            if(this->timer>=this->Animationtimer){
//                this->timer=0.f;
//                if(this->currentRec!=this->EndRect){
//                    this->currentRec.left+=this->width;
//                }else//reset
//                {
//                    this->currentRec.left+=this->Startrect.left;
//                }
//                this->sprite.setTextureRect(this->currentRec);
//            }
//        }
//
        void reset(){
            this->timer=0.f;
            this->currentRec=this->Startrect;
        }
  };
    sf::Sprite& sprite;
    sf::Texture& textureSheet;
    std::map<std::string,AnimationComponent*> animations;
    AnimationComponent* lastAnimation;

public:

    Animation(sf::Sprite& sprite,sf::Texture& texture_sheet);
    virtual ~Animation();


    void addAnimation(const std::string key, float animationTimer, int startFrameX, int startFrameY, int framesX, int framesY, int width, int height);
    void play(const std::string key,const float& dt);
    //void play(const std::string key,const float& dt,const float& modifier,const float& modifier_max);
};


#endif //HANAMI_GAME_ANIMATION_H