#ifndef BALL_H
#define BALL_H

#include <Windows.h>
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Bar.h"

#define LEFT  -1
#define RIGHT  1
#define MIN_X_VEL 1
#define MAX_X_VEL 2
#define MIN_Y_VEL 0
#define MAX_Y_VEL 2


class Ball {
    public:
        Ball(SDL_Renderer* renderer);
        virtual ~Ball();
        void draw();
        int  tick(Bar* leftBar, Bar* rightBar);
        int getYDir();

        float _x;
        float _y;

    private:
        void initBall();
        void handleIntersection(Bar* bar);
        void breakZeroY();
        int  checkBoundary();

        SDL_Renderer* _renderer;
        SDL_Texture*  _ballTexture;
        SDL_Rect*     _rect;

        int _ballWidth;
        int _ballHeight;
        int _xVel;
        int _yVel;
        int _xDir;
        int _yDir;
        int _angle;
};

#endif // BALL_H
