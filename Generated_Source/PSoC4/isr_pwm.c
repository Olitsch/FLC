/*******************************************************************************
* File Name: isr_pwm.c  
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
#include <isr_pwm.h>

#if !defined(isr_pwm__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isr_pwm_intc` */
#include <project.h>

enum lights {strobe = 0, collision, navigation, landing};

extern  uint8_t pwm_light[4];
    
uint8_t counter_pwm = 0;

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: isr_pwm_Start
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
void isr_pwm_Start(void)
{
    /* For all we know the interrupt is active. */
    isr_pwm_Disable();

    /* Set the ISR to point to the isr_pwm Interrupt. */
    isr_pwm_SetVector(&isr_pwm_Interrupt);

    /* Set the priority. */
    isr_pwm_SetPriority((uint8)isr_pwm_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_pwm_Enable();
}


/*******************************************************************************
* Function Name: isr_pwm_StartEx
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
void isr_pwm_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isr_pwm_Disable();

    /* Set the ISR to point to the isr_pwm Interrupt. */
    isr_pwm_SetVector(address);

    /* Set the priority. */
    isr_pwm_SetPriority((uint8)isr_pwm_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_pwm_Enable();
}


/*******************************************************************************
* Function Name: isr_pwm_Stop
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
void isr_pwm_Stop(void)
{
    /* Disable this interrupt. */
    isr_pwm_Disable();

    /* Set the ISR to point to the passive one. */
    isr_pwm_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: isr_pwm_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for isr_pwm.
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
CY_ISR(isr_pwm_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START isr_pwm_Interrupt` */
    isr_pwm_ClearPending();
    PWM_Timer_ClearInterrupt(PWM_Timer_INTR_MASK_TC);
    if (counter_pwm == 0 &&  pwm_light[landing] != 0)      //PWM frame start
    {
        LandingLight_Write(0xFF);
    }
    if (counter_pwm == 0 &&  pwm_light[navigation] != 0)      //PWM frame start
    {
        NavLight_Write(0xFF);
    }
    if (counter_pwm == 0 &&  pwm_light[strobe] != 0)      //PWM frame start
    {
        StrobeLight_Write(0xFF);
    }
    if (counter_pwm == 0 &&  pwm_light[collision] != 0)      //PWM frame start
    {
        CollisionLight_Write(0xFF);
    }
    if (counter_pwm ==  pwm_light[landing]) LandingLight_Write(0x00);      //PWM turn LandingLight off
    if (counter_pwm ==  pwm_light[navigation]) NavLight_Write(0x00);              //PWM turn LandingLight off
    if (counter_pwm ==  pwm_light[strobe]) StrobeLight_Write(0x00);        //PWM turn LandingLight off
    if (counter_pwm ==  pwm_light[collision]) CollisionLight_Write(0x00);  //PWM turn LandingLight off
        
    
    counter_pwm++;
    
    /* `#END` */
}


/*******************************************************************************
* Function Name: isr_pwm_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isr_pwm_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use isr_pwm_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isr_pwm_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + isr_pwm__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: isr_pwm_GetVector
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
cyisraddress isr_pwm_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + isr_pwm__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: isr_pwm_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling isr_pwm_Start
*   or isr_pwm_StartEx will override any effect this method would 
*   have had. This method should only be called after isr_pwm_Start or 
*   isr_pwm_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void isr_pwm_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((isr_pwm__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *isr_pwm_INTC_PRIOR = (*isr_pwm_INTC_PRIOR & (uint32)(~isr_pwm__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: isr_pwm_GetPriority
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
uint8 isr_pwm_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((isr_pwm__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*isr_pwm_INTC_PRIOR & isr_pwm__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: isr_pwm_Enable
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
void isr_pwm_Enable(void)
{
    /* Enable the general interrupt. */
    *isr_pwm_INTC_SET_EN = isr_pwm__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_pwm_GetState
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
uint8 isr_pwm_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*isr_pwm_INTC_SET_EN & (uint32)isr_pwm__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: isr_pwm_Disable
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
void isr_pwm_Disable(void)
{
    /* Disable the general interrupt. */
    *isr_pwm_INTC_CLR_EN = isr_pwm__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_pwm_SetPending
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
void isr_pwm_SetPending(void)
{
    *isr_pwm_INTC_SET_PD = isr_pwm__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_pwm_ClearPending
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
void isr_pwm_ClearPending(void)
{
    *isr_pwm_INTC_CLR_PD = isr_pwm__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
