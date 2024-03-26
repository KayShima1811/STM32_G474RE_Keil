/**
  *************************************************************
  *  	@file: 			stm32g4_flash.h
  *		@author: 		Shenny
  * 	@brief:			Defines the Flash library header file
  *  	Created on: 	Mar 26, 2024
  *************************************************************
 */

#ifndef STM32G4_FLASH_H
#define STM32G4_FLASH_H

#include "main.h"

#define FLASH_LATENCY_0           FLASH_ACR_LATENCY_0WS    /*!< FLASH Zero wait state */
#define FLASH_LATENCY_1           FLASH_ACR_LATENCY_1WS    /*!< FLASH One wait state */
#define FLASH_LATENCY_2           FLASH_ACR_LATENCY_2WS    /*!< FLASH Two wait states */
#define FLASH_LATENCY_3           FLASH_ACR_LATENCY_3WS    /*!< FLASH Three wait states */
#define FLASH_LATENCY_4           FLASH_ACR_LATENCY_4WS    /*!< FLASH Four wait states */
#define FLASH_LATENCY_5           FLASH_ACR_LATENCY_5WS    /*!< FLASH Five wait state */
#define FLASH_LATENCY_6           FLASH_ACR_LATENCY_6WS    /*!< FLASH Six wait state */
#define FLASH_LATENCY_7           FLASH_ACR_LATENCY_7WS    /*!< FLASH Seven wait states */
#define FLASH_LATENCY_8           FLASH_ACR_LATENCY_8WS    /*!< FLASH Eight wait states */
#define FLASH_LATENCY_9           FLASH_ACR_LATENCY_9WS    /*!< FLASH Nine wait states */
#define FLASH_LATENCY_10          FLASH_ACR_LATENCY_10WS   /*!< FLASH Ten wait state */
#define FLASH_LATENCY_11          FLASH_ACR_LATENCY_11WS   /*!< FLASH Eleven wait state */
#define FLASH_LATENCY_12          FLASH_ACR_LATENCY_12WS   /*!< FLASH Twelve wait states */
#define FLASH_LATENCY_13          FLASH_ACR_LATENCY_13WS   /*!< FLASH Thirteen wait states */
#define FLASH_LATENCY_14          FLASH_ACR_LATENCY_14WS   /*!< FLASH Fourteen wait states */
#define FLASH_LATENCY_15          FLASH_ACR_LATENCY_15WS   /*!< FLASH Fifteen wait states */


#endif  /* STM32G4_FLASH_H */
