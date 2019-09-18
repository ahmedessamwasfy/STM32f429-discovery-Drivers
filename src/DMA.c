/*
 * DMA.c
 *
 *  Created on: Sep 12, 2019
 *      Author: Ahmed Wasfy
 */

#include"DMA_Implement.h"

/**
 * @brief   DMA2 Stream0 initialization function
 * @note    Used for data transfer between two memory buffers
 * @param   None
 * @retval  None
 */
void DMA2_Stream_0_Init()
{
  /* Enable DMA clock in RCC */
	RCC_AHB1ENR |= RCC_AHB1ENR_DMA2EN;


    /* DMA 2 stream 0 is enabled, shall be disabled first */
	DMA2_CR(0)&= ~DMA_SxCR_EN;

    /* Wait until EN bit is cleared */
    while(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_CR(0)))
    {
      /* Do nothing until EN bit is cleared */
    }


  /* Select the DMA channel CHSEL[2:0] in the DMA_SxCR.
   * (not needed when M->M). */
    DMA2_CR(0) |=DMA2_STREAM_0_Channel_Selection;

    /* Select Memmory brust */
    DMA2_CR(0)|=DMA2_STREAM_0_MBURST;

    /* Select perepheral brust */
    DMA2_CR(0)|=DMA2_STREAM_0_PBURST;


    /* Select Current target (only in double buffer mode)*/

	#if DMA2_STREAM_0_CT==TRUE
		DMA2_CR(0)|=DMA_SxCR_CT;
	#endif

	 /* Select DBM: Double buffer mode*/

	#if DMA2_STREAM_0_DBM==TRUE
		DMA2_CR(0)|=DMA_SxCR_DBM;
	#endif

  /* Select stream priority very high */
    DMA2_CR(0) |= DMA2_STREAM_0_PL;


   /* Select INCOS: Peripheral increment offset size*/

	#if DMA2_STREAM_0_PINCOS==TRUE
		DMA2_CR(0)|=DMA_SxCR_PINCOS;
	#endif

	/* Select memory and peripherals sizes */
	  DMA2_CR(0)  |= DMA2_STREAM_0_MSIZE;
	  DMA2_CR(0)  |= DMA2_STREAM_0_PSIZE;


	 /* Select  MINC: Memory increment mode*/

	#if DMA2_STREAM_0_MINC==TRUE
		DMA2_CR(0)|=DMA_SxCR_MINC;
	#endif

	/* Select  PINC: Peripheral increment mode*/

	#if DMA2_STREAM_0_PINC==TRUE
		DMA2_CR(0)|=DMA_SxCR_PINC;
	#endif


	/* Select  CIRC: Circular mode*/

	#if DMA2_STREAM_0_CIRC==TRUE
		DMA2_CR(0)|=DMA_SxCR_CIRC;
	#endif




  /* Select the data transfer direction memory to memory */
    DMA2_CR(0)  |= DMA2_STREAM_0_DIR;


    /* Select  PFCTRL: Peripheral flow controller*/

	#if DMA2_STREAM_0_PFCTRL==TRUE
		DMA2_CR(0)|=DMA_SxCR_PFCTRL;
	#endif



    /* Select TCIE: Transfer complete interrupt enable*/

	#if DMA2_STREAM_0_TCIE==TRUE
		DMA2_CR(0)|=DMA_SxCR_TCIE;
	#endif



    /* Select   HTIE: Half transfer interrupt enable*/

	#if DMA2_STREAM_0_HTIE==TRUE
		DMA2_CR(0)|=DMA_SxCR_HTIE;
	#endif


    /* Select  TEIE: Transfer error interrupt enable*/

	#if DMA2_STREAM_0_TEIE==TRUE
		DMA2_CR(0)|=DMA_SxCR_TEIE;
	#endif



	/* Select  DMEIE: Direct mode error interrupt enable*/

	#if DMA2_STREAM_0_DMEIE==TRUE
		DMA2_CR(0)|=DMA_SxCR_DMEIE;
	#endif



//# DMA_FCR			/*!< DMA stream x FIFO control register       */


		/* Select FEIE: FIFO error interrupt enable */

	DMA2_FCR(0) |= DMA2_STREAM_0_FIFO_Error_Interrupt_enable*DMA_SxFCR_FEIE;

  /* Select FIFO mode, it will be also set by hardware when stream enabled */
    DMA2_FCR(0) |= DMA2_STREAM_0_Direct_Mode_Disable*DMA_SxFCR_DMDIS;

  /* Select FIFO threshold level half FIFO */
    DMA2_FCR(0) |= DMA2_STREAM_0_FIFO_Threshold_Selection;



}



/**
 * @brief   DMA2 Stream0 set addresses function
 * @note    Sets the addresses of the memory and peripheral ports,
 *          and number of data items to be transfered.
 * @param   src, dst, size
 * @retval  None
 */
void DMA2_Stream_0_Set_Addresses_M2M(const uint32 * src,
    uint32 * dst, const uint32 size)
{

  /* Set the source address to the peripheral port */
	DMA2_PAR(0)= (uint32)src;

  /* Set the destination address to the memory port */
	DMA2_M0AR(0)= (uint32)dst;

  /* Set number of data items */
	DMA2_NDTR(0) = size;
}


/**
 * @brief   DMA2 Stream0 enable function
 * @note
 * @param   None
 * @retval  None
 */
void DMA2_Stream_0_Enable()
{
  /* Clear all interrupt flags */
	DMA2_LISR = (DMA_LIFCR_CFEIF0 | DMA_LIFCR_CDMEIF0 | DMA_LIFCR_CTEIF0
      | DMA_LIFCR_CHTIF0 | DMA_LIFCR_CTCIF0);

  /* Enable DMA 2 stream 0 */
	DMA2_CR(0) |= DMA_SxCR_EN;
}

