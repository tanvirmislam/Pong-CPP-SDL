#include "Ball.h"
#include "Application.h"
#include "texture_methods.h"
#include <ctime>
#include <random>

Ball::Ball(SDL_Renderer* renderer)
     :_x(WINDOW_WIDTH / 2),
      _y(WINDOW_HEIGHT / 2),
      _renderer(renderer),
      _ballTexture(nullptr),
      _rect(new SDL_Rect()),
      _ballWidth(20),
      _ballHeight(21),
      _xVel(MIN_X_VEL),
      _yVel(0),
      _xDir(RIGHT),
      _yDir(0)
{
    initBall();
}

Ball::~Ball() {
    SDL_DestroyTexture(_ballTexture);
    delete _rect;
}

void Ball::initBall() {
    _ballTexture = loadTexture(_renderer, "ball_t.png");
    _rect->x = _x;
    _rect->y = _y;
    _rect->w = _ballWidth;
    _rect->h = _ballHeight;
}

void Ball::draw() {
    _rect->x = _x;
    _rect->y = _y;

    auto status = SDL_RenderCopy(_renderer, _ballTexture, nullptr, _rect);
    if (status != 0) {
        throw std::runtime_error(std::string("SDL_RenderCopy ") + SDL_GetError());
    }
}

int Ball::tick(Bar* leftBar, Bar* rightBar) {
    // Check collision
    handleIntersection(leftBar);
    handleIntersection(rightBar);

    // Check boundary
    int status = checkBoundary();

    _x += (_xVel * _xDir);
    _y += (_yVel * _yDir);

    return status;
}

void Ball::handleIntersection(Bar* bar) {
    SDL_Rect* result = new SDL_Rect();
    if (SDL_IntersectRect(_rect, bar->getBarRect(), result)) {
        if (_yDir == bar->_dir) {
            //std::cout << "y vel++" << std::endl;
            _yVel = std::min(MAX_Y_VEL, (_yVel+1));
        }
        else if (bar->_dir != 0) {
            //std::cout << "y vel--" << std::endl;
            if (_yVel == 0) {
                _yDir = bar->_dir;
            }
            _yVel = std::max(MIN_Y_VEL, (_yVel-1));
        }

        _xDir = (bar->_isLeft) ? RIGHT : LEFT;
        if (bar->_dir != 0) {
            srand(time(NULL));
            _xVel = (rand() % MAX_X_VEL) + 1;
        }

        breakZeroY();


        if (_yDir != 1 && _xVel == MAX_X_VEL) {
            _xVel -= 1;
        }

        //std::cout << "y vel: " << _yVel << std::endl;
        //std::cout << "y dir: " << _yDir << std::endl;
    }
    delete result;
}

void Ball::breakZeroY() {
    if (_yDir == 0) {
        srand(time(NULL));
        int tmp = rand() % 2;
        //std::cout << "rand num for dir: " << tmp << std::endl;
        if (tmp == 0) {
            _yDir = -1;
        }
        else {
            _yDir = 1;
        }
    }

    if (_yVel == 0) {
        _yVel = 1;
    }
}

int Ball::checkBoundary() {
    if (_x <= 0) {
        _xDir *= -1;
    }
    else if (_x >= WINDOW_WIDTH) {
        _xDir *= -1;
    }

    if (_y <= 0) {
        _yDir *= -1;
    }
    else if (_y >= WINDOW_HEIGHT) {
        _yDir *= -1;
    }

    return 0;
}

int Ball::getYDir() {
    return _yDir;
}
