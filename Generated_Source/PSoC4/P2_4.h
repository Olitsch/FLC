/*******************************************************************************
* File Name: P2_4.h  
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

#if !defined(CY_PINS_P2_4_H) /* Pins P2_4_H */
#define CY_PINS_P2_4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "P2_4_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    P2_4_Write(uint8 value) ;
void    P2_4_SetDriveMode(uint8 mode) ;
uint8   P2_4_ReadDataReg(void) ;
uint8   P2_4_Read(void) ;
uint8   P2_4_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define P2_4_DRIVE_MODE_BITS        (3)
#define P2_4_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - P2_4_DRIVE_MODE_BITS))

#define P2_4_DM_ALG_HIZ         (0x00u)
#define P2_4_DM_DIG_HIZ         (0x01u)
#define P2_4_DM_RES_UP          (0x02u)
#define P2_4_DM_RES_DWN         (0x03u)
#define P2_4_DM_OD_LO           (0x04u)
#define P2_4_DM_OD_HI           (0x05u)
#define P2_4_DM_STRONG          (0x06u)
#define P2_4_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define P2_4_MASK               P2_4__MASK
#define P2_4_SHIFT              P2_4__SHIFT
#define P2_4_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P2_4_PS                     (* (reg32 *) P2_4__PS)
/* Port Configuration */
#define P2_4_PC                     (* (reg32 *) P2_4__PC)
/* Data Register */
#define P2_4_DR                     (* (reg32 *) P2_4__DR)
/* Input Buffer Disable Override */
#define P2_4_INP_DIS                (* (reg32 *) P2_4__PC2)


#if defined(P2_4__INTSTAT)  /* Interrupt Registers */

    #define P2_4_INTSTAT                (* (reg32 *) P2_4__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define P2_4_DRIVE_MODE_SHIFT       (0x00u)
#define P2_4_DRIVE_MODE_MASK        (0x07u << P2_4_DRIVE_MODE_SHIFT)


#endif /* End Pins P2_4_H */


/* [] END OF FILE */
