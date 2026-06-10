#include "Pipe.h"

void Pipe::init(float width, float height, float pipeWidth, float gapHeight, float gapY) 
{
    // Top Pipe
    top.setSize(sf::Vector2f(pipeWidth, gapY - gapHeight / 2.f));
    top.setFillColor(sf::Color(45, 200, 45));
    top.setOutlineColor(sf::Color::Black);
    top.setOutlineThickness(2.f);
    top.setPosition(width, -2.f);

    // Bottom Pipe
    float bottomPipeY = gapY + gapHeight / 2.f;
    bottom.setSize(sf::Vector2f(pipeWidth, height - bottomPipeY + 2.f));
    bottom.setFillColor(sf::Color(45, 200, 45));
    bottom.setOutlineColor(sf::Color::Black);
    bottom.setOutlineThickness(2.f);
    bottom.setPosition(width, bottomPipeY);
    
    passed = false;
}

void Pipe::move(float speed) 
{
    top.move(-speed, 0.f);
    bottom.move(-speed, 0.f);
}

void Pipe::draw(sf::RenderWindow& window) const 
{
    window.draw(top);
    window.draw(bottom);
}