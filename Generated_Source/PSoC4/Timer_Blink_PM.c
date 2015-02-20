/*******************************************************************************
* File Name: Timer_Blink_PM.c
* Version 1.10
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

#include "Timer_Blink.h"

static Timer_Blink_BACKUP_STRUCT Timer_Blink_backup;


/*******************************************************************************
* Function Name: Timer_Blink_SaveConfig
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
void Timer_Blink_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_Blink_Sleep
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
void Timer_Blink_Sleep(void)
{
    if(0u != (Timer_Blink_BLOCK_CONTROL_REG & Timer_Blink_MASK))
    {
        Timer_Blink_backup.enableState = 1u;
    }
    else
    {
        Timer_Blink_backup.enableState = 0u;
    }

    Timer_Blink_Stop();
    Timer_Blink_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_Blink_RestoreConfig
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
void Timer_Blink_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_Blink_Wakeup
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
void Timer_Blink_Wakeup(void)
{
    Timer_Blink_RestoreConfig();

    if(0u != Timer_Blink_backup.enableState)
    {
        Timer_Blink_Enable();
    }
}


/* [] END OF FILE */
