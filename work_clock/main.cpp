#include "main.h"


void Clock_W::logSDLError(std::ostream& os, const std::string& msg) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}

void Clock_W::renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y, int w, int h)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;
    SDL_RenderCopy(ren, tex, NULL, &dst);
}

void Clock_W::renderTextureAngl(SDL_Texture* tex, SDL_Renderer* ren, int x, int y, int w, int h, int ang, SDL_Point centr)
{
    SDL_Rect dst; 
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;
    SDL_RenderCopyEx(ren, tex, NULL, &dst, ang, NULL, SDL_FLIP_NONE);
}

void Clock_W::renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y)
{
    int w, h;
    SDL_QueryTexture(tex, NULL, NULL, &w, &h);
    renderTexture(tex, ren, x, y, w, h);
}

int Clock_W::DrawBackground() {
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

    window = SDL_CreateWindow("FUCKING PISS OF SHIT", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << SDL_GetError() << std::endl;
        return 2;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
        | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cout << SDL_GetError() << std::endl;
        return 3;
    }
    background = loadTexture("images/background.png", renderer);
    renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (CheckErr(background))
        return 1;
}


//todo findcentrpos


int Clock_W::DrawBackClock() {
    int x, y, w, h;
    B_Clock = loadTexture("images/3.png", renderer);
    x = 0;
    y = 0;
    w = SCREEN_WIDTH / 3 - 100;
    h = SCREEN_HEIGHT / 3;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {

            renderTexture(B_Clock, renderer, x, y, w, h);
            if (!CheckErr(B_Clock))
                return 1;
            x += SCREEN_WIDTH / 3;
        }
        y = SCREEN_HEIGHT / 3 * 2;
        x = 0;
    }
}

int Clock_W::DrawHands(int n, int ang) {
    SDL_Point centr;
    int x, y, w, h;
    centr.x = 0;
    centr.y = 0;
    x = SCREEN_WIDTH/12+40;
    y = SCREEN_HEIGHT/12-85;
    w = 0;
    h = 0;
    hand1 = loadTexture("images/1.png", renderer);
    hand2 = loadTexture("images/2.png", renderer);
    renderTextureAngl(hand1, renderer, x, y, 15, SCREEN_HEIGHT/3+10, 15, centr);
    //renderTexture(hand2, renderer, x, y);
    if (!CheckErr(B_Clock))
        return 1;
}


Clock_W::~Clock_W() {
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(hand1);
    SDL_DestroyTexture(hand2);
    SDL_DestroyTexture(B_Clock);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}





//void ApplySurface(int x, int y, int ang, SDL_Texture* tex, SDL_Renderer* rend) {
//    SDL_Rect pos;
//    pos.x = x;
//    pos.y = y;
//    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
//    SDL_RenderCopyEx(rend, tex, NULL, &pos, ang ,NULL, SDL_FLIP_NONE);
//}

SDL_Texture* Clock_W::loadTexture(const std::string& file, SDL_Renderer* ren)
{
    SDL_Texture* texture = IMG_LoadTexture(ren, file.c_str());
    if (!texture)
    {
        std::cout << IMG_GetError(); 
    }
    return texture;
}






int Clock_W::CheckErr(SDL_Texture* temp) {
    if (!temp)
    {
        SDL_DestroyTexture(hand1);
        SDL_DestroyTexture(hand2);
        SDL_DestroyTexture(B_Clock);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
}





int main(int argc, char** argv) {
    Clock_W strt;
    if (!strt.DrawBackground())
        return 1;
    if (!strt.DrawBackClock())
        return 1;
    if (!strt.DrawHands(0,15))
        return 1;
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
    /*auto current_time = std::chrono::system_clock::now();
    std::time_t current_time_t = std::chrono::system_clock::to_time_t(current_time);
    std::cout << "current time is: " << ctime_s((std:) & current_time_t);*/
    return 0;
}

