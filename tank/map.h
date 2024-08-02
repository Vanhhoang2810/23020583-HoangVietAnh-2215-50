#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

using namespace std;

extern vector<SDL_Rect> hWalls;
extern vector<SDL_Rect> vWalls;
extern const int CELL_SIZE;
extern SDL_Texture* hWallTex;
extern SDL_Texture* vWallTex;



void initMaze();

void renderMaze(SDL_Renderer* renderer);
