//
// Created by Asus on 12.06.2024.
//

#include "Animation.h"

Animation::Animation(sf::Sprite& sprite,sf::Texture& texture_sheet):
        sprite(sprite),textureSheet(texture_sheet),lastAnimation(NULL)
{

}

Animation::~Animation() {
    for(auto &i:this->animations){
        delete i.second;
    }
}



void Animation::addAnimation(const std::string key,
                             float animationTimer, int startFrameX,
                             int startFrameY, int framesX, int framesY, int width, int height) {
    this->animations[key] =new AnimationComponent(sprite, textureSheet, animationTimer, startFrameX, startFrameY, framesX, framesY, width, height);
}

//void Animation::play(const std::string key, const float &dt) {
//    if(this->lastAnimation!=this->animations[key]) {
//      if(this->lastAnimation==NULL)
//          this->lastAnimation = this->animations[key];
//          else
//          {
//              this->lastAnimation->reset();
//              this->lastAnimation = this->animations[key];
//          }
//
//    }
//    this->animations[key]->play(dt);
//
//}
void Animation::play(const std::string key,const float& dt) {
    if(this->lastAnimation!=this->animations[key]) {
        if(this->lastAnimation==NULL)
            this->lastAnimation = this->animations[key];
        else
        {
            this->lastAnimation->reset();
            this->lastAnimation = this->animations[key];
        }

    }
   if (this->animations[key] != nullptr) {
        this->animations[key]->play(dt);
    }

}