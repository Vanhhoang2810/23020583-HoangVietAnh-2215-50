#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "map.h"
using namespace std;

extern void renderText(SDL_Renderer* renderer, const string &text, TTF_Font* font, SDL_Color color, int y, SDL_Rect* rect);
extern SDL_Rect dstTank1, dstTank2;
extern const int SCREEN_HEIGHT, SCREEN_WIDTH;
extern int tank1Angle, tank2Angle;
extern int point1, point2;

bool showEnd(SDL_Renderer* renderer, TTF_Font* font, const string &message);

void resetGame();
