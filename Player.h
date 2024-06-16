#ifndef HANAMI_GAME_PLAYER_H
#define HANAMI_GAME_PLAYER_H
#include "Entity.h"
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include "Map.h"

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Monster.h"

class Player : public Entity {
private:
    int health;
    int attackDamage;
    float attackRange;
    sf::Clock attackTimer;
    sf::Time attackCooldown;

public:
    Player(float x, float y, sf::Texture& texture_sheet);
    virtual ~Player();

    void attack(std::vector<Monster*>& monsters);
    void decreaseHealth(int damage);
    void update(const float& deltaT, const sf::RenderWindow& window);
};

#endif // HANAMI_GAME_PLAYER_H
