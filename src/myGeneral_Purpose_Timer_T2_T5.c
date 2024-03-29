/*******************************************************************************
 * @file    timer.c
 * @author  Ahmed Eldeep
 * @email   ahmed@almohandes.org
 * @website http://almohandes.org/stm32
 * @date    11.09.2018
 *
 * @brief   Timer examples
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
#include <myGeneral_Purpose_Timer_T2_T5.h>
#include "Timer_regesters.h"
#include "gpio.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup timer
 * @brief
 * @{
 */

/**
 * @defgroup timer_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_private_variables
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_exported_functions
 * @{
 */

/**
 * @brief   Timer6 as up counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM6_UpCount_Config(void)
{
  /* Enable TIM6 clock */
  RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;

  /* Set counter direction as up-counter */
  TIM6->CR1 &= ~TIM_CR1_DIR;

  /* Set timer Prescaler, bus clock = 45 MHz, fCK_PSC / (PSC[15:0] + 1)
   * CK_CNT = 45000000 / (44999 + 1) -> 1000 Hz -> time base = 1 ms */
  TIM6->PSC = 44999;

  /* Set timer reload value */
  TIM6->ARR = 5000;

  /* Enable TIM6 counter */
  TIM6->CR1 |= TIM_CR1_CEN;
}

/**
 * @brief   Timer3 as down counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM3_DownCount_Config(void)
{
  /* Enable TIM5 clock */
  RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

  /* Set counter direction as down-counter */
  TIM3->CR1 |= TIM_CR1_DIR;

  /* Set timer Prescaler, bus clock = 45 MHz, fCK_PSC / (PSC[15:0] + 1)
   * CK_CNT = 45000000 / (44999 + 1) -> 1000 Hz -> time base = 1 ms */
  TIM3->PSC = 56249;

  /* Set timer reload value */
  TIM3->ARR = 5000;

  /* Enable TIM5 counter */
  TIM3->CR1 |= TIM_CR1_CEN;
}

/**
 * @brief   Timer4 as up down counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM4_UpDownCount_Config(void)
{
  /* Enable TIM4 clock */
  RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

  /* Set counter direction as up-down-counter */
  TIM4->CR1 |= TIM_CR1_CMS;

  /* Set timer Prescaler, bus clock = 45 MHz, fCK_PSC / (PSC[15:0] + 1)
   * CK_CNT = 45000000 / (44999 + 1) -> 1000 Hz -> time base = 1 ms */
  TIM4->PSC = 44999;

  /* Set timer reload value */
  TIM4->ARR = 5000;

  /* Enable update event interrupt */
  TIM4->DIER |= TIM_DIER_UIE;

  /* Enable TIM4 counter */
  TIM4->CR1 |= TIM_CR1_CEN;
}

/**
 * @brief   Timer4 IRQ callback function
 * @note
 * @param
 * @retval
 */
void TIM4_IRQ_Callback(void)
{
  /* Clear update interrupt flag */
  TIM4->SR &= ~TIM_SR_UIF;

  /* Toggle green LED */
  GPIO_Toggle_LED(EVAL_GREEN_LED);
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
