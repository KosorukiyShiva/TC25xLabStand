/*
 * AS5600.h
 *
 *  Created on: Apr 27, 2026
 *      Author: Shiva_thinik
 */

#ifndef INC_AS5600_H_
#define INC_AS5600_H_

#include <stdint.h>
#include "stm32g4xx_hal.h"
#include "stm32g431xx.h"

#define AS5600_ADDR_INIT 							0x36


//CONFIG REG

#define AS5600_CRG_ZMCO 							0X00
#define AS5600_CRG_ZPOS_11_8						0X01
#define AS5600_CRG_ZPOS_7_0							0X02
#define AS5600_CRG_MPOS_11_8						0X03
#define AS5600_CRG_MPOS_7_0							0X04
#define AS5600_CRG_MANG_11_8 						0X05
#define AS5600_CRG_MANG_7_0							0X06
#define AS5600_CRG_CONF_WD_FTH_SF					0X07
#define AS5600_CRG_CONF_PWMF_OUTS_HYST_PM			0X08


//OUTPUT REG

#define AS5600_0RG_RAW_ANGLE_11_8 					0X0C
#define AS5600_0RG_RAW_ANGLE_7_0					0X0D
#define AS5600_0RG_ANGLE_11_8						0X0E
#define AS5600_0RG_ANGLE_7_0						0X0F


//STATUS REG

#define AS5600_SRG_STATUS							0X0B
#define AS5600_SRG_AGC								0X1A
#define AS5600_SRG_MAGNITUDE_11_8					0X1B
#define AS5600_SRG_MAGNITUDE_7_0					0X1C

//BURN COMMAND

#define AS5600_BRG_BURN								0XFF
#define AS5600_BCMD_BURN_ANGLE						0X80
#define AS5600_BCMD_BURN_SETTINGS					0X40

typedef struct{
	I2C_HandleTypeDef *i2cHandle;
	uint8_t i2cAddr;
	GPIO_TypeDef *DirPin;
	uint16_t DirPin;
	uint8_t PosiRotatDir;
	uint8_t PowerMode;
	uint8_t Hysteresis
};
#endif /* INC_AS5600_H_ */
