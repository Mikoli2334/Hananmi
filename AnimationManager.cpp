
#include "AnimationManager.h"

AnimationManager::AnimationManager(sf::Sprite* sprite, sf::Texture* textureSheet)
        : sprite(sprite), textureSheet(textureSheet), animationTimer(0), timer(0), done(false) {
}

AnimationManager::~AnimationManager() {
}

void AnimationManager::addAnimation(const std::string& key, float animation_timer, int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height) {
    this->animations[key] = sf::IntRect(start_frame_x * width, start_frame_y * height, width * frames_x, height * frames_y);
    this->animationTimer = animation_timer;
    this->startRect = this->animations[key];
    this->currentRect = this->startRect;
}

bool AnimationManager::play(const std::string& key, float dt, bool priority) {
    if (this->animations.find(key) != this->animations.end()) {
        if (priority || this->sprite->getTextureRect() != this->animations[key]) {
            if (this->timer > this->animationTimer) {
                this->timer = 0.f;
                if (this->currentRect != this->animations[key]) {
                    this->currentRect = this->animations[key];
                }
                else {
                    this->currentRect.left += this->currentRect.width;
                    if (this->currentRect.left >= this->startRect.left + this->startRect.width) {
                        this->currentRect.left = this->startRect.left;
                        done = true;
                    }
                }
                this->sprite->setTextureRect(this->currentRect);
            }
            else {
                this->timer += 100.f * dt;
            }
        }
        return done;
    }
    return false;
}
