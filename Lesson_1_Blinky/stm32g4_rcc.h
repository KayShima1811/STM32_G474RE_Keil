/**
  *************************************************************
  *  	@file: 			stm32g4_rcc.h
  *		@author: 		Shenny
  * 	@brief:			Defines the RCC library header file
  *  	Created on: 	Mar 26, 2024
  *************************************************************
 */


#ifndef STM32G4_RCC_H
#define STM32G4_RCC_H

#include "main.h"

enum RCC_OSC {
    RCC_HSI48,
    RCC_PLL,
    RCC_HSE,
    RCC_HSI16,
    RCC_LSE,
    RCC_LSI
};

enum RCC_CLK {
    RCC_CLOCK_24MHZ,
    RCC_CLOCK_48MHZ,
    RCC_CLOCK_96MHZ,
	RCC_CLOCK_100MHZ,
    RCC_CLOCK_170MHZ,
    RCC_CLOCK_END
};


struct RCC_OscInit
{      
    v_uint32_t HSEState;
    v_uint32_t PLLSource;
    v_uint32_t PLLM;       
    v_uint32_t PLLN;       
    v_uint32_t PLLP;       
    v_uint32_t PLLQ;       
    v_uint32_t PLLR;
    v_uint32_t HPRE;
    v_uint32_t PPRE1;
    v_uint32_t PPRE2;
    v_uint32_t VOS_SCALE;
    v_uint32_t BOOST;
    v_uint32_t FLASH_CONFIG;
    v_uint32_t FLASH_WAIT;
    v_uint32_t AHBCLKDivider;
    v_uint32_t APB1CLKDivider;
    v_uint32_t APB2CLKDivider;        
};

#define RCC_HSE_ON                     RCC_CR_HSEON                               /*!< HSE clock activation */

#define RCC_PLLM_DIV1                  0x00000001U             /*!< PLLM division factor = 1  */
#define RCC_PLLM_DIV2                  0x00000002U             /*!< PLLM division factor = 2  */
#define RCC_PLLM_DIV3                  0x00000003U             /*!< PLLM division factor = 3  */
#define RCC_PLLM_DIV4                  0x00000004U             /*!< PLLM division factor = 4  */
#define RCC_PLLM_DIV5                  0x00000005U             /*!< PLLM division factor = 5  */
#define RCC_PLLM_DIV6                  0x00000006U             /*!< PLLM division factor = 6  */
#define RCC_PLLM_DIV7                  0x00000007U             /*!< PLLM division factor = 7  */
#define RCC_PLLM_DIV8                  0x00000008U             /*!< PLLM division factor = 8  */
#define RCC_PLLM_DIV9                  0x00000009U             /*!< PLLM division factor = 9  */
#define RCC_PLLM_DIV10                 0x0000000AU             /*!< PLLM division factor = 10 */
#define RCC_PLLM_DIV11                 0x0000000BU             /*!< PLLM division factor = 11 */
#define RCC_PLLM_DIV12                 0x0000000CU             /*!< PLLM division factor = 12 */
#define RCC_PLLM_DIV13                 0x0000000DU             /*!< PLLM division factor = 13 */
#define RCC_PLLM_DIV14                 0x0000000EU             /*!< PLLM division factor = 14 */
#define RCC_PLLM_DIV15                 0x0000000FU             /*!< PLLM division factor = 15 */
#define RCC_PLLM_DIV16                 0x00000010U             /*!< PLLM division factor = 16 */

#define RCC_PLLP_DIV2                  0x00000002U             /*!< PLLP division factor = 2  */
#define RCC_PLLP_DIV3                  0x00000003U             /*!< PLLP division factor = 3  */
#define RCC_PLLP_DIV4                  0x00000004U             /*!< PLLP division factor = 4  */
#define RCC_PLLP_DIV5                  0x00000005U             /*!< PLLP division factor = 5  */
#define RCC_PLLP_DIV6                  0x00000006U             /*!< PLLP division factor = 6  */
#define RCC_PLLP_DIV7                  0x00000007U             /*!< PLLP division factor = 7  */
#define RCC_PLLP_DIV8                  0x00000008U             /*!< PLLP division factor = 8  */
#define RCC_PLLP_DIV9                  0x00000009U             /*!< PLLP division factor = 9  */
#define RCC_PLLP_DIV10                 0x0000000AU             /*!< PLLP division factor = 10 */
#define RCC_PLLP_DIV11                 0x0000000BU             /*!< PLLP division factor = 11 */
#define RCC_PLLP_DIV12                 0x0000000CU             /*!< PLLP division factor = 12 */
#define RCC_PLLP_DIV13                 0x0000000DU             /*!< PLLP division factor = 13 */
#define RCC_PLLP_DIV14                 0x0000000EU             /*!< PLLP division factor = 14 */
#define RCC_PLLP_DIV15                 0x0000000FU             /*!< PLLP division factor = 15 */
#define RCC_PLLP_DIV16                 0x00000010U             /*!< PLLP division factor = 16 */
#define RCC_PLLP_DIV17                 0x00000011U             /*!< PLLP division factor = 17 */
#define RCC_PLLP_DIV18                 0x00000012U             /*!< PLLP division factor = 18 */
#define RCC_PLLP_DIV19                 0x00000013U             /*!< PLLP division factor = 19 */
#define RCC_PLLP_DIV20                 0x00000014U             /*!< PLLP division factor = 20 */
#define RCC_PLLP_DIV21                 0x00000015U             /*!< PLLP division factor = 21 */
#define RCC_PLLP_DIV22                 0x00000016U             /*!< PLLP division factor = 22 */
#define RCC_PLLP_DIV23                 0x00000017U             /*!< PLLP division factor = 23 */
#define RCC_PLLP_DIV24                 0x00000018U             /*!< PLLP division factor = 24 */
#define RCC_PLLP_DIV25                 0x00000019U             /*!< PLLP division factor = 25 */
#define RCC_PLLP_DIV26                 0x0000001AU             /*!< PLLP division factor = 26 */
#define RCC_PLLP_DIV27                 0x0000001BU             /*!< PLLP division factor = 27 */
#define RCC_PLLP_DIV28                 0x0000001CU             /*!< PLLP division factor = 28 */
#define RCC_PLLP_DIV29                 0x0000001DU             /*!< PLLP division factor = 29 */
#define RCC_PLLP_DIV30                 0x0000001EU             /*!< PLLP division factor = 30 */
#define RCC_PLLP_DIV31                 0x0000001FU             /*!< PLLP division factor = 31 */

#define RCC_PLLQ_DIV2                  0x00000002U             /*!< PLLQ division factor = 2 */
#define RCC_PLLQ_DIV4                  0x00000004U             /*!< PLLQ division factor = 4 */
#define RCC_PLLQ_DIV6                  0x00000006U             /*!< PLLQ division factor = 6 */
#define RCC_PLLQ_DIV8                  0x00000008U             /*!< PLLQ division factor = 8 */

#define RCC_PLLR_DIV2                  0x00000002U             /*!< PLLR division factor = 2 */
#define RCC_PLLR_DIV4                  0x00000004U             /*!< PLLR division factor = 4 */
#define RCC_PLLR_DIV6                  0x00000006U             /*!< PLLR division factor = 6 */
#define RCC_PLLR_DIV8                  0x00000008U             /*!< PLLR division factor = 8 */

#define RCC_PLLSOURCE_HSE              RCC_PLLCFGR_PLLSRC_HSE  /*!< HSE clock selected as PLL entry clock source */

#define RCC_SYSCLK_DIV1                RCC_CFGR_HPRE_DIV1   /*!< SYSCLK not divided */
#define RCC_SYSCLK_DIV2                RCC_CFGR_HPRE_DIV2   /*!< SYSCLK divided by 2 */
#define RCC_SYSCLK_DIV4                RCC_CFGR_HPRE_DIV4   /*!< SYSCLK divided by 4 */
#define RCC_SYSCLK_DIV8                RCC_CFGR_HPRE_DIV8   /*!< SYSCLK divided by 8 */
#define RCC_SYSCLK_DIV16               RCC_CFGR_HPRE_DIV16  /*!< SYSCLK divided by 16 */
#define RCC_SYSCLK_DIV64               RCC_CFGR_HPRE_DIV64  /*!< SYSCLK divided by 64 */
#define RCC_SYSCLK_DIV128              RCC_CFGR_HPRE_DIV128 /*!< SYSCLK divided by 128 */
#define RCC_SYSCLK_DIV256              RCC_CFGR_HPRE_DIV256 /*!< SYSCLK divided by 256 */
#define RCC_SYSCLK_DIV512              RCC_CFGR_HPRE_DIV512 /*!< SYSCLK divided by 512 */

#define RCC_HCLK_DIV1                  RCC_CFGR_PPRE1_DIV1  /*!< HCLK not divided */
#define RCC_HCLK_DIV2                  RCC_CFGR_PPRE1_DIV2  /*!< HCLK divided by 2 */
#define RCC_HCLK_DIV4                  RCC_CFGR_PPRE1_DIV4  /*!< HCLK divided by 4 */
#define RCC_HCLK_DIV8                  RCC_CFGR_PPRE1_DIV8  /*!< HCLK divided by 8 */
#define RCC_HCLK_DIV16                 RCC_CFGR_PPRE1_DIV16 /*!< HCLK divided by 16 */

/*  32     28      20       16      0
    --------------------------------
    | MCO   | GPIO  | GPIO  | GPIO  |
    | Index |  AF   | Port  |  Pin  |
    -------------------------------*/
#define RCC_MCO_GPIOPORT_POS           16U
#define RCC_MCO_GPIOPORT_MASK          (0xFUL << RCC_MCO_GPIOPORT_POS)
#define RCC_MCO_GPIOAF_POS             20U
#define RCC_MCO_GPIOAF_MASK            (0xFFUL << RCC_MCO_GPIOAF_POS)
#define RCC_MCO_INDEX_POS              28U
#define RCC_MCO_INDEX_MASK             (0x1UL << RCC_MCO_INDEX_POS)
#define RCC_MCO1_INDEX                 (0x0UL << RCC_MCO_INDEX_POS)             /*!< MCO1 index */
#define RCC_MCO_PA8                    (RCC_MCO1_INDEX | (GPIO_AF0_MCO << RCC_MCO_GPIOAF_POS) | (GPIO_GET_INDEX(GPIOA) << RCC_MCO_GPIOPORT_POS) | GPIO_PIN_8)
#define RCC_MCO_PG10                   (RCC_MCO1_INDEX | (GPIO_AF0_MCO << RCC_MCO_GPIOAF_POS) | (GPIO_GET_INDEX(GPIOG) << RCC_MCO_GPIOPORT_POS) | GPIO_PIN_10)
/* Legacy Defines*/
#define RCC_MCO1                       RCC_MCO_PA8
#define RCC_MCO                        RCC_MCO1               /*!< MCO1 to be compliant with other families with 2 MCOs*/

#define RCC_MCO1SOURCE_NOCLOCK         0x00000000U                            /*!< MCO1 output disabled, no clock on MCO1 */
#define RCC_MCO1SOURCE_SYSCLK          RCC_CFGR_MCOSEL_0                      /*!< SYSCLK selection as MCO1 source */
#define RCC_MCO1SOURCE_HSI             (RCC_CFGR_MCOSEL_0| RCC_CFGR_MCOSEL_1) /*!< HSI selection as MCO1 source */
#define RCC_MCO1SOURCE_HSE             RCC_CFGR_MCOSEL_2                      /*!< HSE selection as MCO1 source */
#define RCC_MCO1SOURCE_PLLCLK          (RCC_CFGR_MCOSEL_0|RCC_CFGR_MCOSEL_2)  /*!< PLLCLK selection as MCO1 source */
#define RCC_MCO1SOURCE_LSI             (RCC_CFGR_MCOSEL_1|RCC_CFGR_MCOSEL_2)  /*!< LSI selection as MCO1 source */
#define RCC_MCO1SOURCE_LSE             (RCC_CFGR_MCOSEL_0|RCC_CFGR_MCOSEL_1|RCC_CFGR_MCOSEL_2) /*!< LSE selection as MCO1 source */
#define RCC_MCO1SOURCE_HSI48           RCC_CFGR_MCOSEL_3                      /*!< HSI48 selection as MCO1 source */

#define RCC_MCODIV_1                   RCC_CFGR_MCOPRE_DIV1     /*!< MCO not divided  */
#define RCC_MCODIV_2                   RCC_CFGR_MCOPRE_DIV2     /*!< MCO divided by 2 */
#define RCC_MCODIV_4                   RCC_CFGR_MCOPRE_DIV4     /*!< MCO divided by 4 */
#define RCC_MCODIV_8                   RCC_CFGR_MCOPRE_DIV8     /*!< MCO divided by 8 */
#define RCC_MCODIV_16                  RCC_CFGR_MCOPRE_DIV16    /*!< MCO divided by 16 */

#define RCC_FLAG_HSERDY                ((CR_REG_INDEX << 5U) | RCC_CR_HSERDY_Pos) /*!< HSE Ready flag */
#define RCC_FLAG_PLLRDY                ((CR_REG_INDEX << 5U) | RCC_CR_PLLRDY_Pos) /*!< PLL Ready flag */


/** @group Macro function */
#define RCC_PLL_CONFIG(__PLLSOURCE__, __PLLM__, __PLLN__, __PLLP__, __PLLQ__,__PLLR__ )     \
                            MODIFY_REG(RCC->PLLCFGR,                                        \
                            (RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN |     \
                            RCC_PLLCFGR_PLLQ | RCC_PLLCFGR_PLLR | RCC_PLLCFGR_PLLPDIV),     \
                            ((__PLLSOURCE__) |                                              \
                            (((__PLLM__) - 1U) << RCC_PLLCFGR_PLLM_Pos) |                   \
                            ((__PLLN__) << RCC_PLLCFGR_PLLN_Pos) |                          \
                            ((((__PLLQ__) >> 1U) - 1U) << RCC_PLLCFGR_PLLQ_Pos) |           \
                            ((((__PLLR__) >> 1U) - 1U) << RCC_PLLCFGR_PLLR_Pos) |           \
                            ((__PLLP__) << RCC_PLLCFGR_PLLPDIV_Pos)))


/** @group Default initialization clock */
extern const struct RCC_OscInit RCC_Osc_HSE_Init[RCC_CLOCK_END];


/** @group Initialization function */
void SystemClockInit(const struct RCC_OscInit* Mhz);

#endif /* STM32G4_RCC_H */
