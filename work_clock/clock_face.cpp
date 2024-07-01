#include "clock_face.hpp"

clock_face::clock_face(int x, int y, int w, int h) {
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	hand_minute.set_dst(x, y, w, h);
	hand_hour.set_dst(x, y, w, h);
	image_clock = loadTexture(file, global::renderer);
}

clock_face::clock_face() {
	dst.x = 0;
	dst.y = 0;
	dst.w = 0;
	dst.h = 0;
	hand_minute.set_dst(0, 0, 0, 0);
	hand_hour.set_dst(0, 0, 0, 0);
	image_clock = loadTexture(file, global::renderer);
}

clock_face::~clock_face() {
	SDL_DestroyTexture(image_clock);
	SDL_DestroyTexture(image_text);
}

void clock_face::set_dst(int x, int y, int w, int h) {
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
}

SDL_Rect clock_face::get_dst() {
	return dst;
}

void clock_face::render_clock(SDL_Renderer* ren, int ang_second, int ang_minute, int ang_hour, int i)
{
	renderTexture(image_clock, ren ,dst, 0);
	hand_minute.set_dst(dst.x, dst.y, dst.w, dst.h);
	hand_hour.set_dst(dst.x, dst.y, dst.w, dst.h);
	hand_second.set_dst(dst.x, dst.y, dst.w, dst.h);
	hand_second.render(ren, ang_second);
	hand_minute.render(ren, ang_minute);
	hand_hour.render(ren, ang_hour);
	render_text(ren, files_text[i], i);
}  

void clock_face::render_text(SDL_Renderer* ren, std::string fileN, int n) {
	SDL_Rect place;
	place.w = 150;
	place.h = 100;
	if (n > 2) {
		place.x = SCREEN_WIDTH/3 * (n - 3) + 80;
		place.y = SCREEN_HEIGHT/ 3 ;
	}
	else {
		place.x = SCREEN_WIDTH/3 * n + 80;
		place.y = SCREEN_HEIGHT / 3*2 - 80;
	}
	image_text = loadTexture(fileN, ren);
	if (!image_text) {
		std::cout << SDL_GetError() << std::endl;
	}
	renderTexture(image_text, ren, place, 0);
}