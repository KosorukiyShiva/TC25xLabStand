/*
 * driver.h
 *
 *  Created on: Mar 20, 2026
 *      Author: Shiva_thinik
 */


#ifndef INC_DRIVER_H_
#define INC_DRIVER_H_

//#include"main.h"
//#include "stm32g4xx_hal.h"
#include <stdint.h>
#include <main.h>

 typedef enum {
	 OFF,
//	 SMLL_FRC,
//	 BG_FRC,

	 ON1,
	 ON2
 }duty_subrange;



 void Quicksort_signal( uint8_t * map, uint8_t duty, uint8_t * PWM_ch1);

 uint8_t sort_signal( uint32_t* signal, uint8_t* map, uint8_t duty, uint32_t* PWM_ch11, uint32_t* PWM_ch21);
 uint8_t mirror_signal(uint16_t SIZE, uint32_t* PWM_ch11, uint32_t* PWM_ch21);
 uint8_t shift_channels(uint32_t* PWM_ch11, uint32_t* PWM_ch12, uint32_t* PWM_ch13, uint32_t* PWM_ch21, uint32_t* PWM_ch22, uint32_t* PWM_ch23, uint16_t SIZE);
 void clear_chanels(uint8_t* PWM_ch1, uint8_t* PWM_ch2, uint8_t* PWM_ch3);
#endif /* INC_DRIVER_H_ */
