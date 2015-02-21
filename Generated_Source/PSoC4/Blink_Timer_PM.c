/*******************************************************************************
* File Name: Blink_Timer_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Blink_Timer.h"

static Blink_Timer_BACKUP_STRUCT Blink_Timer_backup;


/*******************************************************************************
* Function Name: Blink_Timer_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Blink_Timer_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Blink_Timer_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Blink_Timer_Sleep(void)
{
    if(0u != (Blink_Timer_BLOCK_CONTROL_REG & Blink_Timer_MASK))
    {
        Blink_Timer_backup.enableState = 1u;
    }
    else
    {
        Blink_Timer_backup.enableState = 0u;
    }

    Blink_Timer_Stop();
    Blink_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Blink_Timer_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Blink_Timer_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Blink_Timer_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Blink_Timer_Wakeup(void)
{
    Blink_Timer_RestoreConfig();

    if(0u != Blink_Timer_backup.enableState)
    {
        Blink_Timer_Enable();
    }
}


/* [] END OF FILE */
