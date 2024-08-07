#include "bullets.h"
#include "map.h"

void shootBullet(int tankX, int tankY, float angle, int& timer, int tankID) {
    if (timer >= FIRE_RATE) {
        Bullet bullet;
        bullet.rect.x = tankX + 20;
        bullet.rect.y = tankY + 20;
        bullet.rect.w = bullet.rect.h = 10;
        float radians = (angle - 90) * M_PI / 180;
        bullet.velX = cos(radians) * 5;
        bullet.velY = sin(radians) * 5;
        bullet.active = true;
        bullet.tankID = tankID;
        bullets.push_back(bullet);
        timer = 0;
    }
}


void renderBullet() {
    for (int i = 0; i< bullets.size(); i++) {
        if (bullets[i].active) {
            SDL_RenderCopy(renderer,bulletTex, NULL, &bullets[i].rect);
        }
    }
}

void updateBullet(int width, int height) {
    for (int i = 0; i < bullets.size(); i++) {
        if (bullets[i].active) {
            bullets[i].rect.x += bullets[i].velX;
            bullets[i].rect.y += bullets[i].velY;

            if (bullets[i].rect.x < 0 || bullets[i].rect.x > width || bullets[i].rect.y < 0 || bullets[i].rect.y > height) {
                bullets[i].active = false;
            }

            if (checkMazeCollision(bullets[i].rect)) {
                bullets[i].active = false;
            }
        }
    }
}

void restage(SDL_Rect& dstTank1, SDL_Rect& dstTank2) {
    dstTank1.x = 20;
    dstTank1.y = SCREEN_HEIGHT / 2 - 32;
    dstTank1.w = dstTank1.h = 64;
    dstTank2.x = SCREEN_WIDTH - 84;
    dstTank2.y = SCREEN_HEIGHT / 2 - 32;
    dstTank2.w = dstTank2.h = 64;
    bullets.clear();
    tank1Angle = 90;
    tank2Angle = 270;
}

void bulletCollision() {
    for (int i = 0; i<bullets.size(); i++) {
        if (bullets[i].active) {
            if (bullets[i].tankID == 1) {
                if (checkCollision(bullets[i].rect, dstTank2)) {
                    bullets[i].active = false;
                    point1++;
                    restage(dstTank1, dstTank2);
                }
            } else if (bullets[i].tankID == 2) {
                if (checkCollision(bullets[i].rect, dstTank1)) {
                    bullets[i].active = false;
                    point2++;
                    restage(dstTank1, dstTank2);
                }
            }
        }

        for (int j = i + 1; j < bullets.size(); j++) {
            if (bullets[j].active && checkCollision(bullets[i].rect, bullets[j].rect)) {
                bullets[i].active = false;
                bullets[j].active = false;
            }
        }
    }
}


