 /**
  *************************************************************
  *  	@file: 			stm32g4_defvar.h
  *		@author: 		Shenny
  * 	@brief:			Define user variables
  *  	Created on: 	Mar 26, 2024
  *************************************************************
 */

#ifndef STM32G4_DEFVAR_H
#define STM32G4_DEFVAR_H

typedef const 		volatile	unsigned 		int				cv_uint32_t;
typedef const 		volatile	unsigned 		short			cv_uint16_t;
typedef const 		volatile	unsigned 		char			cv_uint8_t;

typedef const 		volatile			 		int				cv_int32_t;
typedef const 		volatile			 		short			cv_int16_t;
typedef const 		volatile			 		char			cv_int8_t;

typedef const 					unsigned 		int				c_uint32_t;
typedef const 					unsigned 		short			c_uint16_t;
typedef const 					unsigned 		char			c_uint8_t;

typedef const 							 		int				c_int32_t;
typedef const 							 		short			c_int16_t;
typedef const 							 		char			c_int8_t;

typedef 			volatile    unsigned    	int             v_uint32_t;
typedef 			volatile    unsigned    	short           v_uint16_t;
typedef 			volatile    unsigned    	char            v_uint8_t;

typedef 			volatile 		        	int             v_int32_t;
typedef 			volatile 		        	short           v_int16_t;
typedef 			volatile 					char            v_int8_t;

typedef enum
{
  OK       = 0x00U,
  ERROR    = 0x01U,
  BUSY     = 0x02U,
  TIMEOUT  = 0x03U
} StatusTypeDef;

#endif  /* STM32G4XX_DEFVAR_H */
