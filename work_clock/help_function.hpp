#pragma once
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 800;
#include <SDL_image.h>
#include "SDL.h"
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream> 
#include <iomanip>

namespace global {
	extern SDL_Window* window;
	extern SDL_Renderer* renderer;
}

int initial();
void logSDLError(std::ostream& os, const std::string& msg);
void ApplySurface(int x, int y, int ang, SDL_Texture* tex, SDL_Renderer* rend);
SDL_Texture* LoadImage(std::string file);
SDL_Texture* loadTexture(const std::string& file, SDL_Renderer* ren);
void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, SDL_Rect dst, int ang);
inline std::tm localtime_xp(std::time_t timer);
int getHour();
int getMinute();
int getSecond();