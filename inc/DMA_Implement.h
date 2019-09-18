/*
 * DMA_Implement.h
 *
 *  Created on: Sep 12, 2019
 *      Author: Ahmed Wasfy
 */

#ifndef INC_DMA_IMPLEMENT_H_
#define INC_DMA_IMPLEMENT_H_

/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */
/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */
#include"Std_Types.h"
#include"DMA_Reg.h"
#include"DMA_Cfg.h"

/* Inclusion of system and local header files goes here */



/* ==================================================================== */
/* ============================ constants ============================= */
/* ==================================================================== */



/* ==================================================================== */
/* ============================ DMA 2 ================================= */
/* ==================================================================== */

/* ============================ STREAM 0 ================================= */

/**
 * @brief   DMA2 Stream0 initialization function
 * @note    Used for data transfer between two memory buffers
 * @param   None
 * @retval  None
 */
void DMA2_Stream_0_Init(void);

/**
 * @brief   DMA2 Stream0 set addresses function
 * @note    Sets the addresses of the memory and peripheral ports,
 *          and number of data items to be transfered.
 * @param   src, dst, size
 * @retval  None
 */
void DMA2_Stream_0_Set_Addresses_M2M(const uint32 * src,
    uint32 * dst, const uint32 size);

/**
 * @brief   DMA2 Stream0 enable function
 * @note
 * @param   None
 * @retval  None
 */
void DMA2_Stream_0_Enable();



/**
 * @brief   DMA2 Stream0 Change Channel function
 * @note    Used to change the channel
 * @param   None
 * @retval  None
 */
void DMA2_Stream_0_Change_Channel(void);


/* #define and enum statements go here */



/* ==================================================================== */
/* ======================== global variables ========================== */
/* ==================================================================== */

/* Global variables definitions go here */



/* ==================================================================== */
/* ============================== data ================================ */
/* ==================================================================== */

/* Definition of datatypes go here */



/* ==================================================================== */
/* ==================== function prototypes =========================== */
/* ==================================================================== */

/* Function prototypes for public (external) functions go here */


/* @prog __ApplicationName ****************************************************
**
** __ShortDescription__
**
******************************************************************************/
	

#endif /* INC_DMA_IMPLEMENT_H_ */
