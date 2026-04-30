/*
 * cordic_drive.h
 *
 *  Created on: Apr 29, 2026
 *      Author: Shiva_thinik
 */

#ifndef INC_CORDIC_DRIVE_H_
#define INC_CORDIC_DRIVE_H_

#include <stdint.h>
#include "stm32g4xx_hal.h"
#include "stm32g431xx.h"

extern CORDIC_HandleTypeDef hcordic;
extern DMA_HandleTypeDef hdma_cordic_read;
extern DMA_HandleTypeDef hdma_cordic_write;

#endif /* INC_CORDIC_DRIVE_H_ */
