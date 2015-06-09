/*******************************************************************************
* File Name: isr_blink.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <isr_blink.h>

#if !defined(isr_blink__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isr_blink_intc` */
#include <project.h>
    
enum lights {strobe = 0, collision, navigation, landing};
enum chanels {ch1 = 0, ch2, ch3, ch4, ch5, ch6, ch7, ch8};

extern uint8_t pwm_light[4];
extern uint8_t pwm_light_adj[4];
extern uint8_t channelValue[8];
extern int16_t channelTime[8];

extern uint8_t lightOff;

uint32_t seconds = 0;
    
extern uint16_t flashTime_StrobeLight;
extern uint16_t pauseTime_StrobeLight;
extern uint16_t flashTime_CollisionLight;


    
    
uint16_t counter_blink = 0;
uint16_t counter_off_millis = 0;
uint16_t counter_setup_millis = 0;
uint16_t counter_setup_adj_millis = 0;
uint16_t counter_button_millis = 0;
    
/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: isr_blink_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it. This function disables the interrupt, 
*  sets the default interrupt vector, sets the priority from the value in the
*  Design Wide Resources Interrupt Editor, then enables the interrupt to the 
*  interrupt controller.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_blink_Start(void)
{
    /* For all we know the interrupt is active. */
    isr_blink_Disable();

    /* Set the ISR to point to the isr_blink Interrupt. */
    isr_blink_SetVector(&isr_blink_Interrupt);

    /* Set the priority. */
    isr_blink_SetPriority((uint8)isr_blink_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_blink_Enable();
}


/*******************************************************************************
* Function Name: isr_blink_StartEx
********************************************************************************
*
* Summary:
*  Sets up the interrupt and enables it. This function disables the interrupt,
*  sets the interrupt vector based on the address passed in, sets the priority 
*  from the value in the Design Wide Resources Interrupt Editor, then enables 
*  the interrupt to the interrupt controller.
*  
*  When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*  used to provide consistent definition across compilers:
*  
*  Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*   Function prototype example:
*   CY_ISR_PROTO(MyISR);
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isr_blink_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isr_blink_Disable();

    /* Set the ISR to point to the isr_blink Interrupt. */
    isr_blink_SetVector(address);

    /* Set the priority. */
    isr_blink_SetPriority((uint8)isr_blink_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_blink_Enable();
}


/*******************************************************************************
* Function Name: isr_blink_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_blink_Stop(void)
{
    /* Disable this interrupt. */
    isr_blink_Disable();

    /* Set the ISR to point to the passive one. */
    isr_blink_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: isr_blink_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for isr_blink.
*
*   Add custom code between the START and END comments to keep the next version
*   of this file from over-writing your code.
*
*   Note You may use either the default ISR by using this API, or you may define
*   your own separate ISR through ISR_StartEx().
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(isr_blink_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START isr_blink_Interrupt` */

    
    isr_blink_ClearPending();
    Blink_Timer_ClearInterrupt(Blink_Timer_INTR_MASK_TC);
    //UART_2_UartPutChar('I');

    if (lightOff == 0)
    {
        //pwm_light[landing] = pwm_light_adj[landing];
        pwm_light[navigation] = pwm_light_adj[navigation];
        
        if (counter_blink == 0)
        {
            pwm_light[collision] = 0x00;
            pwm_light[strobe] = 0x00;
            if (channelValue[6] > 128)
            {
                pwm_light[landing] = pwm_light_adj[landing];
            }
            else
            {
                pwm_light[landing] = 0x00;
            }
            
        }
        
        if (counter_blink == 600)
        {
            pwm_light[collision] = pwm_light_adj[collision];
        }
        if (counter_blink == 600 + flashTime_CollisionLight)
        {
            pwm_light[collision] = 0x00;
        }
        
        if (counter_blink == 1020)
        {
             pwm_light[strobe] =  pwm_light_adj[strobe];
        }
        if (counter_blink == 1020 + flashTime_StrobeLight)
        {
             pwm_light[strobe] = 0x00;
        }
        if (counter_blink == 1020 + flashTime_StrobeLight + 60)
        {
             pwm_light[strobe] =  pwm_light_adj[strobe];
        }
        if (counter_blink == 1020 + flashTime_StrobeLight + pauseTime_StrobeLight + flashTime_StrobeLight)
        {
             pwm_light[strobe] = 0x00;
            counter_blink = 0;
        }
    }else if (counter_blink == 1200)
        counter_blink = 0;
    
    if (channelValue[ch3] == 0 && channelValue[ch2] == 255) // left stick in lower right corner
    {
        counter_setup_adj_millis++;
    }
    else
    {
        counter_setup_millis = 0;
    }
    
    if (channelValue[ch3] == 0 && channelValue[ch2] == 0) // left stick in lower right corner
    {
        counter_setup_millis++;
    }
    else
    {
        counter_setup_millis = 0;
    }
    
    if (Button_Read() == 0) // Button Pressed
    {
        counter_button_millis++;
    }
    else
    {
        counter_button_millis = 0;
    }
    counter_blink++;
    counter_off_millis++;
    /* `#END` */
}


/*******************************************************************************
* Function Name: isr_blink_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isr_blink_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use isr_blink_StartEx instead.
* 
*   When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*   used to provide consistent definition across compilers:
*
*   Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*
*   Function prototype example:
*     CY_ISR_PROTO(MyISR);
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isr_blink_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + isr_blink__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: isr_blink_GetVector
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
cyisraddress isr_blink_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + isr_blink__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: isr_blink_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling isr_blink_Start or isr_blink_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after isr_blink_Start or isr_blink_StartEx has been called. 
*   To set the initial priority for the component, use the Design-Wide Resources
*   Interrupt Editor.
*
*   Note This API has no effect on Non-maskable interrupt NMI).
*
* Parameters:
*   priority: Priority of the interrupt, 0 being the highest priority
*             PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*             PSoC 4: Priority is from 0 to 3.
*
* Return:
*   None
*
*******************************************************************************/
void isr_blink_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((isr_blink__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *isr_blink_INTC_PRIOR = (*isr_blink_INTC_PRIOR & (uint32)(~isr_blink__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: isr_blink_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt, 0 being the highest priority
*    PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*    PSoC 4: Priority is from 0 to 3.
*
*******************************************************************************/
uint8 isr_blink_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((isr_blink__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*isr_blink_INTC_PRIOR & isr_blink__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: isr_blink_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt to the interrupt controller. Do not call this function
*   unless ISR_Start() has been called or the functionality of the ISR_Start() 
*   function, which sets the vector and the priority, has been called.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_blink_Enable(void)
{
    /* Enable the general interrupt. */
    *isr_blink_INTC_SET_EN = isr_blink__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_blink_GetState
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
uint8 isr_blink_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*isr_blink_INTC_SET_EN & (uint32)isr_blink__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: isr_blink_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt in the interrupt controller.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_blink_Disable(void)
{
    /* Disable the general interrupt. */
    *isr_blink_INTC_CLR_EN = isr_blink__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_blink_SetPending
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
* Side Effects:
*   If interrupts are enabled and the interrupt is set up properly, the ISR is
*   entered (depending on the priority of this interrupt and other pending 
*   interrupts).
*
*******************************************************************************/
void isr_blink_SetPending(void)
{
    *isr_blink_INTC_SET_PD = isr_blink__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_blink_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt in the interrupt controller.
*
*   Note Some interrupt sources are clear-on-read and require the block 
*   interrupt/status register to be read/cleared with the appropriate block API 
*   (GPIO, UART, and so on). Otherwise the ISR will continue to remain in 
*   pending state even though the interrupt itself is cleared using this API.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_blink_ClearPending(void)
{
    *isr_blink_INTC_CLR_PD = isr_blink__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
