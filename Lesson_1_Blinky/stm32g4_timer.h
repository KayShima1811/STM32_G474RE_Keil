/**
  *************************************************************
  *  	@file: 			stm32g4_timer.h
  *		@author: 		Shenny
  * 	@brief:			Defines the TIM library header file
  *  	Created on: 	Mar 26, 2024
  *************************************************************
 */

#ifndef STM32G4_TIMER_H
#define STM32G4_TIMER_H

#include "main.h"

typedef struct
{
	TIM_TypeDef* Instance;
	v_uint32_t Prescaler;
	v_uint32_t CounterMode;
	v_uint32_t Period;
	v_uint32_t ClockDivision;
	v_uint32_t AutoReloadPreload;
}TIM_InitTypedef;

#define TIMx_Mask 	(0x00001C00U)
#define TIMx_EN		(0x00000001U)

#define TIMx_CR1_CKD_DIV0 	(0x00000000U)
#define TIMx_CR1_CKD_DIV2	TIM_CR1_CKD_0
#define TIMx_CR1_CKD_DIV4	TIM_CR1_CKD_1

#define TIM_CR1_DIR_UP 		(0x00000000U)		
#define TIM_CR1_DIR_DOWN 	(0x00000001U)

#define TIM_CR1_ARPE_ENABLE	TIM_CR1_ARPE

#define TIM_ARR_MASK (0xFFFFFFFFU)

/** @group Initialization function */
void ENABLE_CLOCK_TIM2_7(TIM_TypeDef* TIMx);
void TIMx_Setup(TIM_InitTypedef* TIMx);
void TIMx_Init(void);

#endif /* STM32G4_TIMER_H */

