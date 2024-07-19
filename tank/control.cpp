#include "Control.h"

bool inputHandling(SDL_Event ev) {
    while(SDL_PollEvent(&ev)) {
        switch(ev.type) {
        case SDL_QUIT:
            return false;
            break;
        case SDL_KEYDOWN:
            if (ev.key.keysym.sym == SDLK_ESCAPE) {
                return false;
            } else if (ev.key.keysym.sym == SDLK_w) {
                up1 = true;
            } else if (ev.key.keysym.sym == SDLK_s) {
                down1 = true;
            } else if (ev.key.keysym.sym == SDLK_a) {
                left1 = true;
            } else if (ev.key.keysym.sym == SDLK_d) {
                right1 = true;
            } else if (ev.key.keysym.sym == SDLK_UP) {
                up2 = true;
            } else if (ev.key.keysym.sym == SDLK_DOWN) {
                down2 = true;
            } else if (ev.key.keysym.sym == SDLK_LEFT) {
                left2 = true;
            } else if (ev.key.keysym.sym == SDLK_RIGHT) {
                right2 = true;
            } else if (ev.key.keysym.sym == SDLK_KP_1) {
                shoot2 = true;
            } else if (ev.key.keysym.sym == SDLK_SPACE) {
                shoot1 = true;
            }
            break;
        case SDL_KEYUP:
            if (ev.key.keysym.sym == SDLK_w) {
                up1 = false;
            } else if (ev.key.keysym.sym == SDLK_s) {
                down1 = false;
            } else if (ev.key.keysym.sym == SDLK_a) {
                left1 = false;
            } else if (ev.key.keysym.sym == SDLK_d) {
                right1 = false;
            } else if (ev.key.keysym.sym == SDLK_UP) {
                up2 = false;
            } else if (ev.key.keysym.sym == SDLK_DOWN) {
                down2 = false;
            } else if (ev.key.keysym.sym == SDLK_LEFT) {
                left2 = false;
            } else if (ev.key.keysym.sym == SDLK_RIGHT) {
                right2 = false;
            } else if (ev.key.keysym.sym == SDLK_KP_1) {
                shoot2 = false;
            } else if (ev.key.keysym.sym == SDLK_SPACE) {
                shoot1 = false;
            }


            break;
        }
    }
    return true;
}
