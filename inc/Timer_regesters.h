/*
 * Timer_regesters.h
 *
 *  Created on: Jul 24, 2019
 *      Author: Ahmed Wasfy
 */

#ifndef INC_TIMER_REGESTERS_H_
#define INC_TIMER_REGESTERS_H_

/**
  * @brief TIMER offsets for all timers
  */

#define	TIMERx_CR1      0x00    /*!< TIM control register 1,              Address offset: 0x00 */

#define TIMERx_CR2      0x04    /*!< TIM control register 2,              Address offset: 0x04 */

#define TIMERx_SMCR     0x08    /*!< TIM slave mode control register,     Address offset: 0x08 */

#define TIMERx_DIER     0x0C    /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */

#define TIMERx_SR       0x10    /*!< TIM status register,                 Address offset: 0x10 */

#define TIMERx_EGR      0x14    /*!< TIM event generation register,       Address offset: 0x14 */

#define TIMERx_CCMR1    0x18    /*!< TIM capture/compare mode register 1, Address offset: 0x18 */

#define TIMERx_CCMR2    0x1C    /*!< TIM capture/compare mode register 2, Address offset: 0x1C */

#define TIMERx_CCER     0x20    /*!< TIM capture/compare enable register, Address offset: 0x20 */

#define TIMERx_CNT      0x24    /*!< TIM counter register,                Address offset: 0x24 */

#define TIMERx_PSC      0x28    /*!< TIM prescaler,                       Address offset: 0x28 */


#define TIMERx_ARR      0x2C    /*!< TIM auto-reload register,            Address offset: 0x2C */  //u32

#define TIMERx_RCR      0x30    /*!< TIM repetition counter register,     Address offset: 0x30 */

#define TIMERx_CCR1     0x34    /*!< TIM capture/compare register 1,      Address offset: 0x34 */ //u32

#define TIMERx_CCR2     0x38    /*!< TIM capture/compare register 2,      Address offset: 0x38 */	//u32

#define TIMERx_CCR3     0x3C    /*!< TIM capture/compare register 3,      Address offset: 0x3C */	//u32

#define TIMERx_CCR4     0x40    /*!< TIM capture/compare register 4,      Address offset: 0x40 */	//u32

#define TIMERx_BDTR     0x44    /*!< TIM break and dead-time register,    Address offset: 0x44 */

#define TIMERx_DCR      0x48    /*!< TIM DMA control register,            Address offset: 0x48 */

#define TIMERx_DMAR     0x4C    /*!< TIM DMA address for full transfer,   Address offset: 0x4C */

#define TIMERx_OR       0x50    /*!< TIM option register,                 Address offset: 0x50 */



/**
  * @brief enum and typedef of all the regusters components
  */



/******************************TIMERx_CR1*********************TIM control register 1, Address offset: 0x00 ****************/
/**
  * @brief it's a flag and/or innterrupt hapens when the data reach it's end
  * 		so we can enable this UEV or disable it
  *
  * @state  Update event enable
  * 	    Update event disable
  */
typedef enum{
	UEV_Enable,
	UEV_Disable
}UDIS_update_state;






/**
  * @brief 	this bit is set to selct the UEV event sources
  * 				1.counter overflow/underflow
  * 				2.setting the UG bit
  * 				3.Update generation
  * 		OR for overflow/underflow or dma request only
  *
  * @state  0.Update event source all for counter over/underflow
  * 		setting UG bit,or update generation
  *
  * 	    1.the event source is for  overflow/underflow or dma request only
  */
typedef enum{
	URS_Source_all,
	URS_Source_OUF
}URS_update_request_source;



/**
  * @brief 	this bit is set to selct the UEV event sources
  * @bit number		bit 3
  * @state  0: Counter is not stopped at update event
  *			1: Counter stops counting at the next update event (clearing the bit CEN)
  */
typedef enum{
	OPM_Enable,
	OPM_Disable
}OPM_one_pulse_mode;



/**
  * @brief 	this bit is set to selct the UEV event sources
  * @bit number		bit 4
  * @state  0: Counter is not stopped at update event
  *			1: Counter stops counting at the next update event (clearing the bit CEN)
  */
typedef enum{
	Upcount,
	Downcount
}DIR_direction;



/**
  * @brief
  * @bit number		bit 5:6
  * @state  00: Edge-aligned mode. The counter counts up or down depending on the direction bit
				(DIR).

			01: Center-aligned mode 1. The counter counts up and down alternatively. Output compare
			interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set
			only when the counter is counting down.

			10: Center-aligned mode 2. The counter counts up and down alternatively. Output compare
			interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set
			only when the counter is counting up.

			11: Center-aligned mode 3. The counter counts up and down alternatively. Output compare
			interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set
			both when the counter is counting up or down.
*/
typedef enum{
	Cemter_aligned_Disable,
	Center_aligned_mode_1,
	Center_aligned_mode_2,
	Center_alinged_mode_3
}CMS_Center_aligned_mode_selection;




/**
  * @brief 	This is the auto_reload preloading enable
  *	@bit number		bit 7
  * @state  0: TIMx_ARR register is not buffered
  *			1: TIMx_ARR register is buffered
  */
typedef enum{
	Not_buffered,
	buffered
}ARPE,Auto_reload_preload_enable;



/**
  * @brief
  * @bit number		bit 8:9
  * @state  This bit-field indicates the division ratio between the timer clock (CK_INT) frequency and
				sampling clock used by the digital filters (ETR, TIx)
				00: t DTS  = t CK_INT
				01: t DTS  = 2 × t CK_INT
				10: t DTS  = 4 × t CK_INT
				11:  Reserved

*/
typedef enum{
	CLK_Division_Mode_0,
	CLK_Division_Mode_1,
	CLK_Division_Mode_2,
}CKD_Clock_division;




/******************************TIMERx_CR2*********************TIM control register 2, Address offset: 0x04 ****************/



#endif /* INC_TIMER_REGESTERS_H_ */
