 /**
  *************************************************************
  *  	@file: 			main.h
  *		@author: 		Shenny
  * 	@brief:			Program library
  *  	Created on: 	Mar 26, 2024
  *************************************************************
 */

#ifndef LIB_MAIN_H_
#define LIB_MAIN_H_

/** @group 	Includes */
#include <stm32g474xx.h>
#include "stm32g4_defvar.h"
#include "stm32g4_configlib.h"
#include <stdbool.h>

/** @group 	User macros */
#define NULL 									((void *)0)
#define SET_BIT(REG, BIT)                       ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)                     ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)                      ((REG) & (BIT))
#define TOGGLE_BIT(REG, BIT)                    ((REG) ^= (BIT))
#define CLEAR_REG(REG)                          ((REG) = (0x0))
#define WRITE_REG(REG, VAL)                     ((REG) = (VAL))
#define READ_REG(REG)                           ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)     WRITE_REG((REG), (((READ_REG(REG))              \
                                                & (~(CLEARMASK))) | (SETMASK)))     

/** @group 	Declare user functions */
/* Delay function */
void Delay_us(uint32_t time);
void Delay_ms(uint32_t time);


#endif /* LIB_MAIN_H_ */
