/**
  *************************************************************
  *  	@file: 			stm32g4_timer.c
  *		@author: 		Shenny
  * 	@brief:			Timer module driver
  *  	Created on: 	Mar 26, 2024
  *************************************************************
 */
#include "stm32g4_timer.h"

void ENABLE_CLOCK_TIM2_7(TIM_TypeDef* TIMx)
{
	uint32_t timer_pos = READ_BIT((uint32_t)TIMx,TIMx_Mask) >> 10;
	SET_BIT(RCC->APB1ENR1,TIMx_EN << timer_pos);
}

void TIMx_Setup(TIM_InitTypedef* TIMx)
{
	/** @brief 		Enable clock for TIMx */
	ENABLE_CLOCK_TIM2_7(TIMx->Instance);
	
	/** @brief 		Set the value for the Prescaler Register */
	SET_BIT(TIMx->Instance->PSC, TIMx->Prescaler);
	
	/** @brief 		Set the value for the Auto_reload Register */
	MODIFY_REG(TIMx->Instance->ARR,TIM_ARR_MASK, TIMx->Period);
	
	/** @brief 		Set the value for the clock divider, 
					turn on ARPR, select up/down counting mode 
	*/
	SET_BIT(TIMx->Instance->CR1, TIMx->ClockDivision | TIMx->AutoReloadPreload | TIMx->CounterMode);
	
	/** @brief 		Enable Counter */
	SET_BIT(TIMx->Instance->CR1, TIM_CR1_CEN);	
	
	/** @brief 		Enable bit UG
	  * @note 		The new prescaler rate is taken into account at the next 
	  *				update event. So it is necessary to turn on the UG bit to 
	  *				generate an overflow event and reset the timer and load 
	  * 			the new prescaler value.
	*/
	SET_BIT(TIMx->Instance->EGR, TIM_EGR_UG);
}


void TIMx_Init(void)
{
	TIM_InitTypedef TIMx_Config = {
		.Instance = TIM6,
		.Prescaler = 170-1,
		.Period = 0xffffffff,
		.AutoReloadPreload = TIM_CR1_ARPE_ENABLE,
	};
	TIMx_Setup(&TIMx_Config);
}

