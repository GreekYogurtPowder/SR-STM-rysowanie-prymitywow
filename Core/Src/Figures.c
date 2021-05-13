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

void DrawCircle (uint16_t x_pos, uint16_t y_pos, uint16_t rad, uint32_t color)
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
 */

void DrawLine ( int16_t x1, int16_t y1, int16_t x2, int16_t y2)
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
        BSP_LCD_DrawPixel(x1,y1, (0));
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
            BSP_LCD_DrawPixel(x1,y1, (0));
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

void DrawLetterD (uint16_t x_pos, uint16_t y_pos)
{
    DrawLine(x_pos, y_pos, x_pos, y_pos-45);

    x_pos = (int16_t)x_pos;
    y_pos = (int16_t)(y_pos - 23);
    int16_t rad = 24;
    int16_t x = 0;
    int16_t y = rad;
    int16_t c = 2*(1 - rad);

    while(x<=y)
    {
        BSP_LCD_DrawPixel(x_pos + x, y_pos + y, (0));
        BSP_LCD_DrawPixel(x_pos + x,y_pos + -y, (0));

        BSP_LCD_DrawPixel(x_pos + y,y_pos + x, (0));
        BSP_LCD_DrawPixel(x_pos + y,y_pos + -x, (0));
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

void DrawLetterC (uint16_t x_pos, uint16_t y_pos)
{
    y_pos = y_pos - 23;

    int16_t rad = 24;

    int16_t x = 0;
    int16_t y = rad;

    int16_t c = 2*(1 - rad);

    while(x<=y){
        BSP_LCD_DrawPixel(x_pos + -x,y_pos + y, (0));
        BSP_LCD_DrawPixel(x_pos + -x,y_pos + -y, (0));

        BSP_LCD_DrawPixel(x_pos + -y,y_pos + x, (0));
        BSP_LCD_DrawPixel(x_pos + -y,y_pos + -x, (0));
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

void DrawLetterA (uint16_t x_pos, uint16_t y_pos)
{
     DrawLine(x_pos, y_pos, x_pos+20, y_pos-45);
     DrawLine(x_pos+20, y_pos-45, x_pos+40, y_pos);
     DrawLine(x_pos+5, y_pos-25, x_pos+35, y_pos-25);
}

/**
 * @brief draws letter W
 * @param x_pos X position of the bottom left corner of the letter
 * @param y_pos Y position of the bottom left corner of the letter
 */

void DrawLetterW (uint16_t x_pos, uint16_t y_pos)
{
     DrawLine(x_pos, y_pos-25, x_pos+10, y_pos);
     DrawLine(x_pos+10, y_pos, x_pos+20, y_pos-20);
     DrawLine(x_pos+20, y_pos-20, x_pos+30, y_pos);
     DrawLine(x_pos+30, y_pos, x_pos+40, y_pos-25);
}

/**
 * @brief draws letter N
 * @param x_pos X position of the bottom left corner of the letter
 * @param y_pos Y position of the bottom left corner of the letter
 */

void DrawLetterN (uint16_t x_pos, uint16_t y_pos)
{
     DrawLine(x_pos, y_pos-25, x_pos, y_pos);
     DrawLine(x_pos, y_pos-25, x_pos+15, y_pos);
     DrawLine(x_pos+15, y_pos, x_pos+15, y_pos-25);
}

/**
 * @brief draws letter L
 * @param x_pos X position of the bottom right corner of the letter
 * @param y_pos Y position of the bottom right corner of the letter
 */

void DrawLetterL (uint16_t x_pos, uint16_t y_pos)
{
     DrawLine(x_pos, y_pos, x_pos, y_pos-45);
     DrawLine(x_pos, y_pos, x_pos+30, y_pos);
}

/**
 * @brief draws animation of the circle
 * @param x_pos X position of the bottom right corner of the letter
 * @param y_pos Y position of the bottom right corner of the letter
 * @param rad	the radius of the circle
 * @param count	the number of circles
 * @param time	the time between drawings
 */

void AnimCircle (uint16_t x_pos, uint16_t y_pos, uint16_t rad, uint16_t count, uint16_t time){

	//drawing animations with pixels
	for(int i = 0; i<count; i++){
		//diagonally
		DrawCircle(x_pos + i, y_pos + i, rad, 2164260608 + i*10);
		DrawCircle(x_pos - i, y_pos - i, rad, 2164260608 + i*10);
		DrawCircle(x_pos + i, y_pos - i, rad, 2164260608 + i*10);
		DrawCircle(x_pos - i, y_pos + i, rad, 2164260608 + i*10);

		//vertically and horizontally
		DrawCircle(x_pos, y_pos + i, rad, 2164260608 + i*10);
		DrawCircle(x_pos, y_pos - i, rad, 2164260608 + i*10);
		DrawCircle(x_pos + i, y_pos, rad, 2164260608 + i*10);
		DrawCircle(x_pos - i, y_pos, rad, 2164260608 + i*10);

		HAL_Delay(time);
	}

	//clearing the screen by drawing with pixels
	for(int i = 0; i<count; i++){
		//diagonally
		DrawCircle(x_pos + i, y_pos + i, rad, BSP_LCD_GetBackColor());
		DrawCircle(x_pos - i, y_pos - i, rad, BSP_LCD_GetBackColor());
		DrawCircle(x_pos + i, y_pos - i, rad, BSP_LCD_GetBackColor());
		DrawCircle(x_pos - i, y_pos + i, rad, BSP_LCD_GetBackColor());

		//vertically and horizontally
		DrawCircle(x_pos, y_pos + i, rad, BSP_LCD_GetBackColor());
		DrawCircle(x_pos, y_pos - i, rad, BSP_LCD_GetBackColor());
		DrawCircle(x_pos + i, y_pos, rad, BSP_LCD_GetBackColor());
		DrawCircle(x_pos - i, y_pos, rad, BSP_LCD_GetBackColor());

		HAL_Delay(time);
	}
}


