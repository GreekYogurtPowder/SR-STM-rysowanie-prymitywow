#ifndef INC_FIGURES_H_
#define INC_FIGURES_H_

#include "..\..\Drivers\BSP\STM32F429I-Discovery\stm32f429i_discovery.h"
#include "..\..\Drivers\BSP\STM32F429I-Discovery\stm32f429i_discovery_lcd.h"
#include "..\..\Drivers\BSP\STM32F429I-Discovery\stm32f429i_discovery_sdram.h"
#include "..\..\Drivers\BSP\Components\ili9341\ili9341.h"

//wymiary ekranu (do sprawdzenia)
static int sizeX = 240;
static int sizeY = 320;

void drawingHLine (uint16_t margines_x, uint16_t margines_y, uint16_t dlugosc); //rysowanie poziomej linii
void drawingVLine (uint16_t margines_x, uint16_t margines_y, uint16_t dlugosc); //rysowanie pionowej linii
void drawingLine (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2); //rysowanie dowolnej linii
void drawingRectangle (uint16_t margines_x, uint16_t margines_y, uint16_t dlugosc_boku_x, uint16_t dlugosc_boku_y); //rysowanie prostokata
void drawingTriangle (uint16_t margines_x, uint16_t margines_y, uint16_t dlugosc_boku); //rysowanie trojkata

#endif /* INC_FIGURES_H_ */
