#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <string>

Game::Game() : 
    window(sf::VideoMode(400, 600), "Flappy Ball"), 
    score(0), 
    isGameOver(false) 
{
    window.setFramerateLimit(60);
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

bool Game::init() 
{
    if (!font.loadFromFile("E:/Game/arial-black.ttf")) 
    {
        return false;
    }

    // Score UI
    scoreText.setFont(font);
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setOutlineColor(sf::Color::Black);
    scoreText.setOutlineThickness(3.f);
    scoreText.setString("0");
    scoreText.setPosition(WIDTH / 2.f - scoreText.getGlobalBounds().width / 2.f, 50.f);

    // Game Over UI
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(30);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setOutlineColor(sf::Color::Black);
    gameOverText.setOutlineThickness(3.f);

    return true;
}

void Game::reset() 
{
    ball.reset(100.f, 300.f);
    score = 0;
    scoreText.setString("0");
    scoreText.setPosition(WIDTH / 2.f - scoreText.getGlobalBounds().width / 2.f, 50.f);
    pipes.clear();
    pipeClock.restart();
    isGameOver = false;
}

void Game::handleEvents() 
{
    sf::Event event;
    while (window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) 
        {
            if (!isGameOver) 
            {
                ball.jump();
            } 
            else 
            {
                reset();
            }
        }
    }
}

void Game::spawnPipes() 
{
    if (pipeClock.getElapsedTime().asSeconds() > 2.0f) 
    {
        pipeClock.restart();

        float minGapY = 130.f;
        float maxGapY = HEIGHT - 130.f;
        float gapY = minGapY + static_cast<float>(std::rand() % static_cast<int>(maxGapY - minGapY));

        Pipe pipe;
        pipe.init(WIDTH, HEIGHT, pipeWidth, gapHeight, gapY);
        pipes.push_back(pipe);
    }
}

void Game::update() 
{
    if (isGameOver) return;

    ball.update();
    spawnPipes();

    sf::FloatRect ballBounds = ball.getBounds();

    for (auto& pipe : pipes) 
    {
        pipe.move(pipeSpeed);

        // Check Pipe Collision
        if (ballBounds.intersects(pipe.top.getGlobalBounds()) || 
            ballBounds.intersects(pipe.bottom.getGlobalBounds())) 
        {
            isGameOver = true;
        }

        // Check Scoring
        if (!pipe.passed && ball.getPosition().x > pipe.top.getPosition().x + pipeWidth) 
        {
            pipe.passed = true;
            score++;
            scoreText.setString(std::to_string(score));
            scoreText.setPosition(WIDTH / 2.f - scoreText.getGlobalBounds().width / 2.f, 50.f);
        }
    }

    // Clean up offscreen pipes
    if (!pipes.empty() && pipes.front().top.getPosition().x + pipeWidth < 0) 
    {
        pipes.erase(pipes.begin());
    }

    // Boundary check
    if (ball.getPosition().y - 15.f < 0.f || ball.getPosition().y + 15.f > HEIGHT) 
    {
        isGameOver = true;
    }

    if (isGameOver) 
    {
        gameOverText.setString("GAME OVER\nSCORE: " + std::to_string(score) + "\nSPACE TO RESTART");
        gameOverText.setPosition(WIDTH / 2.f - gameOverText.getGlobalBounds().width / 2.f, HEIGHT / 2.f - gameOverText.getGlobalBounds().height / 2.f);
    }
}

void Game::render() 
{
    window.clear(sf::Color(110, 195, 235));

    for (const auto& pipe : pipes) 
    {
        pipe.draw(window);
    }
    ball.draw(window);

    if (!isGameOver) 
    {
        window.draw(scoreText);
    } 
    else 
    {
        window.draw(gameOverText);
    }

    window.display();
}

void Game::run() 
{
    while (window.isOpen()) 
    {
        handleEvents();
        update();
        render();
    }
}