

#include "Button.h"

Button::Button(float x,float y,float width,float height,
               sf::Font* font,std::string text,unsigned char_size,
               sf::Color idle_col,sf::Color hover_col,sf::Color active_col,
               sf::Color idlecol,sf::Color hovercol,sf::Color activecol) {
    this->buttonState=IDLE;
   this->shape.setSize(sf::Vector2f (width,height));
    this->shape.setFillColor(idlecol);
   this->shape.setPosition(sf::Vector2f (x,y));
   this->font=font;
   this->text.setFont(*this->font);
   this->text.setString(text);
   this->text.setFillColor(idle_col);
   this->text.setCharacterSize(char_size);
   this->text.setPosition(
           this->shape.getPosition().x+(this->shape.getGlobalBounds().width/2.f)-this->text.getGlobalBounds().width/2.f,
           this->shape.getPosition().y+(this->shape.getGlobalBounds().height/2.f)-this->text.getGlobalBounds().height/2.f
   );
   this->textActive=active_col;
   this->textHover=hover_col;
   this->textIdle=idle_col;
   this->idlecol=idlecol;
   this->activecol=activecol;
   this->hovercol=hovercol;

}
Button::~Button() {

}

void Button::render(sf::RenderTarget& target) {
target.draw(this->shape);
target.draw(this->text);
}

void Button::update( const sf::Vector2f mousePosition) {
    this->buttonState = IDLE;
    if (this->shape.getGlobalBounds().contains(mousePosition)) {
        this->buttonState = HOVER;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->buttonState = ACTIVE;
        }
    }
    switch (buttonState) {
        case IDLE:
            this->shape.setFillColor(this->idlecol);
            this->text.setFillColor(this->textIdle);
            break;
        case HOVER:
            this->shape.setFillColor(this->hovercol);
            this->text.setFillColor(this->textHover);
            break;
        case ACTIVE:
            this->shape.setFillColor(this->activecol);
            this->text.setFillColor(this->textActive);
            break;
        default:
            this->shape.
                    setFillColor(sf::Color::Red);
                this->text.setFillColor(sf::Color::Blue);
            break;
    }
}

const bool Button::isPressed() const {
    if(buttonState==ACTIVE){
        return true;
    }
    return false;
}

