#include "end.h"

bool showEnd(SDL_Renderer* renderer, TTF_Font* font, const string &message) {
    SDL_Color textColor = { 255, 255, 255, 255 };
    bool endScreenRunning = true;
    SDL_Event event;
    SDL_Rect replay, exit;

    while (endScreenRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return false;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                SDL_Point mousePoint = {x, y};
                if (SDL_PointInRect(&mousePoint, &replay)) {
                    return true;
                }
                if (SDL_PointInRect(&mousePoint, &exit)) {
                    return false;
                }
            }
        }

        SDL_RenderClear(renderer);
        renderText(renderer, message, font, textColor, 180, NULL);
        renderText(renderer, "Replay?", font, textColor, 360, &replay);
        renderText(renderer, "Exit", font, textColor, 410, &exit);
        SDL_RenderPresent(renderer);
    }

    return false;
}
