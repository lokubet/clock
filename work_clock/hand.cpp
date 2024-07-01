#include "hand.hpp"


void Hand_clock::set_dst(int x, int y, int w, int h) {
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
}

SDL_Rect Hand_clock::get_dst() {
	return dst;
}

Hand_clock::Hand_clock(std::string n) {
	file = n;
	image_hand = IMG_LoadTexture(global::renderer, file.c_str());
	if (!image_hand)
	{
		std::cout << IMG_GetError();
	}
}

void Hand_clock::render(SDL_Renderer* ren, int ang) {
	renderTexture(image_hand, ren, dst, ang);
}

Hand_clock::~Hand_clock() {
	SDL_DestroyTexture(image_hand);
}

SDL_Texture* Hand_clock::get_texture() {
	return image_hand;
}