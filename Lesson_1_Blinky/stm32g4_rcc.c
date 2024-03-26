/**
  *************************************************************
  *  	@file: 			stm32g4_rcc.c
  *		@author: 		Shenny
  * 	@brief:			RCC module driver
  *  	Created on: 	Mar 26, 2024
  *************************************************************
 */

#include "stm32g4_rcc.h"

const struct RCC_OscInit RCC_Osc_HSE_Init[RCC_CLOCK_END] = {
	{/* 24MHz */
        .HSEState = RCC_HSE_ON,
        .PLLSource = RCC_PLLSOURCE_HSE,
        .PLLM = RCC_PLLM_DIV2,
        .PLLN = 8,
        .PLLP = RCC_PLLP_DIV2,
        .PLLQ = RCC_PLLQ_DIV2,
        .PLLR = RCC_PLLR_DIV2,
        .HPRE = RCC_SYSCLK_DIV2,
        .PPRE1 = RCC_HCLK_DIV1,
        .PPRE2 = RCC_HCLK_DIV1,
        .VOS_SCALE = PWR_CR1_VOS_RANGE_1,
        .BOOST = false,
        .FLASH_CONFIG = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN,
        .FLASH_WAIT = FLASH_LATENCY_4,
    },
	{/* 48MHz */
        .HSEState = RCC_HSE_ON,
        .PLLSource = RCC_PLLSOURCE_HSE,
        .PLLM = RCC_PLLM_DIV2,
        .PLLN = 8,
        .PLLP = RCC_PLLP_DIV2,
        .PLLQ = RCC_PLLQ_DIV2,
        .PLLR = RCC_PLLR_DIV2,
        .HPRE = RCC_SYSCLK_DIV1,
        .PPRE1 = RCC_HCLK_DIV1,
        .PPRE2 = RCC_HCLK_DIV1,
        .VOS_SCALE = PWR_CR1_VOS_RANGE_1,
        .BOOST = false,
        .FLASH_CONFIG = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN,
        .FLASH_WAIT = FLASH_LATENCY_4,
    },
	{/* 96MHz */
        .HSEState = RCC_HSE_ON,
        .PLLSource = RCC_PLLSOURCE_HSE,
        .PLLM = RCC_PLLM_DIV2,
        .PLLN = 16,
        .PLLP = RCC_PLLP_DIV2,
        .PLLQ = RCC_PLLQ_DIV2,
        .PLLR = RCC_PLLR_DIV2,
        .HPRE = RCC_SYSCLK_DIV1,
        .PPRE1 = RCC_HCLK_DIV1,
        .PPRE2 = RCC_HCLK_DIV1,
        .VOS_SCALE = PWR_CR1_VOS_RANGE_1,
        .BOOST = false,
        .FLASH_CONFIG = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN,
        .FLASH_WAIT = FLASH_LATENCY_4,
    },
	{/* 100MHz */
        .HSEState = RCC_HSE_ON,
        .PLLSource = RCC_PLLSOURCE_HSE,
        .PLLM = RCC_PLLM_DIV3,
        .PLLN = 25,
        .PLLP = RCC_PLLP_DIV2,
        .PLLQ = RCC_PLLQ_DIV2,
        .PLLR = RCC_PLLR_DIV2,
        .HPRE = RCC_SYSCLK_DIV1,
        .PPRE1 = RCC_HCLK_DIV1,
        .PPRE2 = RCC_HCLK_DIV1,
        .VOS_SCALE = PWR_CR1_VOS_RANGE_1,
        .BOOST = false,
        .FLASH_CONFIG = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN,
        .FLASH_WAIT = FLASH_LATENCY_3,
    },
    {/* 170MHz */
        .HSEState = RCC_HSE_ON,
        .PLLSource = RCC_PLLSOURCE_HSE,
        .PLLM = RCC_PLLM_DIV6,
        .PLLN = 85,
        .PLLP = RCC_PLLP_DIV2,
        .PLLQ = RCC_PLLQ_DIV2,
        .PLLR = RCC_PLLR_DIV2,
        .HPRE = RCC_SYSCLK_DIV1,
        .PPRE1 = RCC_HCLK_DIV1,
        .PPRE2 = RCC_HCLK_DIV1,
        .VOS_SCALE = PWR_CR1_VOS_RANGE_1,
        .BOOST = true,
        .FLASH_CONFIG = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN,
        .FLASH_WAIT = FLASH_LATENCY_4,
    },
};

void SystemClockInit(const struct RCC_OscInit* Mhz)
{
    /** @brief 		Enable HSE and wait HSE ready */
    if(Mhz->HSEState == RCC_HSE_ON) {
		SET_BIT(RCC->CR, RCC_HSE_ON);
		while(!(READ_BIT(RCC->CR, RCC_CR_HSERDY)));
	} else {
        CLEAR_BIT(RCC->CR, RCC_HSE_ON);
    }

    /** @brief  	Enable and configure PWR
      * @note    	Bit R1MODE = 0 equivalent to boost mode
      *          	Bit R1MODE = 1 equivalent to normal mode
    */
    SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_PWREN);
    if(Mhz->VOS_SCALE == PWR_CR1_VOS_RANGE_1) {
        MODIFY_REG(PWR->CR1, PWR_CR1_VOS, PWR_CR1_VOS_RANGE_1);
    } else {
        MODIFY_REG(PWR->CR1, PWR_CR1_VOS, PWR_CR1_VOS_RANGE_2);
    }
    if(Mhz->BOOST == true) {
        CLEAR_BIT(PWR->CR5, PWR_CR5_R1MODE);
    } else {
        SET_BIT(PWR->CR5, PWR_CR5_R1MODE);
    }

    /** @brief   	Configure FLASH */
    MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, Mhz->FLASH_WAIT);
    SET_BIT(FLASH->ACR, Mhz->FLASH_CONFIG);

    /** @brief   	Enable and Configure PLL 
      * @warning 	It is mandatory to turn off the PLL oscillator before 
      *          	changing the configuration. 
    */
    CLEAR_BIT(RCC->CR, RCC_CR_PLLON);
    RCC_PLL_CONFIG(Mhz->PLLSource, Mhz->PLLM, Mhz->PLLN, Mhz->PLLP, Mhz->PLLQ, Mhz->PLLR);
	SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLREN);
    SET_BIT(RCC->CR, RCC_CR_PLLON);
    while(!(READ_BIT(RCC->CR, RCC_CR_PLLRDY)));

    /** @brief   	Configure  AHB(HPRE), APB1(PPRE1), APB2(PPRE2) */
    MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, RCC_CFGR_SW_PLL);
    while (!READ_BIT(RCC->CFGR, RCC_CFGR_SWS_PLL));
    MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, Mhz->HPRE);
	MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, Mhz->PPRE1);
	MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, Mhz->PPRE2);
}

