#include "menu.h"
#include "tutorial.h"

bool showMenu(SDL_Renderer* renderer, TTF_Font* font) {
    SDL_Color textColor = { 255, 255, 255, 255 };
    bool menuRunning = true;
    SDL_Event event;
    SDL_Rect start, exit, help;

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
                if (SDL_PointInRect(&mousePoint, &help)) {
                    showTutorial(renderer, font);
                }
            }
        }

        SDL_RenderClear(renderer);
        renderText(renderer, "Tank Trouble", font, textColor, 180, NULL);
        renderText(renderer, "Start Game", font, textColor, 360, &start);
        renderText(renderer, "Help", font, textColor, 410 , &help);
        renderText(renderer, "Exit", font, textColor, 460, &exit);
        SDL_RenderPresent(renderer);
    }

    return false;
}

void renderText(SDL_Renderer* renderer, const string &text, TTF_Font* font, SDL_Color color, int y, SDL_Rect* rect) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    int x = (720 - textSurface->w) / 2;
    SDL_Rect textRect = {x, y, textSurface->w, textSurface->h};
    if (rect) {
        *rect = textRect;
    }
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

