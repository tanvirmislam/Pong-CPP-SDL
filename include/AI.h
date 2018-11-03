#ifndef AI_H
#define AI_H

#include <Windows.h>
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Bar.h"
#include "Ball.h"

class AI {
    public:
        AI(Bar* bar, Ball* ball);
        virtual ~AI();
        int tick();

    private:
        Bar*  _AIbar;
        Ball* _ball;
};

#endif // AI_H
