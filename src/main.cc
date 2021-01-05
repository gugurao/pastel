#include <SDL.h>
#include <iostream>
#undef main
int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("pastel", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    if (win == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (ren == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Delay(2000);
    SDL_DestroyWindow(win);

    SDL_Quit();
}