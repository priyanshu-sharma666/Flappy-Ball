#include "Ball.h"

Ball::Ball() : velocity(0.f) 
{
    shape.setRadius(15.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(2.f);
    shape.setOrigin(15.f, 15.f);
    reset(100.f, 300.f);
}

void Ball::reset(float x, float y) 
{
    shape.setPosition(x, y);
    velocity = 0.f;
}

void Ball::update() 
{
    velocity += gravity;
    shape.move(0.f, velocity);
}

void Ball::jump() 
{
    velocity = jumpStrength;
}

sf::FloatRect Ball::getBounds() const 
{
    return shape.getGlobalBounds();
}

sf::Vector2f Ball::getPosition() const 
{
    return shape.getPosition();
}

void Ball::draw(sf::RenderWindow& window) const 
{
    window.draw(shape);
}