#pragma once
#include <SFML/Graphics.hpp>

class Ball 
{
private:
    sf::CircleShape shape;
    float velocity;
    const float gravity = 0.4f;
    const float jumpStrength = -7.5f;

public:
    Ball();
    void reset(float x, float y);
    void update();
    void jump();
    
    sf::FloatRect getBounds() const;
    sf::Vector2f getPosition() const;
    void draw(sf::RenderWindow& window) const;
};