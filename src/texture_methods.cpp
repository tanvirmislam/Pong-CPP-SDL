#include "texture_methods.h"
#include <SDL/SDL_image.h>

void prepareForRendering(SDL_Renderer *renderer, int r, int g, int b, int a) {
    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void fillTexture(SDL_Renderer *renderer, SDL_Texture *texture, int r, int g, int b, int a) {
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, NULL);
}

SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* fileName) {
    //auto surface = SDL_LoadBMP(fileName);
    SDL_Surface* surface = IMG_Load(fileName);
    if (!surface) {
        throw std::runtime_error(std::string("SDL_LoadBMP(") + fileName + "): " + SDL_GetError());
        return nullptr;
    }

    auto res = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return res;
}
