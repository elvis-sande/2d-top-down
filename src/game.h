#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();  // Memory management, clear Game() from mem

    bool running() { return isRunning; }

private:
    int countr = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

};

#endif // GAME_H_