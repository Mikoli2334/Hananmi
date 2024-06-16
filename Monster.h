#ifndef HANAMI_GAME_MONSTER_H
#define HANAMI_GAME_MONSTER_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include "AnimationManager.h"

class Monster : public Entity {
private:
    int health;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::SoundBuffer deathSoundBuffer;
    sf::Sound deathSound;
    float movementSpeed;
    sf::Vector2f direction;  // Добавлено направление движения
    sf::Clock animationClock;

    void initializeAnimations();
    void initializeSound();
    void initializeVariables();

public:
    Monster(float x, float y, sf::Texture& texture_sheet);
    virtual ~Monster();

    void decreaseHealth(int damage);
    bool isAlive() const;
    void update(const float& dt, const sf::Vector2f& playerPosition);
    void move(const sf::Vector2f& direction);  // Параметр изменен на вектор
};

#endif // HANAMI_GAME_MONSTER_H
