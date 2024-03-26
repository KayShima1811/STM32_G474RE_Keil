 /**
  *************************************************************
  *  	@file: 			stm32g4_configlib.h
  *		@author: 		Shenny
  * 	@brief:			Optionally include additional libraries into the program
  *  	Created on: 	Mar 26, 2024
  *************************************************************
 */

#ifndef STM32G4_CONFIGLIB_H
#define STM32G4_CONFIGLIB_H

/* ########################## Module Selection ############################## */
/**
  * @brief This is the list of modules to be used in the HAL driver
  */
#define RCC_MODULE_ENABLED
#define GPIO_MODULE_ENABLED
//#define EXTI_MODULE_ENABLED
#define FLASH_MODULE_ENABLED
#define PWR_MODULE_ENABLED
#define TIMER_MODULE_ENABLED
#define DELAY_MODULE_ENABLED


/* Includes ------------------------------------------------------------------*/
/**
  * @brief Include module's header file
  */
#ifdef RCC_MODULE_ENABLED
#include "stm32g4_rcc.h"
#endif /* RCC_MODULE_ENABLED */

#ifdef GPIO_MODULE_ENABLED
#include "stm32g4_gpio.h"
#endif /* GPIO_MODULE_ENABLED */

#ifdef EXTI_MODULE_ENABLED
#include "stm32g4_exti.h"
#endif /* EXTI_MODULE_ENABLED */

#ifdef FLASH_MODULE_ENABLED
#include "stm32g4_flash.h"
#endif /* FLASH_MODULE_ENABLED */

#ifdef PWR_MODULE_ENABLED
#include "stm32g4_pwr.h"
#endif /* PWR_MODULE_ENABLED */

#ifdef TIMER_MODULE_ENABLED
#include "stm32g4_timer.h"
#endif /* TIMER_MODULE_ENABLED */

#endif /* STM32G4_CONFIGLIB_H */
