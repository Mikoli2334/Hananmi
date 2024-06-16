#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

class AnimationManager {
private:
    sf::Sprite* sprite;
    sf::Texture* textureSheet;
    std::map<std::string, sf::IntRect> animations;
    float animationTimer;
    float timer;
    bool done;
    sf::IntRect startRect;
    sf::IntRect currentRect;

public:
    AnimationManager(sf::Sprite* sprite, sf::Texture* textureSheet);
    virtual ~AnimationManager();

    void addAnimation(const std::string& key, float animation_timer, int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height);
    bool play(const std::string& key, float dt, bool priority = false);
};

#endif
