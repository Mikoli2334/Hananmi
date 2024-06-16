#include "Monster.h"

Monster::Monster(float x, float y, sf::Texture& texture_sheet) : texture(texture_sheet) {
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(x, y);
    this->sprite.setScale(0.5f, 0.5f);
    initializeVariables();
    initializeAnimations();
    initializeSound();
}

void Monster::initializeVariables() {
    this->health = 100;
    this->movementSpeed = 100.f;
    this->direction = sf::Vector2f(0.f, 0.f);
}


void Monster::initializeSound() {
    if (!deathSoundBuffer.loadFromFile("path/to/monster_death_sound.ogg")) {
        std::cerr << "Failed to load death sound." << std::endl;
    } else {
        deathSound.setBuffer(deathSoundBuffer);
    }
}

Monster::~Monster() {
}

void Monster::decreaseHealth(int damage) {
    health -= damage;
    if (health <= 0) {
        std::cout << "Monster died." << std::endl;
        deathSound.play();
    }
}

bool Monster::isAlive() const {
    return health > 0;
}

void Monster::update(const float& dt, const sf::Vector2f& playerPosition) {
    sf::Vector2f movementDirection = playerPosition - this->sprite.getPosition();
    float length = std::sqrt(std::pow(movementDirection.x, 2) + std::pow(movementDirection.y, 2));
    movementDirection /= length; // Нормализация вектора
    move(movementDirection * dt);
}

void Monster::move(const sf::Vector2f& moveDirection) {
    this->sprite.move(moveDirection * this->movementSpeed);
}


void Monster::initializeAnimations() {
    this->animation =new  AnimationManager(&this->sprite, &this->texture);


    this->animation->addAnimation("WALK", 50.f, 0, 0, 3, 0, 48, 48);
    this->animation->addAnimation("DIE", 70.f, 0, 1, 5, 1, 48, 48);
}
