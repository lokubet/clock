#include "help_function.hpp"
#include "clock_face.hpp"




int main(int argc, char** argv) {

    SDL_Rect size_screen, size_clock;
    int n = 0;
    SDL_Event e;
    bool quit = false;
    int mas_time[6] = { -7, -1, -2, 0, 6, 7};

    create_some_shit();

    SDL_Texture* background = loadTexture("../images/background.png", global::renderer);

    size_screen.x = 0;
    size_screen.y = 0;
    size_screen.w = SCREEN_WIDTH;
    size_screen.h = SCREEN_HEIGHT;

    size_clock.x = 10;
    size_clock.y = 10;
    size_clock.w = SCREEN_WIDTH / 3 -25;
    size_clock.h = SCREEN_HEIGHT / 3;


    clock_face mas[6];

    while (n < 6) {
        mas[n].set_dst(size_clock.x, size_clock.y, size_clock.w, size_clock.h);
        size_clock.x += SCREEN_WIDTH / 3;
        if (n == 2) {
            size_clock.y = SCREEN_HEIGHT / 3 * 2;
            size_clock.x = 10;
        }
        n++;
    }
    while (!quit)
    {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_KEYDOWN){
            quit = true;
        }

        SDL_RenderClear(global::renderer);

        renderTexture(background, global::renderer, size_screen, 0);
        for (int i = 0; i < 6; i++) {
            mas[i].render_clock(global::renderer, getSecond()*6, getMinute() * 6, (getHour()+mas_time[i]) * 30, i);
        }
        SDL_RenderPresent(global::renderer);

    }

    if (!background){
        SDL_DestroyRenderer(global::renderer);
        SDL_DestroyWindow(global::window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    };

    return 0;
}

