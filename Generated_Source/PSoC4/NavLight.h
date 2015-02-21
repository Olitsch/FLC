/*******************************************************************************
* File Name: NavLight.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_NavLight_H) /* Pins NavLight_H */
#define CY_PINS_NavLight_H

#include "cytypes.h"
#include "cyfitter.h"
#include "NavLight_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    NavLight_Write(uint8 value) ;
void    NavLight_SetDriveMode(uint8 mode) ;
uint8   NavLight_ReadDataReg(void) ;
uint8   NavLight_Read(void) ;
uint8   NavLight_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define NavLight_DRIVE_MODE_BITS        (3)
#define NavLight_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - NavLight_DRIVE_MODE_BITS))

#define NavLight_DM_ALG_HIZ         (0x00u)
#define NavLight_DM_DIG_HIZ         (0x01u)
#define NavLight_DM_RES_UP          (0x02u)
#define NavLight_DM_RES_DWN         (0x03u)
#define NavLight_DM_OD_LO           (0x04u)
#define NavLight_DM_OD_HI           (0x05u)
#define NavLight_DM_STRONG          (0x06u)
#define NavLight_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define NavLight_MASK               NavLight__MASK
#define NavLight_SHIFT              NavLight__SHIFT
#define NavLight_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NavLight_PS                     (* (reg32 *) NavLight__PS)
/* Port Configuration */
#define NavLight_PC                     (* (reg32 *) NavLight__PC)
/* Data Register */
#define NavLight_DR                     (* (reg32 *) NavLight__DR)
/* Input Buffer Disable Override */
#define NavLight_INP_DIS                (* (reg32 *) NavLight__PC2)


#if defined(NavLight__INTSTAT)  /* Interrupt Registers */

    #define NavLight_INTSTAT                (* (reg32 *) NavLight__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define NavLight_DRIVE_MODE_SHIFT       (0x00u)
#define NavLight_DRIVE_MODE_MASK        (0x07u << NavLight_DRIVE_MODE_SHIFT)


#endif /* End Pins NavLight_H */


/* [] END OF FILE */
