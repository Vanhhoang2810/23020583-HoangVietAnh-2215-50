#include "end.h"
#include "bullets.h"
#include "menu.h"

extern vector<Bullet> bullets;

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

void resetGame() {
    dstTank1.x = 0;
    dstTank1.y = SCREEN_HEIGHT / 2;
    dstTank1.w = dstTank1.h = 64;
    tank1Angle = 90;

    dstTank2.x = SCREEN_WIDTH - 64;
    dstTank2.y = SCREEN_HEIGHT / 2;
    dstTank2.w = dstTank2.h = 64;
    tank2Angle = 270;

    point1 = 0;
    point2 = 0;
    bullets.clear();
    initMaze();
}
