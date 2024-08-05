#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

using namespace std;

void renderText(SDL_Renderer* renderer, const string &text, TTF_Font* font, SDL_Color color, int y, SDL_Rect* rect);
bool showMenu(SDL_Renderer* renderer, TTF_Font* font);

