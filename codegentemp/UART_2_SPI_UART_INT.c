/*******************************************************************************
* File Name: UART_2_SPI_UART_INT.c
* Version 1.20
*
* Description:
*  This file provides the source code to the Interrupt Service Routine for
*  the SCB Component in SPI and UART modes.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UART_2_PVT.h"
#include "UART_2_SPI_UART_PVT.h"


/*******************************************************************************
* Function Name: UART_2_SPI_UART_ISR
********************************************************************************
*
* Summary:
*  Handles the Interrupt Service Routine for the SCB SPI or UART modes.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
CY_ISR(UART_2_SPI_UART_ISR)
{
#if(UART_2_INTERNAL_RX_SW_BUFFER_CONST)
    uint32 locHead;
    uint32 dataRx;
#endif /* (UART_2_INTERNAL_RX_SW_BUFFER_CONST) */

#if(UART_2_INTERNAL_TX_SW_BUFFER_CONST)
    uint32 locTail;
#endif /* (UART_2_INTERNAL_TX_SW_BUFFER_CONST) */

    if(NULL != UART_2_customIntrHandler)
    {
        UART_2_customIntrHandler();
    }

    #if(UART_2_CHECK_SPI_WAKE_ENABLE)
    {
        /* Clear SPI wakeup source */
        UART_2_ClearSpiExtClkInterruptSource(UART_2_INTR_SPI_EC_WAKE_UP);
    }
    #endif

    #if(UART_2_CHECK_RX_SW_BUFFER)
    {
        if(UART_2_CHECK_INTR_RX_MASKED(UART_2_INTR_RX_NOT_EMPTY))
        {
            while(0u != UART_2_GET_RX_FIFO_ENTRIES)
            {
                /* Get data from RX FIFO */
                dataRx = UART_2_RX_FIFO_RD_REG;

                /* Move local head index */
                locHead = (UART_2_rxBufferHead + 1u);

                /* Adjust local head index */
                if(UART_2_RX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                if(locHead == UART_2_rxBufferTail)
                {
                    /* Overflow: through away new data */
                    UART_2_rxBufferOverflow = (uint8) UART_2_INTR_RX_OVERFLOW;
                }
                else
                {
                    /* Store received data */
                    UART_2_PutWordInRxBuffer(locHead, dataRx);

                    /* Move head index */
                    UART_2_rxBufferHead = locHead;
                }
            }

            UART_2_ClearRxInterruptSource(UART_2_INTR_RX_NOT_EMPTY);
        }
    }
    #endif


    #if(UART_2_CHECK_TX_SW_BUFFER)
    {
        if(UART_2_CHECK_INTR_TX_MASKED(UART_2_INTR_TX_NOT_FULL))
        {
            /* Put data into TX FIFO */
            while(UART_2_FIFO_SIZE != UART_2_GET_TX_FIFO_ENTRIES)
            {
                /* Check for a room in TX software buffer */
                if(UART_2_txBufferHead != UART_2_txBufferTail)
                {
                    /* Move local tail index */
                    locTail = (UART_2_txBufferTail + 1u);

                    /* Adjust local tail index */
                    if(UART_2_TX_BUFFER_SIZE == locTail)
                    {
                        locTail = 0u;
                    }

                    /* Put data into TX FIFO */
                    UART_2_TX_FIFO_WR_REG = UART_2_GetWordFromTxBuffer(locTail);

                    /* Move tail index */
                    UART_2_txBufferTail = locTail;
                }
                else
                {
                    /* TX software buffer is empty: complete transmition */
                    UART_2_DISABLE_INTR_TX(UART_2_INTR_TX_NOT_FULL);
                    break;
                }
            }

            UART_2_ClearTxInterruptSource(UART_2_INTR_TX_NOT_FULL);
        }
    }
    #endif
}


/* [] END OF FILE */
