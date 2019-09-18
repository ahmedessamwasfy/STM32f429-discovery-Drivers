/*******************************************************************************
 * @file    gpio.c
 * @author  Ahmed Eldeep
 * @email   ahmed@almohandes.org
 * @website http://almohandes.org/stm32
 * @date    25.03.2018
 *
 * @brief   Some examples on how to use STM32 GPIOs
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
#include "myGPIO.h"
//#include "gpio.h"
/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup gpio
 * @brief
 * @{
 */

/**
 * @defgroup gpio_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_private_variables
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_exported_functions
 * @{
 */


/**
 * @brief   Any GPIO Pin Output initialization function Alternative / Normal
 * @note
 * @param	Port Name , bit Number , Mode, Alternative function , output type/ ,output speed, pull up / pull down
 * @retval
 */
void GPIO_OUT_INIT(GPIO_PORT port_name , u8 bit_number , gpio_mode mode, u8 AL_fun ,gpio_output_type out_type , gpio_output_speed speed, gpio_pulling  pull_type  )
{
    /* Enable port X clock */

	RCC_AHB1ENR |= (1<<port_name);

    /* Calculating port base addr */

	u32 portbase= myGPIOA_BASE + (u32)((1024)*(port_name));

	/* Select output mode */   /*   using generic formla as each port base exeede the previous by 0x400 */

	//u32 x =
	bit_word_addr(portbase,GPIOx_MODER,bit_number)|=(u32)(mode<<(2*bit_number));

	/* Select Alternative function */
	if(bit_number<8)
		bit_word_addr(portbase,GPIOx_AFRL,bit_number) |=((u32)(AL_fun<<(4*bit_number)));
	else
		bit_word_addr(portbase,GPIOx_AFRH,bit_number) |=((u32)(AL_fun<<(4*bit_number)));

	/* Select output type push-pull */

	bit_word_addr(portbase,GPIOx_OTYPER,bit_number) |=(u32)(out_type<<bit_number);


	/* Select output Speed */

	bit_word_addr(portbase,GPIOx_OSPEEDR,bit_number) |=(u32)(speed<<(2*bit_number));

    /* Enable SYSCFG clock */

	RCC_APB2ENR|=RCC_APB2LPENR_SYSCFGLPEN;


    /* Enable compensation cell */
	SYSCFG_CMPCR|=SYSCFG_CMPCR_CMP_PD;

    //SYSCFG->CMPCR |= SYSCFG_CMPCR_CMP_PD;

    /* Wait till compensation cell is ready */

    while((SYSCFG_CMPCR & SYSCFG_CMPCR_READY) != SYSCFG_CMPCR_READY)
    {

    }


	/* Select output pull_type */

	bit_word_addr(portbase,GPIOx_PUPDR,bit_number) |=(pull_type<<(2*bit_number));
/*
switch (port_name)
{
		case PORTA :
			//bit_word_addr(myGPIOA_BASE,GPIOx_MODER,bit_number)|=(mode<<port_name);
			break;
		case PORTB :
			break;
		case PORTC :
			break;
		case PORTD :
			break;
		case PORTE :
			break;
		case PORTF :
			break;
		case PORTG :
			break;
		case PORTH :
			break;
		case PORTI :
			break;
		case PORTJ :
			break;
		case PORTK :
			break;



}



*/

}


/**
 * @brief   Any GPIO Pin Output value whether high or low
 * @note
 * @param	Port Name , bit Number , desired state
 * @retval
 */
void GPIO_OUT_VALUE(GPIO_PORT port_name , u8 bit_number ,   gpio_output_state  state  ){
	u32 portbase= myGPIOA_BASE + (u32)((1024)*(port_name));

	switch(state){

	case HIGH:
		bit_word_addr(portbase,GPIOx_BSRRS,bit_number) |=((u32)(1<<bit_number));
		break;


	case LOW:
		bit_word_addr(portbase,GPIOx_BSRRR,bit_number) |=((u32)(1<<bit_number));

		break;

	default:
		break;

	}



}




/**
 * @brief   Any GPIO Pin input initialization function Alternative / Normal
 * @note
 * @param	Port Name , bit Number , Mode  , Alternative function, pull up_pull down
 * @retval
 */

void GPIO_IN_INIT(GPIO_PORT port_name , u8 bit_number , gpio_mode mode, u8 AL_fun ,gpio_pulling pull_type){


    /* Enable port X clock */

	RCC_AHB1ENR |= (1<<port_name);


    /* Calculating port base addr */

	u32 portbase= myGPIOA_BASE + (u32)((1024)*(port_name));

	/* Select output mode */   /*   using generic formla as each port base exeede the previous by 0x400 */

	bit_word_addr(portbase,GPIOx_MODER,bit_number)|=(u32)(mode<<(2*bit_number));

	/* Select Alternative function */
		if(bit_number<8)
			bit_word_addr(portbase,GPIOx_AFRL,bit_number) |=((u32)(AL_fun<<(4*bit_number)));
		else
			bit_word_addr(portbase,GPIOx_AFRH,bit_number) |=((u32)(AL_fun<<(4*bit_number)));

	/* Select output pull_type */

		bit_word_addr(portbase,GPIOx_PUPDR,bit_number) |=(pull_type<<(2*bit_number));

}



/**
 * @brief   Any GPIO Pin read the input value
 * @note
 * @param	Port Name , bit Number
 * @retval	the input value
 */

u8 GPIO_IN_value(GPIO_PORT port_name , u8 bit_number ){
	u32 portbase= myGPIOA_BASE + (u32)((1024)*(port_name));
	u8 result = ((bit_word_addr(portbase,GPIOx_IDR,bit_number)>>bit_number)&(1));
	return result;


}


/**
 * @brief   On-board LEDs initialization function
 * @note    EVAL_GREEN_LED -> PG13
 *          EVAL_RED_LED -> PG14
 * @param   Led_Type led
 * @retval  None
 */
void myGPIO_Init_LED(Led_Type led)
{
  /* Check LED type, please */
  switch (led)
  {
    case EVAL_ALL_LEDs:

      /* Enable port G clock */
    	RCC_AHB1ENR |= RCC_AHB1ENR_GPIOGEN;

    /* Calculating port base addr */

    	u32 portbase= myGPIOA_BASE + (u32)((1024)*(	PORTG));

      /* Reset mode */
    	bit_word_addr(portbase,GPIOx_MODER,13) &= ~(GPIO_MODER_MODER13 | GPIO_MODER_MODER14);

      /* Select output mode for pin 13, pin 14 */
    	bit_word_addr(portbase,GPIOx_MODER,13) |= GPIO_MODER_MODER13_0 | GPIO_MODER_MODER14_0;

      /* Select output type push-pull */
    	bit_word_addr(portbase,GPIOx_OTYPER,13) &= ~(GPIO_OTYPER_OT_13 | GPIO_OTYPER_OT_14);

      /* Select output speed very high */
    	bit_word_addr(portbase,GPIOx_OSPEEDR,13) |= (GPIO_OSPEEDER_OSPEEDR13_0 | GPIO_OSPEEDER_OSPEEDR13_1
          | GPIO_OSPEEDER_OSPEEDR14_0 | GPIO_OSPEEDER_OSPEEDR14_1);

      /* Enable SYSCFG clock */
    	RCC_APB2ENR |= RCC_APB2LPENR_SYSCFGLPEN;

      /* Enable compensation cell */
    	SYSCFG_CMPCR |= SYSCFG_CMPCR_CMP_PD;

      /* Wait till compensation cell is ready */
      while((SYSCFG_CMPCR & SYSCFG_CMPCR_READY) != SYSCFG_CMPCR_READY)
      {

      }

      /* Select no pull */
      bit_word_addr(portbase,GPIOx_PUPDR,13) &= ~(GPIO_PUPDR_PUPDR13 | GPIO_PUPDR_PUPDR14);

      break;

    default:
      break;
  }
}

/**
 * @brief   Turns on-board LED on
 * @note    EVAL_GREEN_LED -> PG13
 *          EVAL_RED_LED -> PG14
 * @param   Led_Type led
 * @retval  None
 */
void myGPIO_TurnON_LED(Led_Type led)
{
	u32 portbase= myGPIOA_BASE + (u32)((1024)*(PORTG));

  switch (led)
  {
    case EVAL_GREEN_LED:
    	bit_word_addr(portbase,GPIOx_BSRRS,13) = GPIO_BSRR_BS_13;
      break;

    case EVAL_RED_LED:
    	bit_word_addr(portbase,GPIOx_BSRRS,13) = GPIO_BSRR_BS_14;
      break;

    case EVAL_GREEN_LED_BITBAND:
      GREEN_LED_BITBAND = 1;
      break;

    default:
      break;
  }
}

/**
 * @brief   Turns on-board LED off
 * @note    EVAL_GREEN_LED -> PG13
 *          EVAL_RED_LED -> PG14
 * @param   Led_Type led
 * @retval  None
 */
void myGPIO_TurnOFF_LED(Led_Type led)
{
	u32 portbase= myGPIOA_BASE + (u32)((1024)*(PORTG));

  switch (led)
  {
    case EVAL_GREEN_LED:
    	bit_word_addr(portbase,GPIOx_BSRRS,13) = GPIO_BSRR_BS_13;
      break;

    case EVAL_RED_LED:
    	bit_word_addr(portbase,GPIOx_BSRRS,13) = GPIO_BSRR_BS_14;
      break;

    case EVAL_GREEN_LED_BITBAND:
      GREEN_LED_BITBAND = 0;
      break;

    default:
      break;
  }
}





