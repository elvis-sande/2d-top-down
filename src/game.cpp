#include "game.h"
#include <SDL2/SDL_render.h>

SDL_Texture* playerTex;    // Pointer
SDL_Rect srcR, destR;      // Source rect and destination rect


Game::Game(){}
Game::~Game(){}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) 
{
    int flags = 0;
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Game initialized!" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "SDL window created." << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "SDL renderer created." << std::endl;
        }

        isRunning = true;
    }
    else {
        isRunning = false;
    }

    SDL_Surface* tmpSurface = IMG_Load("assets/bam.png");              // Texture initialized. first create surface
    playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);    // Make surface a texture
    SDL_FreeSurface(tmpSurface);                                       // Free surface

}

void Game::handleEvents(){
    
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    countr++;
    std::cout << countr << std::endl;

    destR.h = 64;
    destR.w = 64;
    destR.x = countr;

}

void Game::render(){    // This is where we add objects to render

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playerTex, NULL, &destR);  // Renderer, texture, source rect, destination rect
    SDL_RenderPresent(renderer);
}

void Game::clean(){

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "game clean exit" << std::endl;
}