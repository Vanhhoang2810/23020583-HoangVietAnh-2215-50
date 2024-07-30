#include <iostream>
#include <cmath>
#include <algorithm>
#include <SDL.h>
#include <vector>
#include "collision.h"

using namespace std;


extern const int FIRE_RATE;
extern SDL_Renderer* renderer;
extern SDL_Texture* bulletTex;
extern bool hit1, hit2;
extern SDL_Rect dstTank1, dstTank2;
extern const int SCREEN_HEIGHT, SCREEN_WIDTH;
extern int point1, point2;
extern int tank1Angle, tank2Angle;

struct Bullet {
    SDL_Rect rect;
    float velX,velY;
    bool active;
    int tankID;
};

extern vector<Bullet> bullets;

void shootBullet(int TankX, int TankY, float angle, int &timer, int tankID);

void renderBullet();

void updateBullet(int width, int height);

void bulletCollision();
