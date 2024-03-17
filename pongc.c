#include <SDL2/SDL.h>

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return -1;
    }

    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);

    SDL_SetWindowTitle(window, "Pong");

    int running = 1;

    SDL_Rect rightPad;
    rightPad.x = 775;
    rightPad.y = 300;
    rightPad.w = 25;
    rightPad.h = 150;

    SDL_Rect leftPad;
    leftPad.x = 0;
    leftPad.y = 300;
    leftPad.w = 25;
    leftPad.h = 150;

    SDL_Rect ball;
    ball.x = 400;
    ball.y = 0;
    ball.w = 20;
    ball.h = 20;

    while (running)
    {
        SDL_Event event;

        SDL_PollEvent(&event);

        if (event.type == SDL_QUIT)
        {
            running = 0;
        }

        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_UP:
                    int moveRightpadUp = rightPad.y - 20;
                    rightPad.y = moveRightpadUp;

                    if (rightPad.y <= 0)
                    {
                        rightPad.y = 0;
                    }

                break;

                case SDLK_DOWN:
                    int moveRightpadDown = rightPad.y + 20;
                    rightPad.y = moveRightpadDown;

                    if (rightPad.y >= 450)
                    {
                        rightPad.y = 450;
                    }

                break;

                case SDLK_w:
                    int moveLeftpadUp = leftPad.y - 20;
                    leftPad.y = moveLeftpadUp;

                    if (leftPad.y <= 0)
                    {
                        leftPad.y = 0;
                    }

                break;

                case SDLK_s:
                    int moveLeftpadDown = leftPad.y + 20;
                    leftPad.y = moveLeftpadDown;

                    if (leftPad.y >= 450)
                    {
                        leftPad.y = 450;
                    }

                break;
            }
        }

        SDL_Delay(100);

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        SDL_RenderDrawRect(renderer, &rightPad);

        SDL_RenderDrawRect(renderer, &leftPad);

        SDL_RenderDrawRect(renderer, &ball);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}