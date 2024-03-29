/*******************************************************************************
 * @file    memcpy.c
 * @author  Ahmed Eldeep
 * @email   ahmed@almohandes.org
 * @website http://almohandes.org/stm32
 * @date    22.04.2018
 *          
 * @brief   Copy data between two memory buffers
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
#include <stddef.h>
#include "memcpy.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup memcpy
 * @brief
 * @{
 */

/**
 * @defgroup memcpy_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup memcpy_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup memcpy_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup memcpy_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup memcpy_private_variables
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup memcpy_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup memcpy_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup memcpy_exported_functions
 * @{
 */

/**
 * @brief   Copy data between two memory buffers
 * @note
 * @param   src, dst, size
 * @retval  RETURN_STATUS_OK, RETURN_STATUS_NOT_OK
 */
ReturnStatus_Type memcpy32(const uint32_t * src,
    uint32_t * dst, const uint32_t size)
{
  /* Return status */
  ReturnStatus_Type returnStatus = RETURN_STATUS_NOT_OK;

  /* Check for null pointer */
  if((NULL != src) && (NULL != dst))
  {
//    /* Pointers are OK, start copying */
//    for (uint32_t idx = 0; idx < size; idx++)
//    {
//      dst[idx] = src[idx];
//    }

    /* Get array length */
    uint32_t arrayLength = size;

    while (arrayLength > 0)
    {
      /* Copy one word then increment the pointers */
      *dst++ = *src++;

      /* Decrement array length */
      arrayLength--;
    }

    /* Return OK */
    returnStatus = RETURN_STATUS_OK;
  }
  else
  {
    /* Null pointer, Return status is not OK */
    returnStatus = RETURN_STATUS_NOT_OK;
  }

  /* Return status */
  return returnStatus;
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
