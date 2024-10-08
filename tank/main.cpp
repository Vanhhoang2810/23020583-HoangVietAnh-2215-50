#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <SDL_ttf.h>
#include "Control.h"
#include "collision.h"
#include "bullets.h"
#include "point.h"
#include "menu.h"
#include "end.h"
#include "map.h"
#include "tutorial.h"

using namespace std;

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 720;
const int MOVE_SPEED_1 = 2;
const int MOVE_SPEED_2 = 4;
const int FIRE_RATE = 200;
const int CELL_SIZE = 80;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Rect dstTank1, dstTank2;
SDL_Texture* background = NULL;
SDL_Texture* tank1 = NULL;
SDL_Texture* tank2 = NULL;
SDL_Texture* bulletTex = NULL;
SDL_Texture* hWallTex = NULL;
SDL_Texture* vWallTex = NULL;

bool up1 = false;
bool down1 = false;
bool left1 = false;
bool right1 = false;
bool shoot1 = false;
bool shield1 = false;

bool up2 = false;
bool down2 = false;
bool left2 = false;
bool right2 = false;
bool shoot2 = false;
bool shield2 = false;

int timer1 = 0, timer2 = 0;
int point1 = 0, point2 = 0;
int tank1Angle = 0, tank2Angle = 0;

vector<Bullet> bullets;
vector<SDL_Rect> hWalls;
vector<SDL_Rect> vWalls;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
    SDL_SetWindowTitle(window, "Tank Trouble");

    TTF_Init();
    TTF_Font* font = TTF_OpenFont("font/Peepo.ttf", 18);
    TTF_Font* menuFont = TTF_OpenFont("font/Peepo.ttf", 25);

    if (!showMenu(renderer, menuFont)) {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        TTF_CloseFont(font);
        TTF_CloseFont(menuFont);
        TTF_Quit();
        SDL_Quit();
        return 0;
    }

    background = IMG_LoadTexture(renderer, "img/background.png");
    tank1 = IMG_LoadTexture(renderer, "img/tank1.png");
    tank2 = IMG_LoadTexture(renderer, "img/tank2.png");
    bulletTex = IMG_LoadTexture(renderer, "img/bullet.png");
    hWallTex = IMG_LoadTexture(renderer, "img/hWall.png");
    vWallTex = IMG_LoadTexture(renderer, "img/vWall.png");

    dstTank1.x = 20;
    dstTank1.y = SCREEN_HEIGHT / 2 - 32;
    dstTank1.w = dstTank1.h = 64;
    tank1Angle = 90;

    dstTank2.x = SCREEN_WIDTH - 84;
    dstTank2.y = SCREEN_HEIGHT / 2 - 32;
    dstTank2.w = dstTank2.h = 64;
    tank2Angle = 270;

    int past = SDL_GetTicks();

    initMaze();

    SDL_Event ev;

    while (true) {
        if (!inputHandling(ev)) {
            break;
        }

        int now = SDL_GetTicks();
        if (now - past >= 10) {
            if (up1) {
                dstTank1.y -= MOVE_SPEED_1;
                tank1Angle = 0;
                if (checkMazeCollision(dstTank1)) {
                    dstTank1.y += MOVE_SPEED_1;
                }
            } else if (down1) {
                dstTank1.y += MOVE_SPEED_1;
                tank1Angle = 180;
                if (checkMazeCollision(dstTank1)) {
                    dstTank1.y -= MOVE_SPEED_1;
                }
            } else if (left1) {
                dstTank1.x -= MOVE_SPEED_1;
                tank1Angle = 270;
                if (checkMazeCollision(dstTank1)) {
                    dstTank1.x += MOVE_SPEED_1;
                }
            } else if (right1) {
                dstTank1.x += MOVE_SPEED_1;
                tank1Angle = 90;
                if (checkMazeCollision(dstTank1)) {
                    dstTank1.x -= MOVE_SPEED_1;
                }
            }
            if (up2) {
                dstTank2.y -= MOVE_SPEED_2;
                tank2Angle = 0;
                if (checkMazeCollision(dstTank2)) {
                    dstTank2.y += MOVE_SPEED_2;
                }
            } else if (down2) {
                dstTank2.y += MOVE_SPEED_2;
                tank2Angle = 180;
                if (checkMazeCollision(dstTank2)) {
                    dstTank2.y -= MOVE_SPEED_2;
                }
            } else if (left2) {
                dstTank2.x -= MOVE_SPEED_2;
                tank2Angle = 270;
                if (checkMazeCollision(dstTank2)) {
                    dstTank2.x += MOVE_SPEED_2;
                }
            } else if (right2) {
                dstTank2.x += MOVE_SPEED_2;
                tank2Angle = 90;
                if (checkMazeCollision(dstTank2)) {
                    dstTank2.x -= MOVE_SPEED_2;
                }
            }

            if (shoot1){
                shootBullet(dstTank1.x, dstTank1.y, tank1Angle, timer1, 1);
            }
            if (shoot2) {
                shootBullet(dstTank2.x, dstTank2.y, tank2Angle, timer2, 2);
            }
            updateBullet(SCREEN_WIDTH, SCREEN_HEIGHT);
            bulletCollision();

            if (point1 == 5) {
                if (showEnd(renderer, menuFont, "Tank 1 Wins!")) {
                    resetGame();
                } else {
                    break;
                }
            } else if (point2 == 5) {
                if (showEnd(renderer, menuFont, "Tank 2 Wins!")) {
                    resetGame();
                } else {
                    break;
                }
            }

            past = now;
            timer1 += 10;
            timer2 += 10;
        }

        keepInWindow(dstTank1, dstTank2, SCREEN_WIDTH, SCREEN_HEIGHT);
        if (checkCollision(dstTank1, dstTank2)) {
            collision(dstTank1, dstTank2);
        }



        SDL_RenderCopy(renderer, background, NULL, NULL);
        SDL_RenderCopyEx(renderer, tank1, NULL, &dstTank1, tank1Angle, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(renderer, tank2, NULL, &dstTank2, tank2Angle, NULL, SDL_FLIP_NONE);

        renderMaze(renderer);

        renderScores(renderer, font, point1, point2);

        renderBullet();

        SDL_RenderPresent(renderer);

        SDL_Delay(10);
    }


    SDL_DestroyTexture(background);
    SDL_DestroyTexture(tank1);
    SDL_DestroyTexture(tank2);
    SDL_DestroyTexture(bulletTex);
    SDL_DestroyTexture(hWallTex);
    SDL_DestroyTexture(vWallTex);


    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    TTF_CloseFont(font);
    TTF_CloseFont(menuFont);

    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
    return 0;
}
