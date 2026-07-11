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
				ADC_val.value = 0;
				ADC_val.state = 0;
				break;
			case 1:  // шаг разделения 1.406 deg общее число эл-тов  256
				output_signal[0] = 0x0;
				output_signal[1] = 0x1000000;
				output_signal[2] = 0x2000000;
				output_signal[3] = 0x3000000;
				while(output_signal[pos - 4 ] != 0xF000000){
					output_signal[pos] = output_signal[pos-3] << 2;
					output_signal[pos+1] = output_signal[pos] | output_signal[pos-3];
					output_signal[pos+2] = output_signal[pos] | output_signal[pos-2];
					output_signal[pos+3] = output_signal[pos] | output_signal[pos-1];
				}

				ADC_val.state = 1;
				break;
			case 2:   // шаг разделения 2.813 deg, общее число эл-тов 128
				output_signal[0] = 0x0;
				output_signal[1] = 0x2000000;
				output_signal[2] = 0x4000000;
				output_signal[3] = 0x6000000;
				while(output_signal[pos - 4 ] != 0xFE000000){
					output_signal[pos] = output_signal[pos-3] << 2;
					output_signal[pos+1] = output_signal[pos] | output_signal[pos-3];
					output_signal[pos+2] = output_signal[pos] | output_signal[pos-2];
					output_signal[pos+3] = output_signal[pos] | output_signal[pos-1];
				}

				ADC_val.state = 1;
				break;
			case 3: // шаг разделения 5.625 deg, общее число эл-тов 64
				output_signal[0] = 0x0;
				output_signal[1] = 0x4000000;
				output_signal[2] = 0x8000000;
				output_signal[3] = 0xC000000;
				while(output_signal[pos - 4 ] != 0xFC000000){
					output_signal[pos] = output_signal[pos-3] << 2;
					output_signal[pos+1] = output_signal[pos] | output_signal[pos-3];
					output_signal[pos+2] = output_signal[pos] | output_signal[pos-2];
					output_signal[pos+3] = output_signal[pos] | output_signal[pos-1];
				}

				ADC_val.state = 1;
				break;
			case 4: // шаг разделения 11.25 deg, общее число эл-тов 32
				output_signal[0] = 0x0;
				output_signal[1] = 0x8000000;
				output_signal[2] = 0x10000000;
				output_signal[3] = 0x18000000;
				while(output_signal[pos - 4 ] != 0xF8000000){
					output_signal[pos] = output_signal[pos-3] << 2;
					output_signal[pos+1] = output_signal[pos] | output_signal[pos-3];
					output_signal[pos+2] = output_signal[pos] | output_signal[pos-2];
					output_signal[pos+3] = output_signal[pos] | output_signal[pos-1];
				}

				ADC_val.state = 1;
				break;
			case 5: // шаг разделения 22.5 deg, общее число эл-тов 16
				output_signal[0] = 0x0;
				output_signal[1] = 0x10000000;
				output_signal[2] = 0x20000000;
				output_signal[3] = 0x30000000;
				while(output_signal[pos - 4 ] != 0xF0000000){
					output_signal[pos] = output_signal[pos-3] << 2;
					output_signal[pos+1] = output_signal[pos] | output_signal[pos-3];
					output_signal[pos+2] = output_signal[pos] | output_signal[pos-2];
					output_signal[pos+3] = output_signal[pos] | output_signal[pos-1];
				}

				ADC_val.state = 1;
				break;
			case 6:  // шаг разделения 45 deg, общее число эл-тов 8
				output_signal[0] = 0x0;
				output_signal[1] = 0x20000000;
				output_signal[2] = 0x40000000;
				output_signal[3] = 0x60000000;
				while(output_signal[pos - 4 ] != 0xE0000000){
					output_signal[pos] = output_signal[pos-3] << 2;
					output_signal[pos+1] = output_signal[pos] | output_signal[pos-3];
					output_signal[pos+2] = output_signal[pos] | output_signal[pos-2];
					output_signal[pos+3] = output_signal[pos] | output_signal[pos-1];
				}

				ADC_val.state = 1;
				break;
			case 7: // шаг разделения 90 deg, общее число эл-тов 4
				output_signal[0] = 0x0;
				output_signal[1] = 0x40000000;
				output_signal[2] = 0x80000000;
				output_signal[3] = 0xC0000000;

				ADC_val.state = 1;
				break;
			default:
				break;
		}
	}

}

void CORDIC_generator(ADC_valueTypeDef ADC_val, uint32_t* argument_table, uint32_t* values_table){
	if (ADC_val.state == 0){
		break;
	}
	else{
		if (ADC_val.value == 0){
			for (uint16_t i = 0; i < WAVE_SIZE; i++) {
				values_table[i] = 0;
			}
		}
		else{
			HAL_CORDIC_Calculate_DMA(&hcordic, argument_table, values_table, WAVE_SIZE, CORDIC_DMA_DIR_IN_OUT);
		}
		if(ADC_val.interpol != NO_IN){
			if(ADC_val.interpol == LIN_IN){

			}
			else if(ADC_val.interpol == H_IN){

			}
			/*
			 * тут,нама, нихуято ни сделана пака насяника
			 *
			 *
			 *
			 *
			 * */
		}
	}
}

void phase_shifter(ADC_valueTypeDef ADC_val, uint32_t* values_table){
	if (ADC_val.state == 0){
		break;
	}
	else{
		if (ADC_val.value == 0){

		}
	}
}
