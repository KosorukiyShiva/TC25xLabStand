#include <driver.h>
/*
 * driver.c
 *
 *  Created on: Mar 20, 2026
 *      Author: Shiva_thinik
 */
uint16_t SIZE  = 0; // size for pwm_dma_start length

 uint8_t map [] = {0,  129,  64,  32,  16,  48, 8, 72, 40, 104, 24, 88, 56, 120, 4, 68, 36, 100, 20, 84, 52, 116, 12, 76, 44, 108, 28, 92, 60, 124, 2, 66, 34, 98, 18, 82, 50, 114, 10, 74, 42, 106, 26,
		 90, 58, 122, 6, 70, 38, 102, 22, 86, 54, 118, 14, 78, 46, 110, 30, 94, 62, 126, 1, 65, 33, 97, 17, 81, 49, 113, 9, 73, 41, 105, 25, 89, 57, 121, 5, 69, 37, 101, 21, 85, 53, 117, 13, 77, 45, 109,
		 29, 93, 61, 125, 3, 67, 35, 99, 19, 83, 51, 115, 11, 75, 43, 107, 27, 91, 59, 123, 7, 71, 39, 103, 23, 87, 55, 119, 15, 79, 47, 111, 31, 95, 63, 127, 128, 96, 80, 112};

 uint32_t signal[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 11, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
		 35, 36, 37, 38, 39, 40, 42, 43, 44, 45, 46, 48, 49, 50, 51, 52, 54, 55, 56, 57, 58, 60, 61, 62, 63, 64, 65, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 86, 87,
		 88, 89, 90, 90, 91, 92, 92, 93, 93, 94, 95, 95, 96, 96, 96, 97, 97, 98, 98, 98, 98, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 98, 98, 98, 98, 97, 97, 96, 96, 96, 95, 95, 94,
		 94, 93, 92, 92, 91, 90, 90, 89, 88, 87, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 64, 63, 62, 61, 60, 59, 57, 56, 55, 54, 53, 51, 50, 49, 48, 47, 45,
		 44, 43, 42, 41, 39, 38, 37, 36, 35, 34, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 13, 12, 11, 10, 9, 9, 8, 7, 7, 6, 6, 5, 4, 4, 3, 3, 3, 2, 2, 1, 1, 1, 1, 0,
		 0, 0, 0, 0, 0, 0, 0};


// uint16_t SIZE  = 0; // size for pwm_dma_start length
 uint16_t SIGNAL_SIZE = sizeof(signal)/sizeof(signal[0]);
 uint16_t MAP_SIZE = sizeof(map)/sizeof(map[0]);

// uint8_t PWM_ch1[260]={0};
 uint32_t PWM_ch2[260]={0};
 uint32_t PWM_ch3[260]={0};

duty_subrange st_sbr = OFF;
uint8_t sort_signal( uint32_t* signal, uint8_t* map, uint8_t duty, uint32_t* PWM_ch1){
  /*
  0. OK						  error code: 0
  1. range of duty = 0-128    error code: 1
  2. end of func			  error code: 98
  3. default                  error code: 99

	  */

	 uint8_t swap_val1 = 0;
	 uint8_t swap_valp = 0;
	 if(duty > 128){
		 st_sbr = OFF;
		 SIZE = 0;
		 return 1;
	 }
	 if(duty == 0){
		 st_sbr = OFF;
	 }
//	 else if (duty != 0 && duty <=40) {
//		st_sbr = SMLL_FRC;
//	}
//	 else if(duty > 40 && duty <= 100){
//		 st_sbr = BG_FRC;
//	 }
	 else if (duty > 0 && duty <= 256) {
		st_sbr = ON;
	}

	 PWM_ch1[0] = signal[map[0]];
	 switch (st_sbr) {
		case OFF:
			SIZE = 0;
			break;
		case ON:
			SIZE = SIGNAL_SIZE - duty*2;
			for (int i = 0 ; i < SIZE/2; i++ ){
				if(i == 0){
					PWM_ch1[0] = signal[0];
					swap_val1 = map[1];
					continue;
				}
				for(int k = 0; k < SIZE/2; k++){
					if(map[k] > swap_valp && map[k] < swap_val1){
						swap_val1 = map[k];
					}
				}
        PWM_ch1[i] = (uint32_t)signal[swap_val1] ;
        swap_valp = swap_val1 ;
        swap_val1 = map[1];
			}
//      for (int i = 0; i < SIZE/2; i++ ){
//        PWM_ch1[i] = (uint32_t) signal[PWM_ch1[i]];
//      }
      return 0;
			break;
		default:
			return 99;
			break;
	}
	 return 98;
 }

uint8_t mirror_signal(uint16_t SIZE, uint32_t* PWM_ch1){
  for(int i = 0; i < SIZE/2; i++){
    PWM_ch1[i+SIZE/2] = PWM_ch1[SIZE/2 -(1 + i)];
  }
//  for(int i = 0; i + SIZE < 260; i++){
//	  PWM_ch1[SIZE + i] = 0;
//  }
  return 0;
 }

uint8_t shift_channels(uint32_t* PWM_ch1, uint32_t* PWM_ch2, uint32_t* PWM_ch3, uint16_t SIZE){
  uint8_t thSIZE = SIZE/3;
  uint8_t tthSIZE = (2*SIZE)/3;
  for(uint8_t i = 0; i < SIZE; i++){
    if(thSIZE + i < SIZE){
      PWM_ch2[i] = PWM_ch1[thSIZE+i];
    }
    else if(thSIZE + i >= SIZE){
      PWM_ch2[i] = PWM_ch1[(thSIZE+i) - SIZE];
    }

    if(tthSIZE + i < SIZE){
      PWM_ch3[i] = PWM_ch1[tthSIZE+i];
    }
    else if(tthSIZE + i >= SIZE){
      PWM_ch3[i] = PWM_ch1[(tthSIZE+i) - SIZE];
    }
  }
  for(int i = 0; i + SIZE < 260; i++){
  	  PWM_ch2[SIZE + i] = 0;
  	  PWM_ch3[SIZE + i] = 0;
    }
  return 0;
 }

//void clear_chanels(uint8_t* PWM_ch1, uint8_t* PWM_ch2, uint8_t* PWM_ch3){
//	for (uint8_t i = 0; i < 260; i++) {
//		PWM_ch1[i] = 0;
//		PWM_ch2[i] = 0;
//		PWM_ch3[i] = 0;
//	}
//}
