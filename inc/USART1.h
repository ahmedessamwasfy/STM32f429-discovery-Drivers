

/*******************************************************************************
 * @file    USART1.h
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @website 
 * @date    Sep 16, 2019
 *
 * @brief   USART1.h example using ST virtual COM port (VCP)
 * @note
 *
@verbatim
Copyright (C) Ahnmed Wasfy 2019

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.
@endverbatim
*******************************************************************************/

/* Define to prevent recursive inclusion */

#ifndef INC_USART1_H_
#define INC_USART1_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif



/* @prog __ApplicationName ****************************************************
**
** __ShortDescription__
**
******************************************************************************/
	





/* Includes */

#include"Std_Types.h"
#include"myGPIO.h"

#include"USART1_Reg.h"
#include"USART1_PRIV.h"
#include"USART1_Cfg.h"




/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup USART1.h
 * @{
 */

/**
 * @defgroup USART1.h_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1.h_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1.h_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1.h_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1.h_exported_functions
 * @{
 */



/**
 * @brief   Configure USART1 for ST virtual COM port (VCP)
 * @note
 * @param   None
 * @retval  None
 */
void USART1_Init(void);

/**
 * @brief   Enable USART1 transmitter and receiver
 * @note
 * @param   None
 * @retval  None
 */
void USART1_Enable(void);


/**
 * @brief   USART1 transmit and receive data
 * @note
 * @param   None
 * @retval  None
 */
void USART1_Process(void);




void USART_Send_char(u8 data);
/**
 * @brief   String receive
 * @note
 * @param   None
 * @retval  None
 */
uint32 USART_Receive(void);



void USART_transmit_complete_checker(void);
uint32 USART_error_checker(void);
void USART_DATA_REG_checker(void);



void USART_Send_sring(u8 * data);

/* @}
 */
/**
 * @}
 */
/**
 * @}
 */

#endif /* INC_USART1_H_ */
