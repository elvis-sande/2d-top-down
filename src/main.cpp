#include "game.h"
#include <SDL2/SDL_video.h>

Game *game = nullptr;

int main(int argc, char const *argv[])
{
    game = new Game();

    game -> init("2d-game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while(game -> running()) {    // if the game is running,
        game -> handleEvents();
        game -> update();
        game -> render();
    
    }

    game -> clean();

    return 0;
}
