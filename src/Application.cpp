#include "Application.h"
#include "Game.h"

Application::Application()
            :_window(nullptr),
             _renderer(nullptr)
{}

Application::~Application() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

int Application::initSystem() {
    int status = SDL_Init(SDL_INIT_EVERYTHING);
    if (status != 0) {
        throw std::runtime_error("SDL_Init failed");
        return status;
    }

    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &_window, &_renderer);
    if (_window == nullptr || _renderer == nullptr) {
        throw std::runtime_error("SDL_CreateWindowAndRenderer failed");
        return 1;
    }

    //SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);
    SDL_SetWindowPosition(_window, 65, 126);

    return 0;
}

void Application::run() {
    int status = initSystem();
    if (status != 0) {
        throw std::runtime_error("Error initializing SDL");
        return;
    }

    Game *game = new Game(_renderer);
    game->run();
    delete game;
}
