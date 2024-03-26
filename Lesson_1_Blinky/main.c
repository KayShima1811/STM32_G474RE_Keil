/**
  *  	@file: 			main.c
  *		@author: 		Shenny
  * 	@brief:			Main program
  *  	Created on: 	Mar 26, 2024
 */
#include "main.h"

int main(void)
{
	SystemClockInit(&RCC_Osc_HSE_Init[RCC_CLOCK_170MHZ]);
	GPIO_Init();
	TIMx_Init();
	for(;;)
	{
		GPIO_Toggle(GPIOA,PIN_5);
		Delay_ms(1000);
	}
}
