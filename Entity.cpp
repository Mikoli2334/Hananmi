//
// Created by Asus on 20.05.2024.
//

#include "Entity.h"
void Entity::InitialVariables() {
    this->componentBox=NULL;
    this->movement=NULL;
    this->animation=NULL;
    //this->onGround= false;
}
Entity::Entity() {
    this->InitialVariables();
    //временный появления поинт

}

Entity::~Entity() {
    delete this->componentBox;
    delete this->movement;
    delete this->animation;

}

void Entity::setTexture(sf::Texture& texture) {

    this->sprite.setTexture(texture);
}
void Entity::CreateHitbox(sf::Sprite &sprite,float offset_x,float  offset_y,float width,float height) {
this->componentBox=new ComponentBox(sprite,offset_x,offset_y,width,height);
}
void Entity::Createmovement(const float maxSpeed,const float acceleration,const float deceleration) {
    this->movement=new Movement(this->sprite,maxSpeed,acceleration,deceleration);
}

void Entity::setPosition(float x, float y) {
    this->sprite.setPosition(x,y);
}
void Entity::move( const float dir_x, const float dir_y,const float &deltaT) {
    if(this->movement) {
        this->movement->move(dir_x,dir_y,deltaT);//sets velocity
        // this->movement->update(deltaT);

    }
}

void Entity::update(const float &deltaT) {
if(this->movement)
    this->movement->update(deltaT);
    if (this->componentBox) {
        //  проверяем, вызывается ли componentBox->update()
        std::cout << "Обновление hitbox ..." << std::endl;
        this->componentBox->update();
    }
}
void Entity::render(sf::RenderTarget& target) {

    target.draw(this->sprite);
    if(this->componentBox)
        this->componentBox->render(target);
}

void Entity::CreateAnimation( sf::Texture &texture_sheet) {
    this->animation= new Animation(sprite, texture_sheet));
}







