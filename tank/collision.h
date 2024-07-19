#include <iostream>
#include <SDL.h>

bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);

void keepInWindow(SDL_Rect& obj1, SDL_Rect& obj2, int width, int height);

void collision(SDL_Rect& obj1, SDL_Rect& obj2);


