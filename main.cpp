#include <SDL2/SDL.h>
#include <iostream>

#define WIDTH 1920
#define HEIGHT 1080

void input() {}
void update() {}
void draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
    SDL_Rect rect;

    rect.x=rect.y = 32;
    rect.w = WIDTH - (rect.x * 2);
    rect.h = HEIGHT - (rect.y * 2);

    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
}

int main(int arg_c, char* arg_v[])
{
    bool running = true;

    SDL_Renderer* renderer;
    SDL_Window* window;

    int frameCount, timerFPS, lastFrame, fps;

    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        std::cout << "Failed to init SDL library" << std::endl;
        return -1;
    }

    if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer))
    {
        std::cout << "Failed to create window/renderer" << std::endl;
        return -1;
    }

    SDL_SetWindowTitle(window, "SDL 2 Tutorial");
    SDL_ShowCursor(1);

    while (running) {
        input();
        update();
        draw(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}