#include "bullets.h"

vector<Bullet> bullets;


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


        }
    }

    bullets.erase(remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) { return !b.active; }), bullets.end());
}


