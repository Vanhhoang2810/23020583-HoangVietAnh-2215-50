#include "point.h"

void renderScores(SDL_Renderer* renderer, TTF_Font* font, int score1, int score2) {
    SDL_Color white = { 255, 255, 255 };

    SDL_Surface* scoreSurface1 = TTF_RenderText_Solid(font, ("Player 1: " + to_string(score1)).c_str(), white);
    SDL_Surface* scoreSurface2 = TTF_RenderText_Solid(font, ("Player 2: " + to_string(score2)).c_str(), white);

    SDL_Texture* scoreTexture1 = SDL_CreateTextureFromSurface(renderer, scoreSurface1);
    SDL_Texture* scoreTexture2 = SDL_CreateTextureFromSurface(renderer, scoreSurface2);

    SDL_Rect scoreRect1 = { 10, 10, scoreSurface1->w, scoreSurface1->h };
    SDL_Rect scoreRect2 = { SCREEN_WIDTH - scoreSurface2->w - 10, 10, scoreSurface2->w, scoreSurface2->h };

    SDL_RenderCopy(renderer, scoreTexture1, NULL, &scoreRect1);
    SDL_RenderCopy(renderer, scoreTexture2, NULL, &scoreRect2);

    SDL_FreeSurface(scoreSurface1);
    SDL_FreeSurface(scoreSurface2);
    SDL_DestroyTexture(scoreTexture1);
    SDL_DestroyTexture(scoreTexture2);
}
