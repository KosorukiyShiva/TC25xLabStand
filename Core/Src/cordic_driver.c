/*
 * cordic_driver.c
 *
 *  Created on: Jun 11, 2026
 *      Author: Shiva_thinik
 */
#include "cordic_driver.h"

void wave_generator(ADC_valueTypeDef ADC_val, uint32_t* output_signal){
	uint16_t pos = 4;
	if (ADC_val.state !=0){
		ADC_val.state = ADC_val.value/ADC_DEVIDER;
		switch (ADC_val.state) {
			case 0:
				for (uint16_t i = 0; i < WAVE_SIZE; i++) {
					output_signal[i] = 0;
				}
				ADC_val.state = 0
				break;
			case 1:
				output_signal[0] = 0x0;
				output_signal[1] = 0x1000000;
				output_signal[2] = 0x2000000;
				output_signal[3] = 0x3000000;
				while(output_signal[pos - 4 ] != 0xFF000000){
					output_signal[pos] = output_signal[pos-3] << 2;
					output_signal[pos+1] = output_signal[pos] | output_signal[pos-3];
					output_signal[pos+2] = output_signal[pos] | output_signal[pos-2];
					output_signal[pos+3] = output_signal[pos] | output_signal[pos-1];
				}

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			case 7:

				break;
			case 8:

				break;
			default:
				break;
		}
	}

}
