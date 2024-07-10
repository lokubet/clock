#pragma once
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 800;
#include <SDL_image.h>
#include "SDL.h"
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream> 
#include <iomanip>
#include <vector>


namespace global {
	extern SDL_Window* window;
	extern SDL_Renderer* renderer;
}

/**
 * @brief Инициализирует библиотеки и создаёт окно и рендер.
 * @return 0 если всё прошло без ошибок.
 */


int initial();

/**
 * @brief Вывод ошибок.
 * @param ostream поток вывода.
 * @param string Причина ошибки
 */

void logSDLError(std::ostream& os, const std::string& msg);


/**
 * @brief Загрузка текстуры.
 * @param string Путь до файла.
 * @param SDL_Renderer Рендер.
 * @return SDL_Texture Возвращает загруженную текстуру.
 */

SDL_Texture* loadTexture(const std::string& file, SDL_Renderer* ren);

/**
 * @brief Рендер полученной текстуры с определёнными свойствами.
 * @param SDL_Texture текстура которую надо отобразить.
 * @param SDL_Renderer рендер.
 * @param SDL_Rect структура координат.
 * @param int угол поворота текстуры.
 */

void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, SDL_Rect dst, int ang);

/**
 * @brief возвращает системное время (час) 
 * @return int системное время (час)
 */

int getHour();

/**
 * @brief возвращает системное время (минута) 
 * @return int системное время (минута)
 */

int getMinute();

/**
 * @brief возвращает системное время (секунда) 
 * @return int системное время (секунда)
 */

int getSecond();