//
// Created by Asus on 01.06.2024.
//

#include "Movement.h"

Movement::Movement(sf::Sprite& sprite,float maxVelocity,
                   float acceleration,float deceleration)
:sprite(sprite),
maxVelocity(maxVelocity),acceleration(acceleration),deceleration(deceleration)
{

}

Movement::~Movement() {

}
const sf::Vector2f &Movement::getVelocity() const {
    return this->velocity;
}
void Movement::move(const float direction_x, const float direction_y, const float& deltaT) {
    // Apply acceleration
    this->velocity.x += this->acceleration * direction_x;
    this->velocity.y += this->acceleration * direction_y;

    // Limit the velocity to maxVelocity
//    if (std::abs(this->velocity.x) > this->maxVelocity) {
//        this->velocity.x = this->maxVelocity * (this->velocity.x / std::abs(this->velocity.x));
//    }
//    if (std::abs(this->velocity.y) > this->maxVelocity) {
//        this->velocity.y = this->maxVelocity * (this->velocity.y / std::abs(this->velocity.y));
//    }

    // Move the sprite
   //d this->sprite.move(this->velocity * deltaT);
}

void Movement::update(const float &deltaT) {
    // Apply deceleration
    if (this->velocity.x > 0.f)
    {

        if (this->velocity.x > this->maxVelocity)
            this->velocity.x = this->maxVelocity;

        this->velocity.x-=deceleration;
        if (this->velocity.x < 0.f)
            this->velocity.x = 0.f;

    }
    else  if (this->velocity.x < 0.f)
    {
        if (this->velocity.x <-this->maxVelocity)
            this->velocity.x = -this->maxVelocity;

        this->velocity.x+=deceleration;
        if (this->velocity.x > 0.f)
            this->velocity.x = 0.f;
    }


    if (this->velocity.y > 0.f)
    {

        if (this->velocity.y > this->maxVelocity)
            this->velocity.y = this->maxVelocity;

        this->velocity.y-=deceleration;
        if (this->velocity.y < 0.f)
            this->velocity.y = 0.f;

    }
    else  if (this->velocity.x < 0.f)
    {
        if (this->velocity.y <-this->maxVelocity)
            this->velocity.y = -this->maxVelocity;

        this->velocity.y+=deceleration;
        if (this->velocity.y > 0.f)
            this->velocity.y = 0.f;
    }

    // Move the sprite
    this->sprite.move(this->velocity * deltaT);
}


const bool Movement::getState(const unsigned short state) const {
    switch(state){
        case IDL:
            if(this->velocity.x==0.f && this->velocity.y==0.f)
                return true;
            break;
        case MOVING:
            if(this->velocity.x!=0.f || this->velocity.y!=0.f)
                return true;
            break;
        case MOVING_LEFT:
            if(this->velocity.x<0.f )
                return true;

            break;
        case MOVING_RIGHT:
            if( this->velocity.x>0.f)
                return true;
            break;
        case MOVING_DOWN:
            if( this->velocity.y>0.f)
                return true;
            break;
        case MOVING_UP:
            if( this->velocity.y<0.f)
                return true;
            break;
        default:
            break;
    }
    return false;
}

//const float &Movement::getMaxVelocity() const {
//    return maxVelocity;
//}




