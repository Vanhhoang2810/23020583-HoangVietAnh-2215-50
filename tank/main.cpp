#include <iostream>
#include <algorithm>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Control.h"
#include "collision.h"
#include "bullets.h"

using namespace std;

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 720;
const int MOVE_SPEED = 1;
const int FIRE_RATE = 200;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Rect dstTank1, dstTank2;
SDL_Texture* background = NULL;
SDL_Texture* tank1 = NULL;
SDL_Texture* tank2 = NULL;
SDL_Texture* bulletTex = NULL;

bool up1 = false;
bool down1 = false;
bool left1 = false;
bool right1 = false;
bool shoot1 = false;

bool up2 = false;
bool down2 = false;
bool left2 = false;
bool right2 = false;
bool shoot2 = false;

int timer1 = 0, timer2 = 0;


int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
    SDL_SetWindowTitle(window, "Tank Trouble");

    background = IMG_LoadTexture(renderer, "img/background.png");
    tank1 = IMG_LoadTexture(renderer, "img/tank1.png");
    tank2 = IMG_LoadTexture(renderer, "img/tank2.png");
    bulletTex = IMG_LoadTexture(renderer, "img/bullet.png");

    dstTank1.x = 0;
    dstTank1.y = SCREEN_HEIGHT / 2;
    dstTank1.w = dstTank1.h = 64;

    dstTank2.x = SCREEN_WIDTH - 64;
    dstTank2.y = SCREEN_HEIGHT / 2;
    dstTank2.w = dstTank2.h = 64;

    int tank1Angle = 0, tank2Angle = 0;
    int tank1Radian = tank1Angle * M_PI/180;
    int tank2Radian = tank2Angle * M_PI/180;
    int past = SDL_GetTicks();

    SDL_Event ev;

    while (true) {
        if (!inputHandling(ev)) {
            break;
        }

        int now = SDL_GetTicks();
        if (now - past >= 10) {
            if (up1) {
                dstTank1.y -= MOVE_SPEED;
                tank1Angle = 0;
            } else if (down1) {
                dstTank1.y += MOVE_SPEED;
                tank1Angle = 180;
            } else if (left1) {
                dstTank1.x -= MOVE_SPEED;
                tank1Angle = 270;
            } else if (right1) {
                dstTank1.x += MOVE_SPEED;
                tank1Angle = 90;
            }
            if (up2) {
                dstTank2.y -= MOVE_SPEED;
                tank2Angle = 0;
            } else if (down2) {
                dstTank2.y += MOVE_SPEED;
                tank2Angle = 180;
            } else if (left2) {
                dstTank2.x -= MOVE_SPEED;
                tank2Angle = 270;
            } else if (right2) {
                dstTank2.x += MOVE_SPEED;
                tank2Angle = 90;
            }

            if (shoot1){
                shootBullet(dstTank1.x, dstTank1.y, tank1Angle, timer1, 1);
            }
            if (shoot2) {
                shootBullet(dstTank2.x, dstTank2.y, tank2Angle, timer2, 2);
            }
            updateBullet(SCREEN_WIDTH, SCREEN_HEIGHT);
            past = now;
            timer1 += 10;
            timer2 += 10;
        }

        keepInWindow(dstTank1, dstTank2, SCREEN_WIDTH, SCREEN_HEIGHT);
        if (dstTank1.x < dstTank2.x + dstTank2.w && dstTank1.x + dstTank1.w > dstTank2.x && dstTank1.y < dstTank2.y + dstTank2.h && dstTank1.y + dstTank1.h > dstTank2.y) {
            collision(dstTank1, dstTank2);
        }



        SDL_RenderCopy(renderer, background, NULL, NULL);
        SDL_RenderCopyEx(renderer, tank1, NULL, &dstTank1, tank1Angle, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(renderer, tank2, NULL, &dstTank2, tank2Angle, NULL, SDL_FLIP_NONE);
        renderBullet();

        SDL_RenderPresent(renderer);

        SDL_Delay(10);

    }


    SDL_DestroyTexture(background);
    SDL_DestroyTexture(tank1);
    SDL_DestroyTexture(tank2);
    SDL_DestroyTexture(bulletTex);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    IMG_Quit();
    SDL_Quit();
    return 0;
}
