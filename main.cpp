#include <iostream>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Surface* gSurface = NULL;

bool init();
bool loadMedia();
void close();

int main(int argc, char* args[]) {
    init();    

    return 0;
}

bool init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("%s", SDL_GetError());
        success = false;
    } else {
        gWindow = SDL_CreateWindow("Nome da janela", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (gWindow == NULL) {
            printf("%s", SDL_GetError());
            success = false;
        } else {
            gSurface = SDL_GetWindowSurface(gWindow);

            SDL_FillRect(gSurface, NULL, SDL_MapRGB(gSurface -> format, 0xFF, 0xFF, 0xFF));

            SDL_UpdateWindowSurface(gWindow);

            SDL_Event e; bool quit = false; while (quit == false) { while(SDL_PollEvent(&e)) { if(e.type == SDL_QUIT) quit = true; } } 

            close();
        }
    }
    

    return success;
}

bool loadMedia() {
    bool success = true;

    return success;
}

void close() {
    SDL_DestroyWindow(gWindow);

    SDL_Quit();
}