#include "map.h"

int maze[9][9];

void initMaze() {
    // Define walls using a grid
    int maze[9][9] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1},
        {0, 0, 1, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (maze[i][j] == 1) {
                if (i % 2 == 0) {
                    hWalls.push_back({ j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE });
                } else {
                    vWalls.push_back({ j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE });
                }
            }
        }
    }
}

bool checkMazeCollision(const SDL_Rect& rect) {
    for (const SDL_Rect& wall : hWalls) {
        if (SDL_HasIntersection(&rect, &wall)) {
            return true;
        }
    }
    for (const SDL_Rect& wall : vWalls) {
        if (SDL_HasIntersection(&rect, &wall)) {
            return true;
        }
    }
    return false;
}



void renderMaze(SDL_Renderer* renderer) {
    for (const SDL_Rect& wall : hWalls) {
        SDL_RenderCopy(renderer, hWallTex, NULL, &wall);
    }
    for (const SDL_Rect& wall : vWalls) {
        SDL_RenderCopy(renderer, vWallTex, NULL, &wall);
    }
}

