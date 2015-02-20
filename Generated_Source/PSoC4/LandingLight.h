/*******************************************************************************
* File Name: LandingLight.h  
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

#if !defined(CY_PINS_LandingLight_H) /* Pins LandingLight_H */
#define CY_PINS_LandingLight_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LandingLight_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LandingLight_Write(uint8 value) ;
void    LandingLight_SetDriveMode(uint8 mode) ;
uint8   LandingLight_ReadDataReg(void) ;
uint8   LandingLight_Read(void) ;
uint8   LandingLight_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LandingLight_DRIVE_MODE_BITS        (3)
#define LandingLight_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LandingLight_DRIVE_MODE_BITS))
#define LandingLight_DRIVE_MODE_SHIFT       (0x00u)
#define LandingLight_DRIVE_MODE_MASK        (0x07u << LandingLight_DRIVE_MODE_SHIFT)

#define LandingLight_DM_ALG_HIZ         (0x00u << LandingLight_DRIVE_MODE_SHIFT)
#define LandingLight_DM_DIG_HIZ         (0x01u << LandingLight_DRIVE_MODE_SHIFT)
#define LandingLight_DM_RES_UP          (0x02u << LandingLight_DRIVE_MODE_SHIFT)
#define LandingLight_DM_RES_DWN         (0x03u << LandingLight_DRIVE_MODE_SHIFT)
#define LandingLight_DM_OD_LO           (0x04u << LandingLight_DRIVE_MODE_SHIFT)
#define LandingLight_DM_OD_HI           (0x05u << LandingLight_DRIVE_MODE_SHIFT)
#define LandingLight_DM_STRONG          (0x06u << LandingLight_DRIVE_MODE_SHIFT)
#define LandingLight_DM_RES_UPDWN       (0x07u << LandingLight_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define LandingLight_MASK               LandingLight__MASK
#define LandingLight_SHIFT              LandingLight__SHIFT
#define LandingLight_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LandingLight_PS                     (* (reg32 *) LandingLight__PS)
/* Port Configuration */
#define LandingLight_PC                     (* (reg32 *) LandingLight__PC)
/* Data Register */
#define LandingLight_DR                     (* (reg32 *) LandingLight__DR)
/* Input Buffer Disable Override */
#define LandingLight_INP_DIS                (* (reg32 *) LandingLight__PC2)


#if defined(LandingLight__INTSTAT)  /* Interrupt Registers */

    #define LandingLight_INTSTAT                (* (reg32 *) LandingLight__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins LandingLight_H */


/* [] END OF FILE */
