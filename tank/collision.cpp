#include "collision.h"

bool checkCollision(const SDL_Rect& a, const SDL_Rect& b) {
    return SDL_HasIntersection(&a, &b);
}

void keepInWindow(SDL_Rect& obj1, SDL_Rect& obj2, int width, int height) {
    if (obj1.x < 0) {
        obj1.x = 0;
    }
    if (obj1.x + obj1.w > width) {
        obj1.x = width - obj1.w;
    }
    if (obj1.y < 0) {
        obj1.y = 0;
    }
    if (obj1.y + obj1.h > height) {
        obj1.y = height - obj1.h;
    }
    if (obj2.x < 0) {
        obj2.x = 0;
    }
    if (obj2.x + obj2.w > width) {
        obj2.x = width - obj2.w;
    }
    if (obj2.y < 0) {
        obj2.y = 0;
    }
    if (obj2.y + obj2.h > height) {
        obj2.y = height - obj2.h;
    }
}

void collision(SDL_Rect& obj1, SDL_Rect& obj2) {
    bool colliding = true;
    while (colliding) {
        colliding = false;
        int deltaX = (obj1.x + obj1.w / 2) - (obj2.x + obj2.w / 2);
        int deltaY = (obj1.y + obj1.h / 2) - (obj2.y + obj2.h / 2);

        if (abs(deltaX) > abs(deltaY)) {
            if(deltaX > 0) {
                obj1.x += 1;
                obj2.x -= 1;
            } else {
                obj1.x -= 1;
                obj2.x += 1;
            }
            if (checkCollision(obj1, obj2)) {
                colliding = true;
            }
        } else {
            if(deltaY > 0) {
                obj1.y += 1;
                obj2.y -= 1;
            } else {
                obj1.y -= 1;
                obj2.y += 1;
            }
            if (checkCollision(obj1, obj2)) {
                colliding = true;
            }
        }
    }
}

