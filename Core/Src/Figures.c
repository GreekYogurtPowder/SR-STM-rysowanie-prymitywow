#include "Figures.h"

//pogrubic kreski i ma byc na bialym tle
void drawingHLine (uint16_t margines_x, uint16_t margines_y, uint16_t dlugosc){ //rysowanie poziomej linii

	  for (int wysokosc = 0; wysokosc < sizeY; wysokosc++)
	  {
		  for (int szerokosc = 0; szerokosc < sizeX; szerokosc++)
	      {
			  //pozioma
			  if (wysokosc == margines_y)
	          {
				  if (szerokosc >= margines_x && szerokosc <= margines_x + dlugosc)
	              {
					  BSP_LCD_DrawPixel(szerokosc, wysokosc, (0)); //taki ma byc kod
	              }
	          }
	      }
	  }
}

void drawingVLine (uint16_t margines_x, uint16_t margines_y, uint16_t dlugosc){ //rysowanie pionowej linii

	 for (int wysokosc = 0; wysokosc < sizeY; wysokosc++)
		  {
			  for (int szerokosc = 0; szerokosc < sizeX; szerokosc++)
		      {
		          //pionowa
		          if (szerokosc == margines_x)
		          {
		        	  if (wysokosc >= margines_y && wysokosc <= margines_y + dlugosc)
		              {
						  BSP_LCD_DrawPixel(szerokosc, wysokosc, (0));
		              }
		          }
		      }
		  }
}

void drawingLine (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) { //rysowanie dowolnej linii

    int m_new = 2 * (x2 - x1);
    int slope_error_new = m_new - (y2 - y1);

    for(int y = y1, x = x1; y <= y2; y++) {
    	BSP_LCD_DrawPixel(x, y, (0));

        slope_error_new += m_new;

        if(slope_error_new >= 0) {
            x++;
            slope_error_new -= 2 * (y2 - y1);
        }
    }

}

void drawingRectangle (uint16_t margines_x, uint16_t margines_y, uint16_t dlugosc_boku_x, uint16_t dlugosc_boku_y) { //rysowanie prostokata

    for (int wysokosc = 0; wysokosc < sizeY; wysokosc++)
    {
        for (int szerokosc = 0; szerokosc < sizeX; szerokosc++)
        {

            if (wysokosc == margines_y || wysokosc == margines_y + dlugosc_boku_y)
            {
                if (szerokosc >= margines_x && szerokosc <= margines_x + dlugosc_boku_x)
					  BSP_LCD_DrawPixel(szerokosc, wysokosc, (0));

            } else if (szerokosc == margines_x || szerokosc == margines_x + dlugosc_boku_x)
            {
                if (wysokosc >= margines_y && wysokosc <= margines_y + dlugosc_boku_y)
					  BSP_LCD_DrawPixel(szerokosc, wysokosc, (0));
            }

        }
    }
}

void drawingTriangle (uint16_t margines_x, uint16_t margines_y, uint16_t dlugosc_boku) { //rysowanie trojkata

    int wskaznik_skosnej_1 = margines_x + dlugosc_boku/2;
    int wskaznik_skosnej_2 = margines_x + dlugosc_boku/2;

    for (int wysokosc = 0; wysokosc < sizeY; wysokosc++)
    {
        for (int szerokosc = 0; szerokosc < sizeX; szerokosc++)
        {
            if (wysokosc >= margines_y && wysokosc < margines_y + dlugosc_boku/2)
            {
                if (szerokosc == wskaznik_skosnej_1 || szerokosc == wskaznik_skosnej_2) //linie skosne
					  BSP_LCD_DrawPixel(szerokosc, wysokosc, (0));
            }

            if (wysokosc == margines_y + dlugosc_boku/2) //linia pozioma
            {
                if (szerokosc >= margines_x && szerokosc <= margines_x + dlugosc_boku)
					  BSP_LCD_DrawPixel(szerokosc, wysokosc, (0));
            }

        }

        if (wysokosc >= margines_y && wysokosc < margines_y + dlugosc_boku)
        {
            wskaznik_skosnej_1--;
            wskaznik_skosnej_2++;
        }
    }
}


/**
 * @brief draws circle
 * @param x_pos X position of the center of the circle
 * @param y_pos Y position of the center of the circle
 * @param rad	the radius of the circle
 * @param color	the color of the circle
 */

///RGB_Code: the pixel color in ARGB mode (8-8-8-8)

void drawingCircle (uint16_t x_pos, uint16_t y_pos, uint16_t rad, uint32_t color)
{
	uint16_t x_cur = 0;
    uint16_t y_cur = rad;
    int16_t c = 2 * (1 - rad);

    while(x_cur <= y_cur)
    {
        BSP_LCD_DrawPixel(x_pos + x_cur, y_pos + y_cur, color);
        BSP_LCD_DrawPixel(x_pos + -x_cur,y_pos + y_cur, color);
        BSP_LCD_DrawPixel(x_pos + -x_cur,y_pos + -y_cur, color);
        BSP_LCD_DrawPixel(x_pos + x_cur,y_pos + -y_cur, color);

        BSP_LCD_DrawPixel(x_pos + y_cur,y_pos + x_cur, color);
        BSP_LCD_DrawPixel(x_pos + -y_cur,y_pos + x_cur, color);
        BSP_LCD_DrawPixel(x_pos + -y_cur,y_pos + -x_cur, color);
        BSP_LCD_DrawPixel(x_pos + y_cur,y_pos + -x_cur, color);

        if(2 * c > 1 - 2 * y_cur)
        {
            y_cur--;
            c -= 2 * y_cur - 1;
        }
        x_cur++;
        c += 2 * x_cur + 1;
    }
}

/**
 * @brief draws line from the point (x1,y1) to the point (x2,y2)
 * @param x1 X position of the beginning point
 * @param y1 Y position of the beginning point
 * @param x2 X position of the beginning point
 * @param y2 Y position of the beginning point
 * @param color	the color of the line
 *
 * source: http://mst.mimuw.edu.pl/lecture.php?lecture=gk1&part=Ch2
 */

void DrawLine ( int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint32_t color)
{
    int16_t delta_x, delta_y, g, h, c;

    delta_x = x2-x1;
    if (delta_x > 0)
        g = +1;
    else
        g = -1;
    delta_x = abs(delta_x);
    delta_y = y2-y1;
    if (delta_y > 0)
        h = +1;
    else
        h = -1;
    delta_y = abs(delta_y);
    if (delta_x > delta_y)
    {
        c = -delta_x;
        while (x1 != x2) {
        BSP_LCD_DrawPixel(x1,y1, color);
        c += 2*delta_y;
        if (c > 0)
        {
            y1 += h;
            c -= 2*delta_x;
        }
        x1 += g;
        }
    }
    else
    {
        c = -delta_y;
        while (y1 != y2)
        {
            BSP_LCD_DrawPixel(x1,y1, color);
            c += 2*delta_x;
            if (c > 0)
            {
                x1 += g;
                c -= 2*delta_y;
            }
            y1 += h;
        }
    }
}

/**
 * @brief draws letter D
 * @param x_pos X position of the bottom left corner of the letter
 * @param y_pos Y position of the bottom left corner of the letter
 */

void drawingLetterD (uint16_t x_pos, uint16_t y_pos, uint32_t color)
{
    DrawLine(x_pos, y_pos, x_pos, y_pos-45, color);

    x_pos = (int16_t)x_pos;
    y_pos = (int16_t)(y_pos - 23);
    int16_t rad = 24;
    int16_t x = 0;
    int16_t y = rad;
    int16_t c = 2*(1 - rad);

    while(x<=y)
    {
        BSP_LCD_DrawPixel(x_pos + x, y_pos + y, color);
        BSP_LCD_DrawPixel(x_pos + x,y_pos + -y, color);

        BSP_LCD_DrawPixel(x_pos + y,y_pos + x, color);
        BSP_LCD_DrawPixel(x_pos + y,y_pos + -x, color);
        if(2*c > 1-2*y){
            y--;
            c -= 2*y-1;
        }
        x++;
        c+=2*x+1;
    }
}

/**
 * @brief draws letter C
 * @param x_pos X position of the bottom left corner of the letter
 * @param y_pos Y position of the bottom left corner of the letter
 */

void drawingLetterC (uint16_t x_pos, uint16_t y_pos, uint32_t color)
{
    y_pos = y_pos - 23;

    int16_t rad = 24;

    int16_t x = 0;
    int16_t y = rad;

    int16_t c = 2*(1 - rad);

    while(x<=y){
        BSP_LCD_DrawPixel(x_pos + -x,y_pos + y, color);
        BSP_LCD_DrawPixel(x_pos + -x,y_pos + -y, color);

        BSP_LCD_DrawPixel(x_pos + -y,y_pos + x, color);
        BSP_LCD_DrawPixel(x_pos + -y,y_pos + -x, color);
        if(2*c > 1-2*y){
            y--;
            c -= 2*y-1;
        }
        x++;
        c+=2*x+1;
    }
}

/**
 * @brief draws letter A
 * @param x_pos X position of the bottom left corner of the letter
 * @param y_pos Y position of the bottom left corner of the letter
 */

void drawingLetterA (uint16_t x_pos, uint16_t y_pos, uint32_t color)
{
     DrawLine(x_pos, y_pos, x_pos+20, y_pos-45, color);
     DrawLine(x_pos+20, y_pos-45, x_pos+40, y_pos, color);
     DrawLine(x_pos+5, y_pos-25, x_pos+35, y_pos-25, color);
}

/**
 * @brief draws letter W
 * @param x_pos X position of the bottom left corner of the letter
 * @param y_pos Y position of the bottom left corner of the letter
 */

void drawingLetterW (uint16_t x_pos, uint16_t y_pos, uint32_t color)
{
     DrawLine(x_pos, y_pos-25, x_pos+10, y_pos, color);
     DrawLine(x_pos+10, y_pos, x_pos+20, y_pos-20, color);
     DrawLine(x_pos+20, y_pos-20, x_pos+30, y_pos, color);
     DrawLine(x_pos+30, y_pos, x_pos+40, y_pos-25, color);
}

/**
 * @brief draws letter N
 * @param x_pos X position of the bottom left corner of the letter
 * @param y_pos Y position of the bottom left corner of the letter
 */

void drawingLetterN (uint16_t x_pos, uint16_t y_pos, uint32_t color)
{
     DrawLine(x_pos, y_pos-25, x_pos, y_pos, color);
     DrawLine(x_pos, y_pos-25, x_pos+15, y_pos, color);
     DrawLine(x_pos+15, y_pos, x_pos+15, y_pos-25, color);
}

/**
 * @brief draws letter L
 * @param x_pos X position of the bottom right corner of the letter
 * @param y_pos Y position of the bottom right corner of the letter
 */

void drawingLetterL (uint16_t x_pos, uint16_t y_pos, uint32_t color)
{
     DrawLine(x_pos, y_pos, x_pos, y_pos-45, color);
     DrawLine(x_pos, y_pos, x_pos+30, y_pos, color);
}

/**
 * @brief draws text AwnLCD
 * @param x_pos X position of the bottom right corner of the letter
 * @param y_pos Y position of the bottom right corner of the letter
 */

void drawingText (uint16_t x_pos, uint16_t y_pos, uint32_t color)
{
	for(int i = 0; i < 6; i++){
		drawingLetterA(x_pos + i, y_pos + i, color);
		drawingLetterW(x_pos + i + 40, y_pos + i, color);
		drawingLetterN(x_pos + i + 85, y_pos + i, color);
		drawingLetterL(x_pos + i + 120, y_pos + i, color);
		drawingLetterC(x_pos + i + 175, y_pos + i, color);
		drawingLetterD(x_pos + i + 195, y_pos + i, color);
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

void animationText (uint16_t x_pos, uint16_t y_pos)
{
	uint16_t time = 200;

	uint32_t color = 2164272953;
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			drawingText(5, 60 + j + 30*i, color + 12345*i);
			HAL_Delay(500);
		}
		HAL_Delay(1000);
	}
	for(int i = 0; i<5; i++){
		for(int j = 0; j<10; j++){
			drawingText(5, 60 + 2*j + 30*i, BSP_LCD_GetBackColor());
			HAL_Delay(500);
		}
		HAL_Delay(1000);
	}
}

