#pragma once
#include "SDL.h"
#include "canvas.hh"
class Window
{
    int _width;
    int _height;
    bool _running;
    Canvas *_canvas;
    Mesh *_mesh;
    SDL_Window *_win;
    SDL_Surface *_screen;

    bool pressedW = false;
    bool pressedS = false;
    bool pressedA = false;
    bool pressedD = false;
    bool pressedUp = false;
    bool pressedDown = false;
    bool pressedLeft = false;
    bool pressedRight = false;

public:
    Window(int argc, char *argv[], int width = 800, int height = 600, const char *title = "Pastel")
    {

        if (SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            fprintf(stderr, "SDL_Init failed\n");
        }

        _win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        _screen = SDL_GetWindowSurface(_win);
        if (_screen == NULL)
        {
            SDL_Quit();
            fprintf(stderr, "SDL_GetWindowSurface failed\n");
        }
        _canvas = new Canvas((uint32_t *)_screen->pixels, width, height);
        
        _running = true;
        const char *modelPath = "illidan.gua3d";
        const char *texturePath = "illidan.guaimage";
        _mesh = new Mesh(modelPath, texturePath);
    }
    virtual ~Window()
    {
        delete _canvas;
        delete _mesh;
        SDL_DestroyWindow(_win);
    }
    //main loop
    void run()
    {

        // SDL_LockSurface(_screen);
        // updateInput();

        // // 1, update
        // update();

        // // 2, clear
        // clear();

        // // 3, draw
        // draw();

        // //4, present
        // show();
    };
    void update()
    {
        static const float transform = 0.05;

        _mesh->rotation.x += pressedUp ? transform : 0;
        _mesh->rotation.x -= pressedDown ? transform : 0;
        _mesh->rotation.y += pressedLeft ? transform : 0;
        _mesh->rotation.y -= pressedRight ? transform : 0;

        _mesh->position.y += pressedW ? transform : 0;
        _mesh->position.y -= pressedS ? transform : 0;
        _mesh->position.x -= pressedA ? transform : 0;
        _mesh->position.x += pressedD ? transform : 0;
    };

    void clear()
    {
        _canvas->clear();
    };
    void draw()
    {
        _canvas->drawMesh(*_mesh);
    };
    void show(){
        //SDL_UnlockSurface(_screen);
        //SDL_UpdateWindowSurface(_win);
    };

    void onKeyEvent(const SDL_Event *event)
    {
        SDL_Keycode key = (*event).key.keysym.sym;
        bool keyIsDown = (event->type == SDL_KEYDOWN);
        if (key == SDLK_ESCAPE)
        {
            quit();
        }
        else if (key == SDLK_UP)
        {
            pressedUp = keyIsDown;
        }
        else if (key == SDLK_DOWN)
        {
            pressedDown = keyIsDown;
        }
        else if (key == SDLK_LEFT)
        {
            pressedLeft = keyIsDown;
        }
        else if (key == SDLK_RIGHT)
        {
            pressedRight = keyIsDown;
        }
        else if (key == SDLK_w)
        {
            pressedW = keyIsDown;
        }
        else if (key == SDLK_s)
        {
            pressedS = keyIsDown;
        }
        else if (key == SDLK_a)
        {
            pressedA = keyIsDown;
        }
        else if (key == SDLK_d)
        {
            pressedD = keyIsDown;
        }
    }

    void onMouseEvent(const SDL_Event *event)
    {
    }

    void HandleEvent(const SDL_Event *event)
    {
        unsigned char eventType = event->type;

        if (eventType == SDL_QUIT)
        {
            quit();
        }
        else if (eventType == SDL_KEYDOWN || eventType == SDL_KEYUP)
        {
            onKeyEvent(event);
        }
        else if (eventType == SDL_MOUSEBUTTONDOWN)
        {
            onMouseEvent(event);
        }
    };

    void updateInput()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            HandleEvent(&event);
        }
    };
    void quit()
    {
        _running = false;
    };
};