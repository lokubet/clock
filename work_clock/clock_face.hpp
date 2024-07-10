#pragma once

#include "help_function.hpp"
#include "hand.hpp"


class clock_face {
	private:
		SDL_Color textColor = { 255,0,0 };
		SDL_Rect dst;
		std::string	file = "../images/3_2.png";
		std::string background = "../images/background.png";
		std::string files_text[6] = {"../images/Moscow.png", "../images/Tokyo.png", "../images/Sydney.png",
		 "../images/New_York_City.png" ,"../images/Paris.png" ,"../images/London.png"};
		Hand_clock hand_second{ "../images/4_1.png" };
		Hand_clock hand_minute{"../images/1_1.png"};
		Hand_clock hand_hour{"../images/2_4.png"};
		SDL_Texture* image_clock;
		std::vector<SDL_Texture*> image_text;
		int timezone;
	public:
		
		/**
		 * @brief конструктор класса заполняющий координаты расположения 
		 * циферблата и стрелок. Так же загружает текстуры.
		 * @param numbers координаты для часов и стрелок. 
		 */

		clock_face();
		
		/**
		 * @brief конструктор класса заполняющий координаты расположения 
		 * часов и стрелок нулями. Так же загружает текстуры. 
		 */
		
		clock_face(int x, int y, int w, int h);

		/**
		 * @brief деконструктор класса освобождающий память от текстур. 
		 */
		
		~clock_face();

		/**
		 * @brief Ставит полученные переменные в структуру координат,
		 *  отвечающих за расположение циферблата. 
		 * @param numbers координаты для циферблата. 
		 */

		void set_dst(int x, int y, int w, int h);
		
		/**
		 * @brief Возвращает координаты циферблата
		 * @return Sdl_Rect координаты циферблата
		 */

		SDL_Rect get_dst();

		/**
		 * @brief Задаёт координаты всех стрелок,и рендерит циферблат, стрелки и текст.
		 * @param SDL_Renderer Рендер.
		 * @param Numbers ang_second, ang_minute, ang_hour углы для стрелок.
		 * @param int номер часов которые будут рендериться
		 */

		void render_text(SDL_Renderer* ren, int n);

		/**
		 * @brief Задаёт координаты всех стрелок,и рендерит циферблат, стрелки и текст.
		 * @param SDL_Renderer Рендер.
		 * @param int индекс строчки с путём до файла изображения
		 */

		void render_clock(SDL_Renderer* ren, int ang_second, int ang_minute, int ang_hour, int i);
	};
