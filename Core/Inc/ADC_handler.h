/*
 * ADC_handler.h
 *
 *  Created on: Jun 11, 2026
 *      Author: Shiva_thinik
 */

#ifndef INC_ADC_HANDLER_H_
#define INC_ADC_HANDLER_H_
#include "stm32g4xx_hal.h"
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

typedef	struct
{
	uint32_t value;
	uint8_t state; //0 - без изменений  1 - требуется пересчет таблицы
} ADC_valueTypeDef;



#endif /* INC_ADC_HANDLER_H_ */
