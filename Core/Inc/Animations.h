#ifndef INC_ANIMATIONS_H_
#define INC_ANIMATIONS_H_

#include "..\..\Drivers\BSP\STM32F429I-Discovery\stm32f429i_discovery.h"
#include "..\..\Drivers\BSP\STM32F429I-Discovery\stm32f429i_discovery_lcd.h"
#include "..\..\Drivers\BSP\STM32F429I-Discovery\stm32f429i_discovery_sdram.h"
#include "..\..\Drivers\BSP\Components\ili9341\ili9341.h"
#include "Figures.h"

/**
 * Definitions of animated functions:
 */

void animationLine (uint16_t poczatek_x, uint16_t poczatek_y, uint16_t koniec_x, uint16_t koniec_y, uint16_t odstep, uint16_t czas);
void animationRectangle (uint16_t margines_x, uint16_t margines_y, uint16_t dlugosc_boku_x, uint16_t dlugosc_boku_y, uint16_t ilosc, uint16_t czas);
void animationJumpingRectangle (uint16_t dlugosc_boku_x, uint16_t dlugosc_boku_y, uint16_t czas);
void animationTriangle (uint16_t margines_x, uint16_t margines_y, uint16_t dlugosc_boku, uint16_t ilosc, uint16_t czas);
void animationCircle (uint16_t x_pos, uint16_t y_pos, uint16_t rad, uint16_t count, uint16_t time);
void animationText (uint16_t x_pos, uint16_t y_pos, uint16_t time);

#endif /* INC_ANIMATIONS_H_ */
