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

