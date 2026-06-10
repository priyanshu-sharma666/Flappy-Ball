#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"
#include "Pipe.h"

class Game 
{
private:
    const int WIDTH = 400;
    const int HEIGHT = 600;
    
    sf::RenderWindow window;
    Ball ball;
    std::vector<Pipe> pipes;
    sf::Clock pipeClock;
    
    sf::Font font;
    sf::Text scoreText;
    sf::Text gameOverText;
    
    int score;
    bool isGameOver;

    const float pipeWidth = 70.f;
    const float gapHeight = 150.f;
    const float pipeSpeed = 3.5f;

    void handleEvents();
    void update();
    void render();
    void spawnPipes();
    void reset();

public:
    Game();
    bool init();
    void run();
};