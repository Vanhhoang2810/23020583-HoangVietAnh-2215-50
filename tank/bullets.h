#include <iostream>
#include <cmath>
#include <algorithm>
#include <SDL.h>
#include <vector>

using namespace std;


extern const int FIRE_RATE;
extern SDL_Renderer* renderer;
extern SDL_Texture* bulletTex;

struct Bullet {
    SDL_Rect rect;
    float velX,velY;
    bool active;
    int tankID;
};

void shootBullet(int TankX, int TankY, float angle, int &timer, int tankID);

void renderBullet();

void updateBullet(int width, int height);
