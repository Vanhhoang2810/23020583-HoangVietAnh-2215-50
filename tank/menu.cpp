#include "menu.h"


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
        renderText(renderer, "Tank Trouble", font, textColor, 180, NULL);
        renderText(renderer, "Start Game", font, textColor, 360, &start);
        renderText(renderer, "Exit", font, textColor, 410, &exit);
        SDL_RenderPresent(renderer);
    }

    return false;
}

