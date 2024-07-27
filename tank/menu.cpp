#include "menu.h"

void renderText(SDL_Renderer* renderer, const string &text, TTF_Font* font, SDL_Color color, int x, int y, SDL_Rect* rect) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect = {x, y, textSurface->w, textSurface->h};
    if (rect) {
        *rect = textRect;
    }
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

bool showMenu(SDL_Renderer* renderer, TTF_Font* font) {
    SDL_Color textColor = { 255, 255, 255, 255 };
    bool menuRunning = true;
    SDL_Event event;
    SDL_Rect start, exit;

    while (menuRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return false;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                SDL_Point mousePoint = {x, y};
                if (SDL_PointInRect(&mousePoint, &start)) {
                    return true;
                }
                if (SDL_PointInRect(&mousePoint, &exit)) {
                    return false;
                }
            }
        }

        SDL_RenderClear(renderer);
        renderText(renderer, "Tank Trouble", font, textColor, 320, 180);
        renderText(renderer, "1. Start Game", font, textColor, 320, 360, &start);
        renderText(renderer, "2. Exit", font, textColor, 320, 410, &exit);
        SDL_RenderPresent(renderer);
    }

    return false;
}
