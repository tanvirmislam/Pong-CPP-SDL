#include <Windows.h>
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "Application.h"
#include "texture_methods.h"

int main(int argc, char *argv[]) {
    Application* app = new Application();
    app->run();
    delete app;
    return 0;
}

//
//int main(int argc, char *argv[])
//{
//    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_HAPTIC);
//
//    SDL_Window *window = SDL_CreateWindow("SDL test",
//        SDL_WINDOWPOS_CENTERED,
//        SDL_WINDOWPOS_CENTERED,
//        320, 240,
//        SDL_WINDOW_OPENGL);
//    SDL_Renderer *renderer = SDL_CreateRenderer(
//        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
//
//    const int width = 50;
//    const int height = 50;
//
//    ::std::vector<SDL_Texture*> textures;
//
//    SDL_Texture *redTexture = SDL_CreateTexture(renderer,
//        SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
//    textures.push_back(redTexture);
//
//    SDL_Texture *greenTexture = SDL_CreateTexture(renderer,
//        SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
//    textures.push_back(greenTexture);
//
//    SDL_Texture *purpleTexture = SDL_CreateTexture(renderer,
//        SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
//    textures.push_back(purpleTexture);
//
//    // Here is setting the blend mode for each and every used texture:
//    for(int i = 0; i < textures.size(); ++i)
//    {
//        SDL_SetTextureBlendMode(textures[i], SDL_BLENDMODE_BLEND);
//    }
//
//    int purpleAlpha = 0;
//
//    fillTexture(renderer, redTexture, 255, 0, 0, 0);
//    fillTexture(renderer, greenTexture, 0, 255, 0, 128);
//    fillTexture(renderer, purpleTexture, 255, 0, 255, purpleAlpha);
//
//    prepareForRendering(renderer, 0x00, 0xff, 0xff, 0xff);
//
//    bool running = true;
//    while(running)
//    {
//        SDL_Rect rect;
//        rect.w = width;
//        rect.h = height;
//
//        SDL_RenderClear(renderer);
//
//        rect.x = 50;
//        rect.y = 50;
//        SDL_RenderCopy(renderer, redTexture, NULL, &rect);
//
//        rect.x = 75;
//        rect.y = 70;
//        SDL_RenderCopy(renderer, greenTexture, NULL, &rect);
//
//        rect.x = 75;
//        rect.y = 30;
//        SDL_RenderCopy(renderer, purpleTexture, NULL, &rect);
//
//        SDL_RenderPresent(renderer);
//
//        // Process events
//        {
//            SDL_Event event;
//            while(SDL_PollEvent(&event) == 1)
//            {
//                if(event.type == SDL_QUIT)
//                {
//                    running = false;
//                }
//                else if(event.type == SDL_KEYDOWN)
//                {
//                    switch(event.key.keysym.sym)
//                    {
//                    case SDLK_ESCAPE:
//                        running = false;
//                        break;
//                    case SDLK_a:
//                        purpleAlpha = ::std::max(purpleAlpha - 32, 0);
//                        fillTexture(renderer, purpleTexture, 255, 0, 255, purpleAlpha);
//                        prepareForRendering(renderer, 0x00, 0xff, 0xff, 0xff);
//                        ::std::cout << "Alpha: " << purpleAlpha << ::std::endl;
//                        break;
//                    case SDLK_s:
//                        purpleAlpha = ::std::min(purpleAlpha + 32, 255);
//                        fillTexture(renderer, purpleTexture, 255, 0, 255, purpleAlpha);
//                        prepareForRendering(renderer, 0x00, 0xff, 0xff, 0xff);
//                        ::std::cout << "Alpha: " << purpleAlpha << ::std::endl;
//                        break;
//                    }
//                }
//            }
//
//        }
//    }
//
//    for(int i = 0; i < textures.size(); ++i)
//    {
//        SDL_DestroyTexture(textures[i]);
//    }
//    textures.clear();
//
//    SDL_DestroyRenderer(renderer);
//    renderer = NULL;
//    SDL_DestroyWindow(window);
//    window = NULL;
//
//    SDL_Quit();
//    return 0;
//}
