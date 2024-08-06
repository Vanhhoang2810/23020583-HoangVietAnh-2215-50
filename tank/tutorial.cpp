#include "tutorial.h"
#include "menu.h"

bool showTutorial(SDL_Renderer* renderer, TTF_Font* font) {
    SDL_Color textColor = { 255, 255, 255, 255 };
    bool tutorialRunning = true;
    SDL_Event event;
    SDL_Rect back;

    while (tutorialRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return false;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                SDL_Point mousePoint = {x, y};
                if (SDL_PointInRect(&mousePoint, &back)) {
                    return true;
                }
            }
        }

        SDL_RenderClear(renderer);
        renderText(renderer, "How to Play", font, textColor, 50, NULL);

        renderText(renderer, "Player 1:", font, textColor, 100, NULL);
        renderText(renderer, "WASD - Move", font, textColor, 150, NULL);
        renderText(renderer, "SPACE - Shoot", font, textColor, 200, NULL);

        renderText(renderer, "Player 2 Controls:", font, textColor, 400, NULL);
        renderText(renderer, "Arrow Keys - Move", font, textColor, 450, NULL);
        renderText(renderer, "Numpad 1 - Shoot", font, textColor, 500, NULL);

        renderText(renderer, "Click here to go back", font, textColor, 600, &back);
        SDL_RenderPresent(renderer);
    }

    return false;
}

