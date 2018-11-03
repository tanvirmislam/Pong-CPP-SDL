#include "Game.h"

Game::Game(SDL_Renderer* renderer)
     :_renderer(renderer),
      _leftBar(new Bar(renderer, true)),
      _rightBar(new Bar(renderer, false)),
      _ball(new Ball(renderer)),
      _AI(new AI(_leftBar, _ball)),
      _isUpKeyPressedLeft(false),
      _isDownKeyPressedLeft(false),
      _isUpKeyPressedRight(false),
      _isDownKeyPressedRight(false),
      _gameState(GameState::PLAY)
{}

Game::~Game() {
    delete _leftBar;
    delete _rightBar;
    delete _ball;
    delete _AI;
}


void Game::run() {
    gameLoop();
}

int Game::tick() {
    //_leftBar->tick(_isUpKeyPressedLeft, _isDownKeyPressedLeft);
    _AI->tick();
    _rightBar->tick(_isUpKeyPressedRight, _isDownKeyPressedRight);
    _ball->tick(_leftBar, _rightBar);
    return 0;
}

void Game::gameLoop() {
    prepareForRendering(_renderer, 0x00, 0x00, 0x00, 0x00);
    unsigned int currentTime, lastTime = 0;

    while (_gameState != GameState::EXIT) {
        processInput();

        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + TICK_INTERVAL) {
            bool status = tick();
            if (status) {
                //SDL_Delay(10);
                break;
                //std::cout << "HIT" << std::endl;
            }
            lastTime = currentTime;
        }

        SDL_RenderClear(_renderer);
        _leftBar->draw();
        _rightBar->draw();
        _ball->draw();
        SDL_RenderPresent(_renderer);
    }
}

void Game::processInput() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        switch (e.type) {
            case SDL_QUIT:
                _gameState = GameState::EXIT;
                break;
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_w) {
                    _isUpKeyPressedLeft = true;
                }
                else if (e.key.keysym.sym == SDLK_s) {
                    _isDownKeyPressedLeft = true;
                }
                if (e.key.keysym.sym == SDLK_UP) {
                    _isUpKeyPressedRight = true;
                }
                else if (e.key.keysym.sym == SDLK_DOWN) {
                    _isDownKeyPressedRight = true;
                }
                break;
            case SDL_KEYUP:
                _isUpKeyPressedLeft    = false;
                _isDownKeyPressedLeft  = false;
                _isUpKeyPressedRight   = false;
                _isDownKeyPressedRight = false;

                _leftBar->resetDir();
                _rightBar->resetDir();

                if (keystate[SDL_SCANCODE_W]) {
                    _isUpKeyPressedLeft = true;
                }
                else if (keystate[SDL_SCANCODE_S]) {
                    _isDownKeyPressedLeft = true;
                }
                if (keystate[SDL_SCANCODE_UP]) {
                    _isUpKeyPressedRight = true;
                }
                else if (keystate[SDL_SCANCODE_DOWN]) {
                    _isDownKeyPressedRight = true;
                }
                break;
        }
    }
}



