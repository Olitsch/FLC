/*******************************************************************************
* File Name: CollisionLight.h  
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

#if !defined(CY_PINS_CollisionLight_H) /* Pins CollisionLight_H */
#define CY_PINS_CollisionLight_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CollisionLight_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    CollisionLight_Write(uint8 value) ;
void    CollisionLight_SetDriveMode(uint8 mode) ;
uint8   CollisionLight_ReadDataReg(void) ;
uint8   CollisionLight_Read(void) ;
uint8   CollisionLight_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CollisionLight_DRIVE_MODE_BITS        (3)
#define CollisionLight_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - CollisionLight_DRIVE_MODE_BITS))

#define CollisionLight_DM_ALG_HIZ         (0x00u)
#define CollisionLight_DM_DIG_HIZ         (0x01u)
#define CollisionLight_DM_RES_UP          (0x02u)
#define CollisionLight_DM_RES_DWN         (0x03u)
#define CollisionLight_DM_OD_LO           (0x04u)
#define CollisionLight_DM_OD_HI           (0x05u)
#define CollisionLight_DM_STRONG          (0x06u)
#define CollisionLight_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define CollisionLight_MASK               CollisionLight__MASK
#define CollisionLight_SHIFT              CollisionLight__SHIFT
#define CollisionLight_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CollisionLight_PS                     (* (reg32 *) CollisionLight__PS)
/* Port Configuration */
#define CollisionLight_PC                     (* (reg32 *) CollisionLight__PC)
/* Data Register */
#define CollisionLight_DR                     (* (reg32 *) CollisionLight__DR)
/* Input Buffer Disable Override */
#define CollisionLight_INP_DIS                (* (reg32 *) CollisionLight__PC2)


#if defined(CollisionLight__INTSTAT)  /* Interrupt Registers */

    #define CollisionLight_INTSTAT                (* (reg32 *) CollisionLight__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define CollisionLight_DRIVE_MODE_SHIFT       (0x00u)
#define CollisionLight_DRIVE_MODE_MASK        (0x07u << CollisionLight_DRIVE_MODE_SHIFT)


#endif /* End Pins CollisionLight_H */


/* [] END OF FILE */
