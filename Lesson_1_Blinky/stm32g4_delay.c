/**
  *************************************************************
  *  	@file: 			stm32g4_delay.c
  *		@author: 		Shenny
  * 	@brief:			Delay module driver
  *  	Created on: 	Mar 26, 2024
  *************************************************************
 */

#include "stm32g4_timer.h"

void Delay_us(uint32_t time)
{
	WRITE_REG(TIM6->CNT,0x0U);
	while(TIM6->CNT < time){}
}

void Delay_ms(uint32_t time)
{
	for(uint32_t i = 0;i < time;i++)
	{
		Delay_us(1000);
	}
}
