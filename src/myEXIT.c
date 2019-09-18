/*******************************************************************************
 * @file    exti.c
 * @author  Ahmed Eldeep
 * @email   ahmed@almohandes.org
 * @website http://almohandes.org/stm32
 * @date    10.04.2018
 *
 * @brief   EXTI examples
 * @note
 *
@verbatim
Copyright (C) Almohandes.org, 2018

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

/* Includes */
#include "myEXIT.h"
#include "myGPIO.h"
/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup exti
 * @brief
 * @{
 */

/**
 * @defgroup exti_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_variables
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_exported_functions
 * @{
 */

/**
 * @brief   Push button EXTI initialization function
 * @note    On-board push button connected to PA0,
 *          so it can use only EXTI0
 * @param   None
 * @retval  None
 */
void EXTI_Init(GPIO_PORT port,u8 pin ,EXIT_EDGE edge ,EXIT_TYPE type )
{

	u8 pin_offset=(pin&&3)*4;

  /* Enable SYSCFG clock */
  RCC_APB2ENR|=RCC_SYSCFG_ENABLE_VALUE;
  //RCC->APB2ENR |= RCC_APB2LPENR_SYSCFGLPEN;

  /* Map PA0 to EXT0 */
  SYSCFG_EXTICR(pin)|=(port<<pin_offset);
  //SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;

  /* Enable the Rising/falling edge trigger */

  switch(edge){

  case RISING:
	  EXTI_RTSR|=(1<<pin);
	  break;

  case FALLING:
	  EXTI_FTSR|=(1<<pin);
	  break;

  case RISING_FALLING:
	  EXTI_RTSR|=(1<<pin);
	  EXTI_FTSR|=(1<<pin);
	  break;
  }


  /* Enable rising edge trigger */
  //EXTI->RTSR |= EXTI_RTSR_TR0;

  /* Disable falling edge trigger */
 // EXTI->FTSR &= ~(EXTI_FTSR_TR0);

  /* Enable interrupt/EVENT line */
    switch(type){

  case interrupt:
	  EXTI_IMR|=(1<<pin);
	  break;

  case event:
	  EXTI_EMR|=(1<<pin);
	  break;

  case interrupt_event:
	  EXTI_IMR|=(1<<pin);
	  EXTI_EMR|=(1<<pin);
	  break;
  }

  /* Enable interrupt line */
  //EXTI->IMR |= EXTI_IMR_MR0;

  /* Enable event line */
  //EXTI->EMR |= EXTI_EMR_MR0;

    /*enable the input pin in gpio*/
   // GPIO_IN_INIT(PORTA,0,gpio_input,0,pull_down);

}




/**
 * @brief   it enables the external interrupt
 * @note    there is two ways of the or more than two ways,
 *          of software enabling of the external interrupt
 * @param   exit pin
 * @retval  None
 */
void EXTI_SW_ENABLE(u8 pin ){
	EXTI_SWIER|=(1<<pin);
}




/**
 * @brief   Push button EXTI initialization function
 * @note    one way
 * @param   External interrupt pin
 * @retval  None
 */
void EXTI_MUSKING(u8 pin ){}



/**
 * @brief   function for clearing the pending of the EXIT
 * @note    On-board push button connected to PA0,
 *          so it can use only EXTI0
 * @param   None
 * @retval  None
 */
void EXTI_CLEAR_PENDING(u8 pin ){
	EXTI_PR|=(1<<pin);
}



/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */
/*
 * myEXIT.c
 *
 *  Created on: Jul 7, 2019
 *      Author: HP
 */


