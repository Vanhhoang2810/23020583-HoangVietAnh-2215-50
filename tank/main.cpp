#include <iostream>
#include <SDL.h>

using namespace std;

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 720;

SDL_Window* window;
SDL_Renderer* renderer;


int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
    SDL_SetWindowTitle(window, "Tank Trouble");

    SDL_Event ev;
    bool run = true;
    while (run) {
        while (SDL_PollEvent(&ev)) {
            switch(ev.type) {
                case SDL_QUIT:
                run = false;
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_QUIT;

}
