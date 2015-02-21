/*******************************************************************************
* File Name: Blink_Timer.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the Blink_Timer
*  component.
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

#if !defined(CY_TCPWM_Blink_Timer_H)
#define CY_TCPWM_Blink_Timer_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} Blink_Timer_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  Blink_Timer_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define Blink_Timer_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define Blink_Timer_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define Blink_Timer_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define Blink_Timer_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define Blink_Timer_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define Blink_Timer_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define Blink_Timer_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define Blink_Timer_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define Blink_Timer_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define Blink_Timer_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define Blink_Timer_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define Blink_Timer_TC_RUN_MODE                    (0lu)
#define Blink_Timer_TC_COUNTER_MODE                (0lu)
#define Blink_Timer_TC_COMP_CAP_MODE               (2lu)
#define Blink_Timer_TC_PRESCALER                   (0lu)

/* Signal modes */
#define Blink_Timer_TC_RELOAD_SIGNAL_MODE          (0lu)
#define Blink_Timer_TC_COUNT_SIGNAL_MODE           (3lu)
#define Blink_Timer_TC_START_SIGNAL_MODE           (0lu)
#define Blink_Timer_TC_STOP_SIGNAL_MODE            (0lu)
#define Blink_Timer_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define Blink_Timer_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define Blink_Timer_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define Blink_Timer_TC_START_SIGNAL_PRESENT        (0lu)
#define Blink_Timer_TC_STOP_SIGNAL_PRESENT         (0lu)
#define Blink_Timer_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Blink_Timer_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define Blink_Timer_PWM_KILL_EVENT                 (0lu)
#define Blink_Timer_PWM_STOP_EVENT                 (0lu)
#define Blink_Timer_PWM_MODE                       (4lu)
#define Blink_Timer_PWM_OUT_N_INVERT               (0lu)
#define Blink_Timer_PWM_OUT_INVERT                 (0lu)
#define Blink_Timer_PWM_ALIGN                      (0lu)
#define Blink_Timer_PWM_RUN_MODE                   (0lu)
#define Blink_Timer_PWM_DEAD_TIME_CYCLE            (0lu)
#define Blink_Timer_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define Blink_Timer_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define Blink_Timer_PWM_COUNT_SIGNAL_MODE          (3lu)
#define Blink_Timer_PWM_START_SIGNAL_MODE          (0lu)
#define Blink_Timer_PWM_STOP_SIGNAL_MODE           (0lu)
#define Blink_Timer_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define Blink_Timer_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define Blink_Timer_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define Blink_Timer_PWM_START_SIGNAL_PRESENT       (0lu)
#define Blink_Timer_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define Blink_Timer_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Blink_Timer_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define Blink_Timer_TC_PERIOD_VALUE                (1000lu)
#define Blink_Timer_TC_COMPARE_VALUE               (65535lu)
#define Blink_Timer_TC_COMPARE_BUF_VALUE           (65535lu)
#define Blink_Timer_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define Blink_Timer_PWM_PERIOD_VALUE               (65535lu)
#define Blink_Timer_PWM_PERIOD_BUF_VALUE           (65535lu)
#define Blink_Timer_PWM_PERIOD_SWAP                (0lu)
#define Blink_Timer_PWM_COMPARE_VALUE              (65535lu)
#define Blink_Timer_PWM_COMPARE_BUF_VALUE          (65535lu)
#define Blink_Timer_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Blink_Timer__LEFT 0
#define Blink_Timer__RIGHT 1
#define Blink_Timer__CENTER 2
#define Blink_Timer__ASYMMETRIC 3

#define Blink_Timer__X1 0
#define Blink_Timer__X2 1
#define Blink_Timer__X4 2

#define Blink_Timer__PWM 4
#define Blink_Timer__PWM_DT 5
#define Blink_Timer__PWM_PR 6

#define Blink_Timer__INVERSE 1
#define Blink_Timer__DIRECT 0

#define Blink_Timer__CAPTURE 2
#define Blink_Timer__COMPARE 0

#define Blink_Timer__TRIG_LEVEL 3
#define Blink_Timer__TRIG_RISING 0
#define Blink_Timer__TRIG_FALLING 1
#define Blink_Timer__TRIG_BOTH 2

#define Blink_Timer__INTR_MASK_TC 1
#define Blink_Timer__INTR_MASK_CC_MATCH 2
#define Blink_Timer__INTR_MASK_NONE 0
#define Blink_Timer__INTR_MASK_TC_CC 3

#define Blink_Timer__UNCONFIG 8
#define Blink_Timer__TIMER 1
#define Blink_Timer__QUAD 3
#define Blink_Timer__PWM_SEL 7

#define Blink_Timer__COUNT_UP 0
#define Blink_Timer__COUNT_DOWN 1
#define Blink_Timer__COUNT_UPDOWN0 2
#define Blink_Timer__COUNT_UPDOWN1 3


/* Prescaler */
#define Blink_Timer_PRESCALE_DIVBY1                ((uint32)(0u << Blink_Timer_PRESCALER_SHIFT))
#define Blink_Timer_PRESCALE_DIVBY2                ((uint32)(1u << Blink_Timer_PRESCALER_SHIFT))
#define Blink_Timer_PRESCALE_DIVBY4                ((uint32)(2u << Blink_Timer_PRESCALER_SHIFT))
#define Blink_Timer_PRESCALE_DIVBY8                ((uint32)(3u << Blink_Timer_PRESCALER_SHIFT))
#define Blink_Timer_PRESCALE_DIVBY16               ((uint32)(4u << Blink_Timer_PRESCALER_SHIFT))
#define Blink_Timer_PRESCALE_DIVBY32               ((uint32)(5u << Blink_Timer_PRESCALER_SHIFT))
#define Blink_Timer_PRESCALE_DIVBY64               ((uint32)(6u << Blink_Timer_PRESCALER_SHIFT))
#define Blink_Timer_PRESCALE_DIVBY128              ((uint32)(7u << Blink_Timer_PRESCALER_SHIFT))

/* TCPWM set modes */
#define Blink_Timer_MODE_TIMER_COMPARE             ((uint32)(Blink_Timer__COMPARE         <<  \
                                                                  Blink_Timer_MODE_SHIFT))
#define Blink_Timer_MODE_TIMER_CAPTURE             ((uint32)(Blink_Timer__CAPTURE         <<  \
                                                                  Blink_Timer_MODE_SHIFT))
#define Blink_Timer_MODE_QUAD                      ((uint32)(Blink_Timer__QUAD            <<  \
                                                                  Blink_Timer_MODE_SHIFT))
#define Blink_Timer_MODE_PWM                       ((uint32)(Blink_Timer__PWM             <<  \
                                                                  Blink_Timer_MODE_SHIFT))
#define Blink_Timer_MODE_PWM_DT                    ((uint32)(Blink_Timer__PWM_DT          <<  \
                                                                  Blink_Timer_MODE_SHIFT))
#define Blink_Timer_MODE_PWM_PR                    ((uint32)(Blink_Timer__PWM_PR          <<  \
                                                                  Blink_Timer_MODE_SHIFT))

/* Quad Modes */
#define Blink_Timer_MODE_X1                        ((uint32)(Blink_Timer__X1              <<  \
                                                                  Blink_Timer_QUAD_MODE_SHIFT))
#define Blink_Timer_MODE_X2                        ((uint32)(Blink_Timer__X2              <<  \
                                                                  Blink_Timer_QUAD_MODE_SHIFT))
#define Blink_Timer_MODE_X4                        ((uint32)(Blink_Timer__X4              <<  \
                                                                  Blink_Timer_QUAD_MODE_SHIFT))

/* Counter modes */
#define Blink_Timer_COUNT_UP                       ((uint32)(Blink_Timer__COUNT_UP        <<  \
                                                                  Blink_Timer_UPDOWN_SHIFT))
#define Blink_Timer_COUNT_DOWN                     ((uint32)(Blink_Timer__COUNT_DOWN      <<  \
                                                                  Blink_Timer_UPDOWN_SHIFT))
#define Blink_Timer_COUNT_UPDOWN0                  ((uint32)(Blink_Timer__COUNT_UPDOWN0   <<  \
                                                                  Blink_Timer_UPDOWN_SHIFT))
#define Blink_Timer_COUNT_UPDOWN1                  ((uint32)(Blink_Timer__COUNT_UPDOWN1   <<  \
                                                                  Blink_Timer_UPDOWN_SHIFT))

/* PWM output invert */
#define Blink_Timer_INVERT_LINE                    ((uint32)(Blink_Timer__INVERSE         <<  \
                                                                  Blink_Timer_INV_OUT_SHIFT))
#define Blink_Timer_INVERT_LINE_N                  ((uint32)(Blink_Timer__INVERSE         <<  \
                                                                  Blink_Timer_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define Blink_Timer_TRIG_RISING                    ((uint32)Blink_Timer__TRIG_RISING)
#define Blink_Timer_TRIG_FALLING                   ((uint32)Blink_Timer__TRIG_FALLING)
#define Blink_Timer_TRIG_BOTH                      ((uint32)Blink_Timer__TRIG_BOTH)
#define Blink_Timer_TRIG_LEVEL                     ((uint32)Blink_Timer__TRIG_LEVEL)

/* Interrupt mask */
#define Blink_Timer_INTR_MASK_TC                   ((uint32)Blink_Timer__INTR_MASK_TC)
#define Blink_Timer_INTR_MASK_CC_MATCH             ((uint32)Blink_Timer__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define Blink_Timer_CC_MATCH_SET                   (0x00u)
#define Blink_Timer_CC_MATCH_CLEAR                 (0x01u)
#define Blink_Timer_CC_MATCH_INVERT                (0x02u)
#define Blink_Timer_CC_MATCH_NO_CHANGE             (0x03u)
#define Blink_Timer_OVERLOW_SET                    (0x00u)
#define Blink_Timer_OVERLOW_CLEAR                  (0x04u)
#define Blink_Timer_OVERLOW_INVERT                 (0x08u)
#define Blink_Timer_OVERLOW_NO_CHANGE              (0x0Cu)
#define Blink_Timer_UNDERFLOW_SET                  (0x00u)
#define Blink_Timer_UNDERFLOW_CLEAR                (0x10u)
#define Blink_Timer_UNDERFLOW_INVERT               (0x20u)
#define Blink_Timer_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define Blink_Timer_PWM_MODE_LEFT                  (Blink_Timer_CC_MATCH_CLEAR        |   \
                                                         Blink_Timer_OVERLOW_SET           |   \
                                                         Blink_Timer_UNDERFLOW_NO_CHANGE)
#define Blink_Timer_PWM_MODE_RIGHT                 (Blink_Timer_CC_MATCH_SET          |   \
                                                         Blink_Timer_OVERLOW_NO_CHANGE     |   \
                                                         Blink_Timer_UNDERFLOW_CLEAR)
#define Blink_Timer_PWM_MODE_ASYM                  (Blink_Timer_CC_MATCH_INVERT       |   \
                                                         Blink_Timer_OVERLOW_SET           |   \
                                                         Blink_Timer_UNDERFLOW_CLEAR)

#if (Blink_Timer_CY_TCPWM_V2)
    #if(Blink_Timer_CY_TCPWM_4000)
        #define Blink_Timer_PWM_MODE_CENTER                (Blink_Timer_CC_MATCH_INVERT       |   \
                                                                 Blink_Timer_OVERLOW_NO_CHANGE     |   \
                                                                 Blink_Timer_UNDERFLOW_CLEAR)
    #else
        #define Blink_Timer_PWM_MODE_CENTER                (Blink_Timer_CC_MATCH_INVERT       |   \
                                                                 Blink_Timer_OVERLOW_SET           |   \
                                                                 Blink_Timer_UNDERFLOW_CLEAR)
    #endif /* (Blink_Timer_CY_TCPWM_4000) */
#else
    #define Blink_Timer_PWM_MODE_CENTER                (Blink_Timer_CC_MATCH_INVERT       |   \
                                                             Blink_Timer_OVERLOW_NO_CHANGE     |   \
                                                             Blink_Timer_UNDERFLOW_CLEAR)
#endif /* (Blink_Timer_CY_TCPWM_NEW) */

/* Command operations without condition */
#define Blink_Timer_CMD_CAPTURE                    (0u)
#define Blink_Timer_CMD_RELOAD                     (8u)
#define Blink_Timer_CMD_STOP                       (16u)
#define Blink_Timer_CMD_START                      (24u)

/* Status */
#define Blink_Timer_STATUS_DOWN                    (1u)
#define Blink_Timer_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   Blink_Timer_Init(void);
void   Blink_Timer_Enable(void);
void   Blink_Timer_Start(void);
void   Blink_Timer_Stop(void);

void   Blink_Timer_SetMode(uint32 mode);
void   Blink_Timer_SetCounterMode(uint32 counterMode);
void   Blink_Timer_SetPWMMode(uint32 modeMask);
void   Blink_Timer_SetQDMode(uint32 qdMode);

void   Blink_Timer_SetPrescaler(uint32 prescaler);
void   Blink_Timer_TriggerCommand(uint32 mask, uint32 command);
void   Blink_Timer_SetOneShot(uint32 oneShotEnable);
uint32 Blink_Timer_ReadStatus(void);

void   Blink_Timer_SetPWMSyncKill(uint32 syncKillEnable);
void   Blink_Timer_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   Blink_Timer_SetPWMDeadTime(uint32 deadTime);
void   Blink_Timer_SetPWMInvert(uint32 mask);

void   Blink_Timer_SetInterruptMode(uint32 interruptMask);
uint32 Blink_Timer_GetInterruptSourceMasked(void);
uint32 Blink_Timer_GetInterruptSource(void);
void   Blink_Timer_ClearInterrupt(uint32 interruptMask);
void   Blink_Timer_SetInterrupt(uint32 interruptMask);

void   Blink_Timer_WriteCounter(uint32 count);
uint32 Blink_Timer_ReadCounter(void);

uint32 Blink_Timer_ReadCapture(void);
uint32 Blink_Timer_ReadCaptureBuf(void);

void   Blink_Timer_WritePeriod(uint32 period);
uint32 Blink_Timer_ReadPeriod(void);
void   Blink_Timer_WritePeriodBuf(uint32 periodBuf);
uint32 Blink_Timer_ReadPeriodBuf(void);

void   Blink_Timer_WriteCompare(uint32 compare);
uint32 Blink_Timer_ReadCompare(void);
void   Blink_Timer_WriteCompareBuf(uint32 compareBuf);
uint32 Blink_Timer_ReadCompareBuf(void);

void   Blink_Timer_SetPeriodSwap(uint32 swapEnable);
void   Blink_Timer_SetCompareSwap(uint32 swapEnable);

void   Blink_Timer_SetCaptureMode(uint32 triggerMode);
void   Blink_Timer_SetReloadMode(uint32 triggerMode);
void   Blink_Timer_SetStartMode(uint32 triggerMode);
void   Blink_Timer_SetStopMode(uint32 triggerMode);
void   Blink_Timer_SetCountMode(uint32 triggerMode);

void   Blink_Timer_SaveConfig(void);
void   Blink_Timer_RestoreConfig(void);
void   Blink_Timer_Sleep(void);
void   Blink_Timer_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define Blink_Timer_BLOCK_CONTROL_REG              (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Blink_Timer_BLOCK_CONTROL_PTR              ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Blink_Timer_COMMAND_REG                    (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Blink_Timer_COMMAND_PTR                    ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Blink_Timer_INTRRUPT_CAUSE_REG             (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Blink_Timer_INTRRUPT_CAUSE_PTR             ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Blink_Timer_CONTROL_REG                    (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__CTRL )
#define Blink_Timer_CONTROL_PTR                    ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__CTRL )
#define Blink_Timer_STATUS_REG                     (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__STATUS )
#define Blink_Timer_STATUS_PTR                     ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__STATUS )
#define Blink_Timer_COUNTER_REG                    (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__COUNTER )
#define Blink_Timer_COUNTER_PTR                    ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__COUNTER )
#define Blink_Timer_COMP_CAP_REG                   (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__CC )
#define Blink_Timer_COMP_CAP_PTR                   ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__CC )
#define Blink_Timer_COMP_CAP_BUF_REG               (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__CC_BUFF )
#define Blink_Timer_COMP_CAP_BUF_PTR               ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__CC_BUFF )
#define Blink_Timer_PERIOD_REG                     (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__PERIOD )
#define Blink_Timer_PERIOD_PTR                     ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__PERIOD )
#define Blink_Timer_PERIOD_BUF_REG                 (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Blink_Timer_PERIOD_BUF_PTR                 ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Blink_Timer_TRIG_CONTROL0_REG              (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Blink_Timer_TRIG_CONTROL0_PTR              ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Blink_Timer_TRIG_CONTROL1_REG              (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Blink_Timer_TRIG_CONTROL1_PTR              ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Blink_Timer_TRIG_CONTROL2_REG              (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Blink_Timer_TRIG_CONTROL2_PTR              ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Blink_Timer_INTERRUPT_REQ_REG              (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__INTR )
#define Blink_Timer_INTERRUPT_REQ_PTR              ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__INTR )
#define Blink_Timer_INTERRUPT_SET_REG              (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__INTR_SET )
#define Blink_Timer_INTERRUPT_SET_PTR              ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__INTR_SET )
#define Blink_Timer_INTERRUPT_MASK_REG             (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__INTR_MASK )
#define Blink_Timer_INTERRUPT_MASK_PTR             ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__INTR_MASK )
#define Blink_Timer_INTERRUPT_MASKED_REG           (*(reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__INTR_MASKED )
#define Blink_Timer_INTERRUPT_MASKED_PTR           ( (reg32 *) Blink_Timer_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define Blink_Timer_MASK                           ((uint32)Blink_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define Blink_Timer_RELOAD_CC_SHIFT                (0u)
#define Blink_Timer_RELOAD_PERIOD_SHIFT            (1u)
#define Blink_Timer_PWM_SYNC_KILL_SHIFT            (2u)
#define Blink_Timer_PWM_STOP_KILL_SHIFT            (3u)
#define Blink_Timer_PRESCALER_SHIFT                (8u)
#define Blink_Timer_UPDOWN_SHIFT                   (16u)
#define Blink_Timer_ONESHOT_SHIFT                  (18u)
#define Blink_Timer_QUAD_MODE_SHIFT                (20u)
#define Blink_Timer_INV_OUT_SHIFT                  (20u)
#define Blink_Timer_INV_COMPL_OUT_SHIFT            (21u)
#define Blink_Timer_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define Blink_Timer_RELOAD_CC_MASK                 ((uint32)(Blink_Timer_1BIT_MASK        <<  \
                                                                            Blink_Timer_RELOAD_CC_SHIFT))
#define Blink_Timer_RELOAD_PERIOD_MASK             ((uint32)(Blink_Timer_1BIT_MASK        <<  \
                                                                            Blink_Timer_RELOAD_PERIOD_SHIFT))
#define Blink_Timer_PWM_SYNC_KILL_MASK             ((uint32)(Blink_Timer_1BIT_MASK        <<  \
                                                                            Blink_Timer_PWM_SYNC_KILL_SHIFT))
#define Blink_Timer_PWM_STOP_KILL_MASK             ((uint32)(Blink_Timer_1BIT_MASK        <<  \
                                                                            Blink_Timer_PWM_STOP_KILL_SHIFT))
#define Blink_Timer_PRESCALER_MASK                 ((uint32)(Blink_Timer_8BIT_MASK        <<  \
                                                                            Blink_Timer_PRESCALER_SHIFT))
#define Blink_Timer_UPDOWN_MASK                    ((uint32)(Blink_Timer_2BIT_MASK        <<  \
                                                                            Blink_Timer_UPDOWN_SHIFT))
#define Blink_Timer_ONESHOT_MASK                   ((uint32)(Blink_Timer_1BIT_MASK        <<  \
                                                                            Blink_Timer_ONESHOT_SHIFT))
#define Blink_Timer_QUAD_MODE_MASK                 ((uint32)(Blink_Timer_3BIT_MASK        <<  \
                                                                            Blink_Timer_QUAD_MODE_SHIFT))
#define Blink_Timer_INV_OUT_MASK                   ((uint32)(Blink_Timer_2BIT_MASK        <<  \
                                                                            Blink_Timer_INV_OUT_SHIFT))
#define Blink_Timer_MODE_MASK                      ((uint32)(Blink_Timer_3BIT_MASK        <<  \
                                                                            Blink_Timer_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define Blink_Timer_CAPTURE_SHIFT                  (0u)
#define Blink_Timer_COUNT_SHIFT                    (2u)
#define Blink_Timer_RELOAD_SHIFT                   (4u)
#define Blink_Timer_STOP_SHIFT                     (6u)
#define Blink_Timer_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define Blink_Timer_CAPTURE_MASK                   ((uint32)(Blink_Timer_2BIT_MASK        <<  \
                                                                  Blink_Timer_CAPTURE_SHIFT))
#define Blink_Timer_COUNT_MASK                     ((uint32)(Blink_Timer_2BIT_MASK        <<  \
                                                                  Blink_Timer_COUNT_SHIFT))
#define Blink_Timer_RELOAD_MASK                    ((uint32)(Blink_Timer_2BIT_MASK        <<  \
                                                                  Blink_Timer_RELOAD_SHIFT))
#define Blink_Timer_STOP_MASK                      ((uint32)(Blink_Timer_2BIT_MASK        <<  \
                                                                  Blink_Timer_STOP_SHIFT))
#define Blink_Timer_START_MASK                     ((uint32)(Blink_Timer_2BIT_MASK        <<  \
                                                                  Blink_Timer_START_SHIFT))

/* MASK */
#define Blink_Timer_1BIT_MASK                      ((uint32)0x01u)
#define Blink_Timer_2BIT_MASK                      ((uint32)0x03u)
#define Blink_Timer_3BIT_MASK                      ((uint32)0x07u)
#define Blink_Timer_6BIT_MASK                      ((uint32)0x3Fu)
#define Blink_Timer_8BIT_MASK                      ((uint32)0xFFu)
#define Blink_Timer_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define Blink_Timer_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define Blink_Timer_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(Blink_Timer_QUAD_ENCODING_MODES     << Blink_Timer_QUAD_MODE_SHIFT))       |\
         ((uint32)(Blink_Timer_CONFIG                  << Blink_Timer_MODE_SHIFT)))

#define Blink_Timer_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(Blink_Timer_PWM_STOP_EVENT          << Blink_Timer_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(Blink_Timer_PWM_OUT_INVERT          << Blink_Timer_INV_OUT_SHIFT))         |\
         ((uint32)(Blink_Timer_PWM_OUT_N_INVERT        << Blink_Timer_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(Blink_Timer_PWM_MODE                << Blink_Timer_MODE_SHIFT)))

#define Blink_Timer_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(Blink_Timer_PWM_RUN_MODE         << Blink_Timer_ONESHOT_SHIFT))
            
#define Blink_Timer_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(Blink_Timer_PWM_ALIGN            << Blink_Timer_UPDOWN_SHIFT))

#define Blink_Timer_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(Blink_Timer_PWM_KILL_EVENT      << Blink_Timer_PWM_SYNC_KILL_SHIFT))

#define Blink_Timer_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(Blink_Timer_PWM_DEAD_TIME_CYCLE  << Blink_Timer_PRESCALER_SHIFT))

#define Blink_Timer_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(Blink_Timer_PWM_PRESCALER        << Blink_Timer_PRESCALER_SHIFT))

#define Blink_Timer_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(Blink_Timer_TC_PRESCALER            << Blink_Timer_PRESCALER_SHIFT))       |\
         ((uint32)(Blink_Timer_TC_COUNTER_MODE         << Blink_Timer_UPDOWN_SHIFT))          |\
         ((uint32)(Blink_Timer_TC_RUN_MODE             << Blink_Timer_ONESHOT_SHIFT))         |\
         ((uint32)(Blink_Timer_TC_COMP_CAP_MODE        << Blink_Timer_MODE_SHIFT)))
        
#define Blink_Timer_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(Blink_Timer_QUAD_PHIA_SIGNAL_MODE   << Blink_Timer_COUNT_SHIFT))           |\
         ((uint32)(Blink_Timer_QUAD_INDEX_SIGNAL_MODE  << Blink_Timer_RELOAD_SHIFT))          |\
         ((uint32)(Blink_Timer_QUAD_STOP_SIGNAL_MODE   << Blink_Timer_STOP_SHIFT))            |\
         ((uint32)(Blink_Timer_QUAD_PHIB_SIGNAL_MODE   << Blink_Timer_START_SHIFT)))

#define Blink_Timer_PWM_SIGNALS_MODES                                                              \
        (((uint32)(Blink_Timer_PWM_SWITCH_SIGNAL_MODE  << Blink_Timer_CAPTURE_SHIFT))         |\
         ((uint32)(Blink_Timer_PWM_COUNT_SIGNAL_MODE   << Blink_Timer_COUNT_SHIFT))           |\
         ((uint32)(Blink_Timer_PWM_RELOAD_SIGNAL_MODE  << Blink_Timer_RELOAD_SHIFT))          |\
         ((uint32)(Blink_Timer_PWM_STOP_SIGNAL_MODE    << Blink_Timer_STOP_SHIFT))            |\
         ((uint32)(Blink_Timer_PWM_START_SIGNAL_MODE   << Blink_Timer_START_SHIFT)))

#define Blink_Timer_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(Blink_Timer_TC_CAPTURE_SIGNAL_MODE  << Blink_Timer_CAPTURE_SHIFT))         |\
         ((uint32)(Blink_Timer_TC_COUNT_SIGNAL_MODE    << Blink_Timer_COUNT_SHIFT))           |\
         ((uint32)(Blink_Timer_TC_RELOAD_SIGNAL_MODE   << Blink_Timer_RELOAD_SHIFT))          |\
         ((uint32)(Blink_Timer_TC_STOP_SIGNAL_MODE     << Blink_Timer_STOP_SHIFT))            |\
         ((uint32)(Blink_Timer_TC_START_SIGNAL_MODE    << Blink_Timer_START_SHIFT)))
        
#define Blink_Timer_TIMER_UPDOWN_CNT_USED                                                          \
                ((Blink_Timer__COUNT_UPDOWN0 == Blink_Timer_TC_COUNTER_MODE)                  ||\
                 (Blink_Timer__COUNT_UPDOWN1 == Blink_Timer_TC_COUNTER_MODE))

#define Blink_Timer_PWM_UPDOWN_CNT_USED                                                            \
                ((Blink_Timer__CENTER == Blink_Timer_PWM_ALIGN)                               ||\
                 (Blink_Timer__ASYMMETRIC == Blink_Timer_PWM_ALIGN))               
        
#define Blink_Timer_PWM_PR_INIT_VALUE              (1u)
#define Blink_Timer_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_Blink_Timer_H */

/* [] END OF FILE */
