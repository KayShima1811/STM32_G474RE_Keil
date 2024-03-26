/**
  *************************************************************
  *  	@file: 			stm32g4_gpio.c
  *		@author: 		Shenny
  * 	@brief:			GPIO module driver
  *  	Created on: 	Mar 26, 2024
  *************************************************************
 */

#include "stm32g4_gpio.h"

void ENABLE_CLOCK_PORT(GPIO_TypeDef* PORT_GPIO)
{
	uint32_t gpio_pos = (READ_BIT((uint32_t)PORT_GPIO, PORTx_Mask) >> 10);
	SET_BIT(RCC->AHB2ENR,GPIOx_EN << gpio_pos);
}

int Check_pin_afmode(uint32_t gpio)
{
	if(gpio <= 7) {
		return true;
	}
	else {
		return false;
	}
}

void GPIO_Setup(GPIO_InitTypeDef *GPIOx)
{
	uint32_t positon = GPIOx->Pin * 2;
	bool pin_afmode = Check_pin_afmode(GPIOx->Pin);
	
	/** @brief 		Enable clock for Port x */
	ENABLE_CLOCK_PORT(GPIOx->Port);
	
	/** @brief 		Choose GPIO pin mode */
	switch (GPIOx->Mode) {
		case GPIO_MODER_INPUT:
			MODIFY_REG(GPIOx->Port->MODER, GPIO_MODER_MASK << positon, GPIO_MODER_INPUT << positon);
			break;
		case GPIO_MODER_OUTPUT:
			MODIFY_REG(GPIOx->Port->MODER, GPIO_MODER_MASK << positon, GPIO_MODER_OUTPUT << positon);
			break;
		case GPIO_MODER_AFMODE:
			MODIFY_REG(GPIOx->Port->MODER, GPIO_MODER_MASK << positon, GPIO_MODER_AFMODE << positon);
			if(pin_afmode) {
				MODIFY_REG(GPIOx->Port->AFR[0], GPIO_AFR_MASK, GPIOx->Alternate << (positon*2));
			}
			else {
				MODIFY_REG(GPIOx->Port->AFR[1], GPIO_AFR_MASK, GPIOx->Alternate << (positon*2));
			}
			break;
		default:
			break;
	}
	/** @brief 		Configure pull up/down and output speed  */
	MODIFY_REG(GPIOx->Port->PUPDR, GPIO_PUPDR_MASK << positon, GPIOx->Pull << positon);
	MODIFY_REG(GPIOx->Port->OSPEEDR, GPIO_OSPEEDR_MASK << positon, GPIO_SPEED_FREQ_VERY_HIGH << positon);
}

void GPIO_Init(void)
{
	/** @brief 		Configure PA5 output */
	GPIO_InitTypeDef GPIO_Config = {
		.Port = GPIOA,
		.Pin = PIN_5,
		.Mode = GPIO_MODER_OUTPUT,
		.Pull = GPIO_NOPULL,
		.Speed = GPIO_SPEED_FREQ_VERY_HIGH,
	};
	GPIO_Setup(&GPIO_Config);
}

void GPIO_Toggle(GPIO_TypeDef* GPIOx,uint32_t Pin)
{
	TOGGLE_BIT(GPIOx->ODR,0x1U << Pin);
}
