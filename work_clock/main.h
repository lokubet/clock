#pragma once

#include <SDL_image.h>
#include "SDL.h"
#include <string>
#include <iostream>
#include <chrono>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;


void ApplySurface(int x, int y, int ang, SDL_Texture* tex, SDL_Renderer* rend);
SDL_Texture* LoadImage(std::string file);


class Clock_W {
	private:
		std::string file1 = "/images/1.png";
		std::string file2 = "/images/2.png";
		SDL_Texture* background;
		SDL_Texture* hand1;
		SDL_Texture* hand2;
		SDL_Texture* B_Clock;
	public:
		~Clock_W();
		void logSDLError(std::ostream& os, const std::string& msg);
		void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y, int w, int h);
		void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y);
		void renderTextureAngl(SDL_Texture* tex, SDL_Renderer* ren, int x, int y, int w, int h, int ang, SDL_Point centr);
		SDL_Texture* loadTexture(const std::string& file, SDL_Renderer* ren);
		int DrawBackground();
		int DrawBackClock();
		int DrawHands(int n, int ang);
		int CheckErr(SDL_Texture* temp);
};


//class dial() {
//	private:
//		int x;
//		int y;
//		int w;
//		
//}