#include "AI.h"

AI::AI(Bar* bar, Ball* ball)
   :_AIbar(bar),
    _ball(ball)
{}

AI::~AI() {

}

int AI::tick() {
    if (_ball->getYDir() == -1) {
        _AIbar->tick(true, false);
    }
    else if (_ball->getYDir() == 1) {
        _AIbar->tick(false, true);
    }

    return 0;
}
