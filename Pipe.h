#pragma once
#include <SFML/Graphics.hpp>

struct Pipe 
{
    sf::RectangleShape top;
    sf::RectangleShape bottom;
    bool passed = false;

    // Configures and sets up a pair of pipes based on given screen parameters
    void init(float width, float height, float pipeWidth, float gapHeight, float gapY);
    // Moves both pipes to the left
    void move(float speed);
    // Draws both pipes to the screen
    void draw(sf::RenderWindow& window) const;
};