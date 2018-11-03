#include "Bar.h"
#include "Application.h"
#include "texture_methods.h"

Bar::Bar(SDL_Renderer* renderer, bool isLeft)
    :_dir(0),
     _isLeft(isLeft),
     _renderer(renderer),
     _texture(nullptr),
     _rect(new SDL_Rect),
     _barWidth(WINDOW_WIDTH / 55),
     _barHeight(WINDOW_HEIGHT / 4),
     _slideAmount(1)
{
    initBar();
}

Bar::~Bar() {
    SDL_DestroyTexture(_texture);
    delete _rect;
}

void Bar::initBar() {
    _rect->x = (_isLeft) ? 0 : (WINDOW_WIDTH - _barWidth);
    _rect->y = (WINDOW_HEIGHT / 2) - (_barHeight / 2);
    _rect->w = _barWidth;
    _rect->h = _barHeight;

    _texture = SDL_CreateTexture(_renderer,
                                 SDL_PIXELFORMAT_RGBA8888,
                                 SDL_TEXTUREACCESS_TARGET,
                                 1024, 768);
    fillTexture(_renderer, _texture, 255, 255, 255, 255);
    SDL_SetTextureBlendMode(_texture, SDL_BLENDMODE_BLEND);
}

int Bar::tick(bool isUpKeyPressed, bool isDownKeyPressed) {
    if (isUpKeyPressed) {
        _rect->y = std::max(0, (_rect->y - _slideAmount));
        _dir = UP;
    }
    if (isDownKeyPressed) {
        _rect->y = std::min((WINDOW_HEIGHT - _barHeight), (_rect->y + _slideAmount));
        _dir = DOWN;
    }

    return 0;
}

void Bar::draw() {
    SDL_RenderCopy(_renderer, _texture, NULL, _rect);
}

SDL_Rect* Bar::getBarRect() {
    return _rect;
}

void Bar::resetDir() {
    _dir = 0;
}

