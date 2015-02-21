/*******************************************************************************
* File Name: LandingLight.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "LandingLight.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        LandingLight_PC =   (LandingLight_PC & \
                                (uint32)(~(uint32)(LandingLight_DRIVE_MODE_IND_MASK << (LandingLight_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (LandingLight_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: LandingLight_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void LandingLight_Write(uint8 value) 
{
    uint8 drVal = (uint8)(LandingLight_DR & (uint8)(~LandingLight_MASK));
    drVal = (drVal | ((uint8)(value << LandingLight_SHIFT) & LandingLight_MASK));
    LandingLight_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: LandingLight_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LandingLight_DM_STRONG     Strong Drive 
*  LandingLight_DM_OD_HI      Open Drain, Drives High 
*  LandingLight_DM_OD_LO      Open Drain, Drives Low 
*  LandingLight_DM_RES_UP     Resistive Pull Up 
*  LandingLight_DM_RES_DWN    Resistive Pull Down 
*  LandingLight_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LandingLight_DM_DIG_HIZ    High Impedance Digital 
*  LandingLight_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LandingLight_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(LandingLight__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: LandingLight_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro LandingLight_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LandingLight_Read(void) 
{
    return (uint8)((LandingLight_PS & LandingLight_MASK) >> LandingLight_SHIFT);
}


/*******************************************************************************
* Function Name: LandingLight_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 LandingLight_ReadDataReg(void) 
{
    return (uint8)((LandingLight_DR & LandingLight_MASK) >> LandingLight_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LandingLight_INTSTAT) 

    /*******************************************************************************
    * Function Name: LandingLight_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 LandingLight_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(LandingLight_INTSTAT & LandingLight_MASK);
		LandingLight_INTSTAT = maskedStatus;
        return maskedStatus >> LandingLight_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
