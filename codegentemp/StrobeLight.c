/*******************************************************************************
* File Name: StrobeLight.c  
* Version 2.5
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
#include "StrobeLight.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        StrobeLight_PC =   (StrobeLight_PC & \
                                (uint32)(~(uint32)(StrobeLight_DRIVE_MODE_IND_MASK << (StrobeLight_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (StrobeLight_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: StrobeLight_Write
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
void StrobeLight_Write(uint8 value) 
{
    uint8 drVal = (uint8)(StrobeLight_DR & (uint8)(~StrobeLight_MASK));
    drVal = (drVal | ((uint8)(value << StrobeLight_SHIFT) & StrobeLight_MASK));
    StrobeLight_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: StrobeLight_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  StrobeLight_DM_STRONG     Strong Drive 
*  StrobeLight_DM_OD_HI      Open Drain, Drives High 
*  StrobeLight_DM_OD_LO      Open Drain, Drives Low 
*  StrobeLight_DM_RES_UP     Resistive Pull Up 
*  StrobeLight_DM_RES_DWN    Resistive Pull Down 
*  StrobeLight_DM_RES_UPDWN  Resistive Pull Up/Down 
*  StrobeLight_DM_DIG_HIZ    High Impedance Digital 
*  StrobeLight_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void StrobeLight_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(StrobeLight__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: StrobeLight_Read
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
*  Macro StrobeLight_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 StrobeLight_Read(void) 
{
    return (uint8)((StrobeLight_PS & StrobeLight_MASK) >> StrobeLight_SHIFT);
}


/*******************************************************************************
* Function Name: StrobeLight_ReadDataReg
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
uint8 StrobeLight_ReadDataReg(void) 
{
    return (uint8)((StrobeLight_DR & StrobeLight_MASK) >> StrobeLight_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(StrobeLight_INTSTAT) 

    /*******************************************************************************
    * Function Name: StrobeLight_ClearInterrupt
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
    uint8 StrobeLight_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(StrobeLight_INTSTAT & StrobeLight_MASK);
		StrobeLight_INTSTAT = maskedStatus;
        return maskedStatus >> StrobeLight_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
