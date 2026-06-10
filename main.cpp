#include "Game.h"

int main() 
{
    Game game;
    if (!game.init()) 
    {
        return -1; // Exits safely if font path fails
    }
    
    game.run();
    return 0;
}