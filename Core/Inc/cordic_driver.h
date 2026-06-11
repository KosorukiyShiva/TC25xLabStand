/*
 * cordic_driver.h
 *
 *  Created on: Jun 11, 2026
 *      Author: Shiva_thinik
 */

#ifndef INC_CORDIC_DRIVER_H_
#define INC_CORDIC_DRIVER_H_
#include "stm32g4xx_hal.h"

#define WAVE_SIZE 256
#define WAVE_CONSTANT 2048  // константное заполенение шим сигнала при не дизармленной системе

#define ADC_DEVIDER 512


uint32_t wave_signal[WAVE_SIZE] = 0;

#endif /* INC_CORDIC_DRIVER_H_ */
