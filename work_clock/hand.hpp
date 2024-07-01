#pragma once
#include "help_function.hpp"

class Hand_clock{
	private:
		int ang;
		SDL_Rect dst;
		std::string file;
		SDL_Texture* image_hand;
	public:
		Hand_clock(std::string n);
		~Hand_clock();
		void set_dst(int x, int y, int w, int h);
		SDL_Rect get_dst();
		void render(SDL_Renderer* ren, int ang);
		SDL_Texture* get_texture();
};