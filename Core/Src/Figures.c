#include "Figures.h"


void drawingHLine (uint16_t margines_x, uint16_t margines_y, uint16_t dlugosc){ //rysowanie poziomej linii

	  for (int wysokosc = 0; wysokosc < sizeX; wysokosc++)
	  {
		  for (int szerokosc = 0; szerokosc < sizeY; szerokosc++)
	      {
			  //pozioma
			  if (wysokosc == margines_y)
	          {
				  if (szerokosc >= margines_x && szerokosc <= margines_x + dlugosc)
	              {
					  BSP_LCD_DrawPixel(szerokosc, wysokosc, (0-0-0-0));
	              }
	          }
	      }
	  }
}

void drawingVLine (uint16_t margines_x, uint16_t margines_y, uint16_t dlugosc){ //rysowanie pionowej linii

	 for (int wysokosc = 0; wysokosc < sizeX; wysokosc++)
		  {
			  for (int szerokosc = 0; szerokosc < sizeY; szerokosc++)
		      {
		          //pionowa
		          if (szerokosc == margines_x)
		          {
		        	  if (wysokosc >= margines_y && wysokosc <= margines_y + dlugosc)
		              {
						  BSP_LCD_DrawPixel(szerokosc, wysokosc, (0-0-0-0));
		              }
		          }
		      }
		  }
}

