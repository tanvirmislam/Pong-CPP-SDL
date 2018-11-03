#ifndef GAME_H
#define GAME_H

#include <Windows.h>
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <stdexcept>
#include "Application.h"
#include "texture_methods.h"
#include "Bar.h"
#include "Ball.h"
#include "AI.h"

#define TICK_INTERVAL 2

enum class GameState {PLAY, EXIT};

class Game {
    public:
        Game(SDL_Renderer* renderer);
        virtual ~Game();
        void run();

    private:
        int  tick();
        void gameLoop();
        void processInput();

        SDL_Renderer* _renderer;
        Bar*          _leftBar;
        Bar*          _rightBar;
        Ball*         _ball;
        AI*           _AI;
        bool          _isUpKeyPressedLeft;
        bool          _isDownKeyPressedLeft;
        bool          _isUpKeyPressedRight;
        bool          _isDownKeyPressedRight;
        GameState _gameState;
};

#endif // GAME_H
