/*******************************************************************************
* File Name: StrobeLight.h  
* Version 2.5
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

#if !defined(CY_PINS_StrobeLight_H) /* Pins StrobeLight_H */
#define CY_PINS_StrobeLight_H

#include "cytypes.h"
#include "cyfitter.h"
#include "StrobeLight_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    StrobeLight_Write(uint8 value) ;
void    StrobeLight_SetDriveMode(uint8 mode) ;
uint8   StrobeLight_ReadDataReg(void) ;
uint8   StrobeLight_Read(void) ;
uint8   StrobeLight_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define StrobeLight_DRIVE_MODE_BITS        (3)
#define StrobeLight_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - StrobeLight_DRIVE_MODE_BITS))
#define StrobeLight_DRIVE_MODE_SHIFT       (0x00u)
#define StrobeLight_DRIVE_MODE_MASK        (0x07u << StrobeLight_DRIVE_MODE_SHIFT)

#define StrobeLight_DM_ALG_HIZ         (0x00u << StrobeLight_DRIVE_MODE_SHIFT)
#define StrobeLight_DM_DIG_HIZ         (0x01u << StrobeLight_DRIVE_MODE_SHIFT)
#define StrobeLight_DM_RES_UP          (0x02u << StrobeLight_DRIVE_MODE_SHIFT)
#define StrobeLight_DM_RES_DWN         (0x03u << StrobeLight_DRIVE_MODE_SHIFT)
#define StrobeLight_DM_OD_LO           (0x04u << StrobeLight_DRIVE_MODE_SHIFT)
#define StrobeLight_DM_OD_HI           (0x05u << StrobeLight_DRIVE_MODE_SHIFT)
#define StrobeLight_DM_STRONG          (0x06u << StrobeLight_DRIVE_MODE_SHIFT)
#define StrobeLight_DM_RES_UPDWN       (0x07u << StrobeLight_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define StrobeLight_MASK               StrobeLight__MASK
#define StrobeLight_SHIFT              StrobeLight__SHIFT
#define StrobeLight_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define StrobeLight_PS                     (* (reg32 *) StrobeLight__PS)
/* Port Configuration */
#define StrobeLight_PC                     (* (reg32 *) StrobeLight__PC)
/* Data Register */
#define StrobeLight_DR                     (* (reg32 *) StrobeLight__DR)
/* Input Buffer Disable Override */
#define StrobeLight_INP_DIS                (* (reg32 *) StrobeLight__PC2)


#if defined(StrobeLight__INTSTAT)  /* Interrupt Registers */

    #define StrobeLight_INTSTAT                (* (reg32 *) StrobeLight__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins StrobeLight_H */


/* [] END OF FILE */
