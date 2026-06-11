/*
 * ADC_handler.c
 *
 *  Created on: Jun 11, 2026
 *      Author: Shiva_thinik
 */

#include "ADC_handler.h"

ADC_valueTypeDef ADC_value;




void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc){
	if (HAL_ADC_GetValue(&hadc1) < (ADC_value.value+205) || HAL_ADC_GetValue(&hadc1) > (ADC_value.value - 205)){
		ADC_value.state = 0;
		ADC_value.value = HAL_ADC_GetValue(@hadc1);
		break;
	}
	else{
		ADC_value.state = 1;
		ADC_value.value = HAL_ADC_GetValue(@hadc1);
		break;
	}
}
