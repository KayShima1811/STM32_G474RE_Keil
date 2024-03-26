/**
  *************************************************************
  *  	@file: 			stm32g4_gpio.h
  *		@author: 		Shenny
  * 	@brief:			Defines the GPIO library header file
  *  	Created on: 	Mar 26, 2024
  *************************************************************
 */

#ifndef STM32G4_GPIO_H
#define STM32G4_GPIO_H

#include "main.h"

typedef struct
{
	GPIO_TypeDef* Port;
    v_uint32_t Pin;
    v_uint32_t Mode;       
    v_uint32_t Pull;       
    v_uint32_t Speed;      
    v_uint32_t Alternate;  
} GPIO_InitTypeDef;

#define PIN_0								0U
#define PIN_1								1U
#define PIN_2								2U
#define PIN_3								3U
#define PIN_4								4U
#define PIN_5								5U
#define PIN_6								6U
#define PIN_7								7U
#define PIN_8								8U
#define PIN_9								10U
#define PIN_10								10U
#define PIN_11								11U
#define PIN_12								12U
#define PIN_13								13U
#define PIN_14								14U
#define PIN_15								15U

#define PORTx_Mask							(0x00001C00U)
#define GPIOx_EN							(0x00000001U)
#define GPIO_MODER_MASK						(0x00000003U)
#define GPIO_PUPDR_MASK						(0x00000003U)
#define GPIO_OSPEEDR_MASK					(0x00000003U)
#define GPIO_OTYPER_MASK					(0x00000001U)
#define GPIO_AFR_MASK						(0x0000000FU)

#define GPIO_MODER_INPUT					(0x00000000U)
#define GPIO_MODER_OUTPUT					(0x00000001U)
#define GPIO_MODER_AFMODE					(0x00000002U)
#define GPIO_MODER_ADCMODE					(0x00000003U)
			
#define GPIO_SPEED_FREQ_LOW        			(0x00000000U)   /*!< range up to 5 MHz */
#define GPIO_SPEED_FREQ_MEDIUM     			(0x00000001U)   /*!< range  5 MHz to 25 MHz */
#define GPIO_SPEED_FREQ_HIGH       			(0x00000002U)   /*!< range 25 MHz to 50 MHz */
#define GPIO_SPEED_FREQ_VERY_HIGH  			(0x00000003U)   /*!< range 50 MHz to 120 MHz */
					
#define GPIO_NOPULL        					(0x00000000U)   
#define GPIO_PULLUP        					(0x00000001U)   
#define GPIO_PULLDOWN      					(0x00000002U)   

/** @group Initialization function */
void ENABLE_CLOCK_PORT(GPIO_TypeDef* PORT_GPIO);
int Check_pin_afmode(uint32_t gpio);
void GPIO_Setup(GPIO_InitTypeDef *GPIOx);
void GPIO_Init(void);


/** @group IO operation functions */
void GPIO_Toggle(GPIO_TypeDef* GPIOx,uint32_t Pin);

#endif /* STM32G4_GPIO_H */
