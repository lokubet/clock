#pragma once
#include "help_function.hpp"

class Hand_clock{
	private:
		int ang;
		SDL_Rect dst;
		std::string file;
		SDL_Texture* image_hand;
	public:

		/**
		 * @brief Конструктор загружающий текстуру стрелки.
		 * @param string путь до файла с изображением стрелки.
		 */

		Hand_clock(std::string n);

		/**
		 * @brief Деконструктор очищающий текстуру.
		 */

		~Hand_clock();

		/**
		 * @brief Присваивание переменных в классе координат, полученные координаты.
		 * @param Numbers координаты.
		 */

		void set_dst(int x, int y, int w, int h);

		/**
		 * @brief Возвращает координаты.
		 * @return SDL_Rect координаты.
		 */

		SDL_Rect get_dst();

		/**
		 * @brief Рендерит стрелку под углом.
		 * @param SDL_Renderer Рендер.
		 * @param Number Угол.
		 */

		void render(SDL_Renderer* ren, int ang);

		/**
		 * @brief Возвращает текстуру стрелки.
		 * @return Текстура стрелки.
		 */

		SDL_Texture* get_texture();
};