#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

using namespace std;

extern const int SCREEN_HEIGHT, SCREEN_WIDTH;`

void renderScores(SDL_Renderer* renderer, TTF_Font* font, int score1, int score2);
