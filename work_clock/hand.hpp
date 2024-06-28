#include "main.h"

class Hand_clock{
	private:
		int ang;
		SDL_Rect dst;
		std::string file;
		SDL_Texture* image_hand;
	public:
		Hand_clock();
		~Hand_clock();
		void set_dst(int x, int y, int w, int h);
		SDL_Rect get_dst();
		void renderTextureAngl(SDL_Renderer* ren, int ang);
};