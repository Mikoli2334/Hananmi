#include "Player.h"

Player::Player(float x, float y, sf::Texture& texture_sheet) {
    this->setPosition(x, y);
    this->health = 100;
    this->attackDamage = 10;
    this->attackCooldown = sf::seconds(1);
    this->attackRange = 50.f;
    this->CreateAnimation(texture_sheet);
    this->CreateHitbox(this->sprite, 0.f, 0.f, 22.f, 32.f);
    this->Createmovement(200.f, 10.f, 4.f);
    this->animation->addAnimation("IDLE_LEFT", 10.f, 0, 0, 5, 0, 22, 32);
}

Player::~Player() {

}

void Player::attack(std::vector<Monster*>& monsters) {
    if (attackTimer.getElapsedTime() >= attackCooldown) {
        for (auto& monster : monsters) {
            if (this->sprite.getGlobalBounds().intersects(monster->getGlobalBounds())) {
                monster->decreaseHealth(attackDamage);
            }
        }
        attackTimer.restart();
    }
}

void Player::decreaseHealth(int damage) {
    health -= damage;

    if (health <= 0) {
        std::cout << "Player died." << std::endl;

        this->animation->play("DIE", deltaTime);

        sf::SoundBuffer deathSoundBuffer;
        if (!deathSoundBuffer.loadFromFile("path/to/death_sound.ogg")) {
            std::cerr << "Failed to load death sound." << std::endl;
        }
        sf::Sound deathSound;
        deathSound.setBuffer(deathSoundBuffer);
        deathSound.play();

        Game::changeState(GameState::GameOver);
    }
}


void Player::update(const float& deltaT, const sf::RenderWindow& window) {
    this->movement->update(deltaT);
    if (this->movement->getState(IDLE))
        this->animation->play("IDLE_LEFT", deltaT);
    else if (this->movement->getState(MOVING_LEFT))
        this->animation->play("WALK_LEFT", deltaT);

    this->componentBox->update();
}
