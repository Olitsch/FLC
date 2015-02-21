/*******************************************************************************
* File Name: NavLight.c  
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
#include "NavLight.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        NavLight_PC =   (NavLight_PC & \
                                (uint32)(~(uint32)(NavLight_DRIVE_MODE_IND_MASK << (NavLight_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (NavLight_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: NavLight_Write
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
void NavLight_Write(uint8 value) 
{
    uint8 drVal = (uint8)(NavLight_DR & (uint8)(~NavLight_MASK));
    drVal = (drVal | ((uint8)(value << NavLight_SHIFT) & NavLight_MASK));
    NavLight_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: NavLight_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  NavLight_DM_STRONG     Strong Drive 
*  NavLight_DM_OD_HI      Open Drain, Drives High 
*  NavLight_DM_OD_LO      Open Drain, Drives Low 
*  NavLight_DM_RES_UP     Resistive Pull Up 
*  NavLight_DM_RES_DWN    Resistive Pull Down 
*  NavLight_DM_RES_UPDWN  Resistive Pull Up/Down 
*  NavLight_DM_DIG_HIZ    High Impedance Digital 
*  NavLight_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void NavLight_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(NavLight__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: NavLight_Read
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
*  Macro NavLight_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 NavLight_Read(void) 
{
    return (uint8)((NavLight_PS & NavLight_MASK) >> NavLight_SHIFT);
}


/*******************************************************************************
* Function Name: NavLight_ReadDataReg
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
uint8 NavLight_ReadDataReg(void) 
{
    return (uint8)((NavLight_DR & NavLight_MASK) >> NavLight_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(NavLight_INTSTAT) 

    /*******************************************************************************
    * Function Name: NavLight_ClearInterrupt
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
    uint8 NavLight_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(NavLight_INTSTAT & NavLight_MASK);
		NavLight_INTSTAT = maskedStatus;
        return maskedStatus >> NavLight_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
