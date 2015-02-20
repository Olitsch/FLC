/*******************************************************************************
* File Name: isr_uart.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <isr_uart.h>

#if !defined(isr_uart__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isr_uart_intc` */
    #include <UART_1_spi_uart.h>
    #include <UART_1.h>
    #include <UART_2_spi_uart.h>
    #include <UART_2.h>
    int8_t frameStart = 0;
    int8_t senderID = 0;
    int8_t senderClass = 0;
    int8_t frameID = 0;
    int32_t count = 0;
    int32_t tempcount = 0;
    int8_t byteCount = 0;
    int16_t channelTime[8] = {0,0,0,0,0,0,0,0};
    
    extern uint8_t pwm_light_adj[4];
    
/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: isr_uart_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_uart_Start(void)
{
    /* For all we know the interrupt is active. */
    isr_uart_Disable();

    /* Set the ISR to point to the isr_uart Interrupt. */
    isr_uart_SetVector(&isr_uart_Interrupt);

    /* Set the priority. */
    isr_uart_SetPriority((uint8)isr_uart_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_uart_Enable();
}


/*******************************************************************************
* Function Name: isr_uart_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isr_uart_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isr_uart_Disable();

    /* Set the ISR to point to the isr_uart Interrupt. */
    isr_uart_SetVector(address);

    /* Set the priority. */
    isr_uart_SetPriority((uint8)isr_uart_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_uart_Enable();
}


/*******************************************************************************
* Function Name: isr_uart_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
void isr_uart_Stop(void)
{
    /* Disable this interrupt. */
    isr_uart_Disable();

    /* Set the ISR to point to the passive one. */
    isr_uart_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: isr_uart_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for isr_uart.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(isr_uart_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START isr_uart_Interrupt` */
    uint32 rxdata;
    uint8_t i;
    //rxdata = UART_1_STATUS_REG;
    
    //PWM_WriteCompare(20);
    //UART_2_UartPutChar(0x11);
    rxdata = UART_1_UartGetChar();
    isr_uart_ClearPending();
    UART_1_ClearRxInterruptSource(UART_1_INTR_RX_ALL);
    count++;
    if (rxdata == 0xFE)
    {
        tempcount = count;
        frameStart = 1;
        senderID = 0;
        senderClass=0;
        frameID = 0;
        byteCount = 0;
        //UART_2_UartPutChar('1');
    }else  if (rxdata == 0x01 && frameStart == 1 && senderID == 0 && count == tempcount + 3)
    {
        senderID = 1;
        senderClass=0;
        frameID = 0;
        //UART_2_UartPutChar('2');
    }else  if (rxdata == 0x01 && frameStart == 1 && senderID == 1 && senderClass == 0 && count == tempcount + 4)
    {
        senderClass=1;
        frameID = 0;
        //UART_2_UartPutChar('3');
    }else  if (rxdata == 0x23 && frameStart == 1 && senderID == 1 && senderClass == 1 && frameID == 0 && count == tempcount + 5)
    {
        frameID = 1;
        //UART_2_UartPutChar('4');
    }else  if (frameStart == 1 && senderID == 1 && senderClass == 1 && frameID == 1 && count >= tempcount + 10)
    {
        byteCount++;
        //UART_1_UartPutChar(byteCount);
        switch (byteCount)
        {
            case 1:
                channelTime[0] = rxdata;
                break;
            
            case 2:
                channelTime[0] |= rxdata << 8;
                UART_2_UartPutChar('1');
                UART_2_UartPutChar((uint8_t) (channelTime[0]>>8));
                UART_2_UartPutChar((uint8_t) channelTime[0]);
                break;
            case 3:
                channelTime[1] = rxdata;
                break;
            
            case 4:
                channelTime[1] |= rxdata << 8;
                UART_2_UartPutChar('2');
                UART_2_UartPutChar((uint8_t) (channelTime[1]>>8));
                UART_2_UartPutChar((uint8_t) channelTime[1]);
                break;
            case 5:
                channelTime[2] = rxdata;
                break;
            
            case 6:
                channelTime[2] |= rxdata << 8;
                UART_2_UartPutChar('3');
                UART_2_UartPutChar((uint8_t) (channelTime[2]>>8));
                UART_2_UartPutChar((uint8_t) channelTime[2]);
                break;
            case 7:
                channelTime[3] = rxdata;
                break;
            
            case 8:
                channelTime[3] |= rxdata << 8;
                UART_2_UartPutChar('4');
                UART_2_UartPutChar((uint8_t) (channelTime[3]>>8));
                UART_2_UartPutChar((uint8_t) channelTime[3]);
                break;
            case 9:
                channelTime[4] = rxdata;
                break;
            
            case 10:
                channelTime[4] |= rxdata << 8;
                UART_2_UartPutChar('5');
                UART_2_UartPutChar((uint8_t) (channelTime[4]>>8));
                UART_2_UartPutChar((uint8_t) channelTime[4]);
                break;
            case 11:
                channelTime[5] = rxdata;
                break;
            
            case 12:
                channelTime[5] |= rxdata << 8;
                UART_2_UartPutChar('6');
                UART_2_UartPutChar((uint8_t) (channelTime[5]>>8));
                UART_2_UartPutChar((uint8_t) channelTime[5]);
                break;
            case 13:
                channelTime[6] = rxdata;
                break;
            
            case 14:
                channelTime[6] |= rxdata << 8;
                UART_2_UartPutChar('7');
                UART_2_UartPutChar((uint8_t) (channelTime[6]>>8));
                UART_2_UartPutChar((uint8_t) channelTime[6]);
                break;
            case 15:
                channelTime[7] = rxdata;
                break;
            
            case 16:
                channelTime[7] |= rxdata << 8;
                UART_2_UartPutChar('8');
                UART_2_UartPutChar((uint8_t) (channelTime[7]>>8));
                UART_2_UartPutChar((uint8_t) channelTime[7]);
                frameStart = 0;
                senderID = 0;
                senderClass=0;
                frameID = 0;
                byteCount = 0;
                count = 0;
                for (i=0;i<4;i++)
                    pwm_light_adj[i] = (channelTime[7] - 980) / 5;
                break;
        }
        /*
        if (byteCount == 1)
        {
            channelTime[1] = rxdata;

        }else if (byteCount == 2)
        {
            channelTime[1] |= rxdata << 8;
            UART_2_UartPutChar((uint8_t) (channelTime[1]>>8));
            UART_2_UartPutChar((uint8_t) channelTime[1]);
            frameStart = 0;
            senderID = 0;
            senderClass=0;
            frameID = 0;
            byteCount = 0;
            count = 0;
        }
        */
    }
    UART_1_ClearRxInterruptSource(UART_1_INTR_RX_ALL);
    /* `#END` */
}


/*******************************************************************************
* Function Name: isr_uart_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isr_uart_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use isr_uart_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isr_uart_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + isr_uart__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: isr_uart_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress isr_uart_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + isr_uart__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: isr_uart_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling isr_uart_Start
*   or isr_uart_StartEx will override any effect this method would 
*   have had. This method should only be called after isr_uart_Start or 
*   isr_uart_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void isr_uart_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((isr_uart__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *isr_uart_INTC_PRIOR = (*isr_uart_INTC_PRIOR & (uint32)(~isr_uart__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: isr_uart_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 3, 0 being the highest.
*
*******************************************************************************/
uint8 isr_uart_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((isr_uart__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*isr_uart_INTC_PRIOR & isr_uart__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: isr_uart_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_uart_Enable(void)
{
    /* Enable the general interrupt. */
    *isr_uart_INTC_SET_EN = isr_uart__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_uart_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 isr_uart_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*isr_uart_INTC_SET_EN & (uint32)isr_uart__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: isr_uart_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_uart_Disable(void)
{
    /* Disable the general interrupt. */
    *isr_uart_INTC_CLR_EN = isr_uart__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_uart_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_uart_SetPending(void)
{
    *isr_uart_INTC_SET_PD = isr_uart__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_uart_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_uart_ClearPending(void)
{
    *isr_uart_INTC_CLR_PD = isr_uart__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
