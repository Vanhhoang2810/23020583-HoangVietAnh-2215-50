#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

using namespace std;

void renderText(SDL_Renderer* renderer, const string &text, TTF_Font* font, SDL_Color color, int x, int y, SDL_Rect* rect = nullptr);

bool showMenu(SDL_Renderer* renderer, TTF_Font* font);

