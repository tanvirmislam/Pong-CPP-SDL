#ifndef APPLICATION_H
#define APPLICATION_H

#include <Windows.h>
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <stdexcept>

#define WINDOW_WIDTH  1280
#define WINDOW_HEIGHT 800

class Application {
    public:
        Application();
        virtual ~Application();
        void run();

    private:
        int initSystem();

        SDL_Window*   _window;
        SDL_Renderer* _renderer;
};

#endif // APPLICATION_H
