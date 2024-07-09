#include "clock_face.hpp"

clock_face::clock_face(int x, int y, int w, int h) {
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	hand_minute.set_dst(x, y, w, h);
	hand_hour.set_dst(x, y, w, h);
	image_clock = loadTexture(file, global::renderer);
	for (int i = 0; i < 6; i++) {	
		image_text.push_back(loadTexture(files_text[i], global::renderer));
	}
	if (!image_clock) {
		std::cout << SDL_GetError() << std::endl;
	}
}

clock_face::clock_face() {
	dst.x = 0;
	dst.y = 0;
	dst.w = 0;
	dst.h = 0;
	hand_minute.set_dst(0, 0, 0, 0);
	hand_hour.set_dst(0, 0, 0, 0);
	image_clock = loadTexture(file, global::renderer);
	for (int i = 0; i < 6; i++) {	
		image_text.push_back(loadTexture(files_text[i], global::renderer));
		if (!image_text[i]) {
			std::cout << SDL_GetError() << std::endl;
		}
	}
	if (!image_clock) {
		std::cout << SDL_GetError() << std::endl;
	}

	
	
}

clock_face::~clock_face() {
	SDL_DestroyTexture(image_clock);
	for (int i = 0; i < 6; i++) {
		SDL_DestroyTexture(image_text[i]);
	}
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
	render_text(ren, i);
}

void clock_face::render_text(SDL_Renderer* ren, int n) {
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
	
	
	renderTexture(image_text[n], ren, place, 0);
}
