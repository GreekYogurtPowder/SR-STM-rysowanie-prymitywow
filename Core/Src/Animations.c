#include "Animations.h"

/**
 * @brief draws animation of the line
 * @param poczatek_x starting X position
 * @param poczatek_y starting Y position
 * @param koniec_x end X position
 * @param koniec_y end Y position
 * @param odstep number of pixels beetwen next lines
 * @param czas the time between drawings
 */

void animationLine (uint16_t poczatek_x, uint16_t poczatek_y, uint16_t koniec_x, uint16_t koniec_y, uint16_t odstep, uint16_t czas) {

	//rysowanie linii od lewej prawej
	for(int i = 0; (poczatek_x + i) < koniec_x; i += odstep) {
		DrawLine(poczatek_x + i, poczatek_y, koniec_x - i, koniec_y, 2164260608 + i*10);
		DrawLine(poczatek_x + i + 1, poczatek_y, koniec_x - i - 1 , koniec_y, 2164260608 + i*10);
		DrawLine(poczatek_x + i + 2, poczatek_y, koniec_x - i - 2, koniec_y, 2164260608 + i*10);
		DrawLine(poczatek_x + i + 3, poczatek_y, koniec_x - i - 3 , koniec_y, 2164260608 + i*10);
		DrawLine(poczatek_x + i + 4, poczatek_y, koniec_x - i - 4, koniec_y, 2164260608 + i*10);
		HAL_Delay(czas);
	}

	//rysowanie linii od gory do dolu
	for(int i = 0; (poczatek_y + i) < koniec_y; i += odstep) {
		DrawLine(koniec_x, poczatek_y + i, poczatek_x, koniec_y - i, 2164260608 + i*10);
		DrawLine(koniec_x, poczatek_y + i + 1, poczatek_x, koniec_y - i - 1, 2164260608 + i*10);
		DrawLine(koniec_x, poczatek_y + i + 2, poczatek_x, koniec_y - i - 2, 2164260608 + i*10);
		DrawLine(koniec_x, poczatek_y + i + 3, poczatek_x, koniec_y - i - 3, 2164260608 + i*10);
		DrawLine(koniec_x, poczatek_y + i + 4, poczatek_x, koniec_y - i - 4, 2164260608 + i*10);
		HAL_Delay(czas);
	}

	//czyszczenie linii od lewej prawej
	for(int i = 0; (poczatek_x + i) < koniec_x; i += odstep) {
		DrawLine(poczatek_x + i, poczatek_y, koniec_x - i, koniec_y, BSP_LCD_GetBackColor());
		DrawLine(poczatek_x + i + 1, poczatek_y, koniec_x - i - 1, koniec_y, BSP_LCD_GetBackColor());
		DrawLine(poczatek_x + i + 2, poczatek_y, koniec_x - i - 2, koniec_y, BSP_LCD_GetBackColor());
		DrawLine(poczatek_x + i + 3, poczatek_y, koniec_x - i - 3, koniec_y, BSP_LCD_GetBackColor());
		DrawLine(poczatek_x + i + 4, poczatek_y, koniec_x - i - 4, koniec_y, BSP_LCD_GetBackColor());
		HAL_Delay(czas);
	}

	//czyszczenie linii od gory do dolu
	for(int i = 0; (poczatek_y + i) < koniec_y; i += odstep) {
		DrawLine(koniec_x, poczatek_y + i, poczatek_x, koniec_y - i, BSP_LCD_GetBackColor());
		DrawLine(koniec_x, poczatek_y + i + 1, poczatek_x, koniec_y - i - 1, BSP_LCD_GetBackColor());
		DrawLine(koniec_x, poczatek_y + i + 2, poczatek_x, koniec_y - i - 2, BSP_LCD_GetBackColor());
		DrawLine(koniec_x, poczatek_y + i + 3, poczatek_x, koniec_y - i - 3, BSP_LCD_GetBackColor());
		DrawLine(koniec_x, poczatek_y + i + 4, poczatek_x, koniec_y - i - 4, BSP_LCD_GetBackColor());
		HAL_Delay(czas);
	}

}

/**
 * @brief draws animation of the rectangle
 * @param margines_x starting X position
 * @param margines_y starting Y position
 * @param dlugosc_boku_x length of the first side of a rectangle
 * @param dlugosc_boku_y length of the second side of a rectangle
 * @param ilosc the number of rectangles
 * @param czas the time between drawings
 */

void animationRectangle (uint16_t margines_x, uint16_t margines_y, uint16_t dlugosc_boku_x, uint16_t dlugosc_boku_y, uint16_t ilosc, uint16_t czas) {

	for(int i = 0; i<ilosc; i++){

		//rysowanie po przekatnej
		drawingRectangle(margines_x + i, margines_y + i, dlugosc_boku_x, dlugosc_boku_y, 2164260608 + i*10);
		drawingRectangle(margines_x - i, margines_y - i, dlugosc_boku_x, dlugosc_boku_y, 2164260608 + i*10);
		drawingRectangle(margines_x + i, margines_y - i, dlugosc_boku_x, dlugosc_boku_y, 2164260608 + i*10);
		drawingRectangle(margines_x - i, margines_y + i, dlugosc_boku_x, dlugosc_boku_y, 2164260608 + i*10);

		//rysowanie pionowo i poziomo
		drawingRectangle(margines_x, margines_y + i, dlugosc_boku_x, dlugosc_boku_y, 2164260608 + i*10);
		drawingRectangle(margines_x, margines_y - i, dlugosc_boku_x, dlugosc_boku_y, 2164260608 + i*10);
		drawingRectangle(margines_x + i, margines_y, dlugosc_boku_x, dlugosc_boku_y, 2164260608 + i*10);
		drawingRectangle(margines_x - i, margines_y, dlugosc_boku_x, dlugosc_boku_y, 2164260608 + i*10);

		HAL_Delay(czas);
	}

	for(int i = 0; i<ilosc; i++){

		//czyszczenie po przekatnej
		drawingRectangle(margines_x + i, margines_y + i, dlugosc_boku_x, dlugosc_boku_y, BSP_LCD_GetBackColor());
		drawingRectangle(margines_x - i, margines_y - i, dlugosc_boku_x, dlugosc_boku_y, BSP_LCD_GetBackColor());
		drawingRectangle(margines_x + i, margines_y - i, dlugosc_boku_x, dlugosc_boku_y, BSP_LCD_GetBackColor());
		drawingRectangle(margines_x - i, margines_y + i, dlugosc_boku_x, dlugosc_boku_y, BSP_LCD_GetBackColor());

		//czyszczenie pionowo i poziomo
		drawingRectangle(margines_x, margines_y + i, dlugosc_boku_x, dlugosc_boku_y, BSP_LCD_GetBackColor());
		drawingRectangle(margines_x, margines_y - i, dlugosc_boku_x, dlugosc_boku_y, BSP_LCD_GetBackColor());
		drawingRectangle(margines_x + i, margines_y, dlugosc_boku_x, dlugosc_boku_y, BSP_LCD_GetBackColor());
		drawingRectangle(margines_x - i, margines_y, dlugosc_boku_x, dlugosc_boku_y, BSP_LCD_GetBackColor());

		HAL_Delay(czas);
	}

}

/**
 * @brief draws animation of the triangle
 * @param margines_x starting X position
 * @param margines_y starting Y position
 * @param dlugosc_boku_x length of the side of a triangle
 * @param ilosc the number of triangle
 * @param czas the time between triangle
 */

void animationTriangle (uint16_t margines_x, uint16_t margines_y, uint16_t dlugosc_boku, uint16_t ilosc, uint16_t czas) {

	for(int i = 0; i<ilosc; i++){

		//rysowanie po przekatnej
		drawingTriangle(margines_x + i, margines_y + i, dlugosc_boku, 2164260608 + i*10);
		drawingTriangle(margines_x - i, margines_y - i, dlugosc_boku, 2164260608 + i*10);
		drawingTriangle(margines_x + i, margines_y - i, dlugosc_boku, 2164260608 + i*10);
		drawingTriangle(margines_x - i, margines_y + i, dlugosc_boku, 2164260608 + i*10);

		//rysowanie pionowo i poziomo
		drawingTriangle(margines_x, margines_y + i, dlugosc_boku, 2164260608 + i*10);
		drawingTriangle(margines_x, margines_y - i, dlugosc_boku, 2164260608 + i*10);
		drawingTriangle(margines_x + i, margines_y, dlugosc_boku, 2164260608 + i*10);
		drawingTriangle(margines_x - i, margines_y, dlugosc_boku, 2164260608 + i*10);

		HAL_Delay(czas);
	}

	for(int i = 0; i<ilosc; i++){

		//czyszczenie po przekatnej
		drawingTriangle(margines_x + i, margines_y + i, dlugosc_boku, BSP_LCD_GetBackColor());
		drawingTriangle(margines_x - i, margines_y - i, dlugosc_boku, BSP_LCD_GetBackColor());
		drawingTriangle(margines_x + i, margines_y - i, dlugosc_boku, BSP_LCD_GetBackColor());
		drawingTriangle(margines_x - i, margines_y + i, dlugosc_boku, BSP_LCD_GetBackColor());

		//czyszczenie pionowo i poziomo
		drawingTriangle(margines_x, margines_y + i, dlugosc_boku, BSP_LCD_GetBackColor());
		drawingTriangle(margines_x, margines_y - i, dlugosc_boku, BSP_LCD_GetBackColor());
		drawingTriangle(margines_x + i, margines_y, dlugosc_boku, BSP_LCD_GetBackColor());
		drawingTriangle(margines_x - i, margines_y, dlugosc_boku, BSP_LCD_GetBackColor());

		HAL_Delay(czas);
	}

}

/**
 * @brief draws animation of the circle
 * @param x_pos X position of the animation
 * @param y_pos Y position of the animation
 * @param rad	the radius of the first circle
 * @param count	the number of circles
 * @param time	the time between drawings
 */

void animationCircle (uint16_t x_pos, uint16_t y_pos, uint16_t rad, uint16_t count, uint16_t time)
{

	//drawing animations with pixels
	for(int i = 0; i<count; i++){
		//diagonally
		drawingCircle(x_pos + i, y_pos + i, rad, 2164260608 + i*10);
		drawingCircle(x_pos - i, y_pos - i, rad, 2164260608 + i*10);
		drawingCircle(x_pos + i, y_pos - i, rad, 2164260608 + i*10);
		drawingCircle(x_pos - i, y_pos + i, rad, 2164260608 + i*10);

		//vertically and horizontally
		drawingCircle(x_pos, y_pos + i, rad, 2164260608 + i*10);
		drawingCircle(x_pos, y_pos - i, rad, 2164260608 + i*10);
		drawingCircle(x_pos + i, y_pos, rad, 2164260608 + i*10);
		drawingCircle(x_pos - i, y_pos, rad, 2164260608 + i*10);

		HAL_Delay(time);
	}

	//clearing the screen by drawing with pixels
	for(int i = 0; i<count; i++){
		//diagonally
		drawingCircle(x_pos + i, y_pos + i, rad, BSP_LCD_GetBackColor());
		drawingCircle(x_pos - i, y_pos - i, rad, BSP_LCD_GetBackColor());
		drawingCircle(x_pos + i, y_pos - i, rad, BSP_LCD_GetBackColor());
		drawingCircle(x_pos - i, y_pos + i, rad, BSP_LCD_GetBackColor());

		//vertically and horizontally
		drawingCircle(x_pos, y_pos + i, rad, BSP_LCD_GetBackColor());
		drawingCircle(x_pos, y_pos - i, rad, BSP_LCD_GetBackColor());
		drawingCircle(x_pos + i, y_pos, rad, BSP_LCD_GetBackColor());
		drawingCircle(x_pos - i, y_pos, rad, BSP_LCD_GetBackColor());

		HAL_Delay(time);
	}
}

/**
 * @brief draws animation of the text
 * @param x_pos X position of the bottom right corner of the animation
 * @param y_pos Y position of the bottom right corner of the animation
 */

void animationText (uint16_t x_pos, uint16_t y_pos, uint16_t time)
{
	uint32_t color = 2164272953;
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			drawingText(5, 60 + j + 30*i, color + 12345*i);
			HAL_Delay(500);
		}
		HAL_Delay(time);
	}
	for(int i = 0; i<5; i++){
		for(int j = 0; j<10; j++){
			drawingText(5, 60 + 2*j + 30*i, BSP_LCD_GetBackColor());
			HAL_Delay(500);
		}
		HAL_Delay(time);
	}
}
