#ifndef BAR_H
#define BAR_H

#include <Windows.h>
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <stdexcept>
#include <algorithm>

#define UP   -1
#define DOWN 1

class Bar {
    public:
        Bar(SDL_Renderer* renderer, bool isLeft);
        virtual ~Bar();
        int  tick(bool isUpKeyPressed, bool isDownKeyPressed);
        void draw();
        SDL_Rect* getBarRect();
        void resetDir();

        int             _dir;
        bool            _isLeft;

    private:
        void initBar();

        SDL_Renderer* _renderer;
        SDL_Texture*  _texture;
        SDL_Rect*     _rect;
        int           _barWidth;
        int           _barHeight;
        int           _slideAmount;

};

#endif // BAR_H
