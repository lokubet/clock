#include "hand.hpp"

/**
 * @brief Присваивание переменных в классе координат, полученные координаты.
 * @param Numbers координаты.
 */
void Hand_clock::set_dst(int x, int y, int w, int h) {
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
}

/**
 * @brief Возвращает координаты.
 * @return SDL_Rect координаты.
 */

SDL_Rect Hand_clock::get_dst() {
	return dst;
}

/**
 * @brief Конструктор загружающий текстуру стрелки.
 * @param string путь до файла с изображением стрелки.
 */

Hand_clock::Hand_clock(std::string n) {
	file = n;
	image_hand = IMG_LoadTexture(global::renderer, file.c_str());
	if (!image_hand)
	{
		std::cout << IMG_GetError();
	}
}


/**
 * @brief Рендерит стрелку под углом.
 * @param SDL_Renderer Рендер.
 * @param Number Угол.
 */

void Hand_clock::render(SDL_Renderer* ren, int ang) {
	renderTexture(image_hand, ren, dst, ang);
}

/**
 * @brief Деконструктор очищающий текстуру.
 */

Hand_clock::~Hand_clock() {
	SDL_DestroyTexture(image_hand);
}


/**
 * @brief Возвращает текстуру стрелки.
 * @return Текстура стрелки.
 */

SDL_Texture* Hand_clock::get_texture() {
	return image_hand;
}