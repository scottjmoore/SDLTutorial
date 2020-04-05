#include <SDL2/SDL.h>

#include <iostream>

#define WIDTH 1920
#define HEIGHT 1080

struct gamestate
{
    bool running;
    int frameCount;
};

void input(gamestate* gameState)
{
    if (gameState->frameCount > 3000)
        gameState->running = false;
}

void update() {}

void draw(SDL_Renderer* renderer)
{
    // SDL_SetRenderDrawColor(renderer, 128, 128, 128, 0);
    // SDL_Rect rect;

    // rect.x=rect.y = 32;
    // rect.w = WIDTH - (rect.x * 2);
    // rect.h = HEIGHT - (rect.y * 2);

    // SDL_RenderFillRect(renderer, &rect);
    // SDL_RenderPresent(renderer);
}

int main(int arg_c, char* arg_v[])
{
    gamestate gameState;

    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Surface* surface;
    SDL_Texture* texture;

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

    surface = SDL_LoadBMP("test.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_SetWindowTitle(window, "SDL 2 Tutorial");
    SDL_ShowCursor(1);

    gameState.running = true;
    gameState.frameCount = 0;

    while (gameState.running) {
        input(&gameState);
        update();
        draw(renderer);

        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);

        gameState.frameCount++;
    }

    SDL_FreeSurface(surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}