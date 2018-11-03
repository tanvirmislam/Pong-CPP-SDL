#ifndef TEXTURE_METHODS_H
#define TEXTURE_METHODS_H

#include <Windows.h>
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <stdexcept>

void prepareForRendering(SDL_Renderer *renderer, int r, int g, int b, int a);
void fillTexture(SDL_Renderer *renderer, SDL_Texture *texture, int r, int g, int b, int a);
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* fileName);

#endif // TEXTURE_METHODS_H
