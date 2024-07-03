#include "help_function.hpp"

namespace global {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
}

void logSDLError(std::ostream& os, const std::string& msg) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}


void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, SDL_Rect dst, int ang) {
    SDL_RenderCopyEx(ren, tex, NULL, &dst, ang, NULL, SDL_FLIP_NONE);
}

SDL_Texture* loadTexture(const std::string& file, SDL_Renderer* ren)
{
    SDL_Texture* texture = IMG_LoadTexture(ren, file.c_str());
    if (!texture)
    {
        std::cout << IMG_GetError();
    }
    return texture;
}

int initial() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        logSDLError(std::cout, "IMG_Init");
        SDL_Quit();
        return 1;
    }

    global::window = SDL_CreateWindow("A litile bit of clocks", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (global::window == nullptr) {
        std::cout << SDL_GetError() << std::endl;
        return 2;
    }
    global::renderer = SDL_CreateRenderer(global::window, -1, SDL_RENDERER_ACCELERATED
        | SDL_RENDERER_PRESENTVSYNC);
    if (global::renderer == nullptr) {
        std::cout << SDL_GetError() << std::endl;
        return 3;
    }
    return 0;
}

int getHour()
{
    struct tm newtime;
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    localtime_r(&in_time_t, &newtime);
    int mounth = newtime.tm_hour;
    return mounth;
}

int getMinute()
{
    struct tm newtime;
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    localtime_r(&in_time_t, &newtime);
    int hour = newtime.tm_min;
    return hour;
}

int getSecond()
{
    struct tm newtime;
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    localtime_r(&in_time_t, &newtime);
    int second = newtime.tm_sec;
    return second;
}
