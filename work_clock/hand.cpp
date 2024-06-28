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

Hand_clock::Hand_clock() {
	image_hand = IMG_LoadTexture(renderer, file.c_str());
	if (!image_hand)
	{
		std::cout << IMG_GetError();
	}
}

void Hand_clock::renderTextureAngl(SDL_Renderer* ren, int ang) {
	SDL_RenderCopyEx(ren, image_hand, NULL, &dst, ang, NULL, SDL_FLIP_NONE);
}

Hand_clock::~Hand_clock() {
	SDL_DestroyTexture(image_hand);
}