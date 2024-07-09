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
		clock_face();
		clock_face(int x, int y, int w, int h);
		~clock_face();
		void set_dst(int x, int y, int w, int h);
		SDL_Rect get_dst();
		void render_text(SDL_Renderer* ren, int n);
		void render_clock(SDL_Renderer* ren, int ang_second, int ang_minute, int ang_hour, int i);
};
