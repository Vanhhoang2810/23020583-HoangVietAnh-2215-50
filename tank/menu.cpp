#include "menu.h"

void renderText(SDL_Renderer* renderer, const string &text, TTF_Font* font, SDL_Color color, int x, int y) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect = {x, y, textSurface->w, textSurface->h};
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

bool showMenu(SDL_Renderer* renderer, TTF_Font* font) {
    SDL_Color textColor = { 255, 255, 255, 255 };
    bool menuRunning = true;
    SDL_Event event;

    while (menuRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return false;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_KP_1:
                        return true;
                    case SDLK_KP_2:
                        return false;
                }
            }
        }

        SDL_RenderClear(renderer);
        renderText(renderer, "Tank Trouble", font, textColor, 320, 180);
        renderText(renderer, "1. Start Game", font, textColor, 320, 360);
        renderText(renderer, "2. Exit", font, textColor, 320, 410);
        SDL_RenderPresent(renderer);
    }

    return false;
}
