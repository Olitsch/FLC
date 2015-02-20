/*******************************************************************************
* File Name: RC_Timer.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the RC_Timer
*  component
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

#include "RC_Timer.h"
#include "CyLib.h"

uint8 RC_Timer_initVar = 0u;


/*******************************************************************************
* Function Name: RC_Timer_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default RC_Timer configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (RC_Timer__QUAD == RC_Timer_CONFIG)
        RC_Timer_CONTROL_REG =
        (((uint32)(RC_Timer_QUAD_ENCODING_MODES     << RC_Timer_QUAD_MODE_SHIFT))       |
         ((uint32)(RC_Timer_CONFIG                  << RC_Timer_MODE_SHIFT)));
    #endif  /* (RC_Timer__QUAD == RC_Timer_CONFIG) */

    #if (RC_Timer__PWM_SEL == RC_Timer_CONFIG)
        RC_Timer_CONTROL_REG =
        (((uint32)(RC_Timer_PWM_STOP_EVENT          << RC_Timer_PWM_STOP_KILL_SHIFT))    |
         ((uint32)(RC_Timer_PWM_OUT_INVERT          << RC_Timer_INV_OUT_SHIFT))         |
         ((uint32)(RC_Timer_PWM_OUT_N_INVERT        << RC_Timer_INV_COMPL_OUT_SHIFT))     |
         ((uint32)(RC_Timer_PWM_MODE                << RC_Timer_MODE_SHIFT)));

        #if (RC_Timer__PWM_PR == RC_Timer_PWM_MODE)
            RC_Timer_CONTROL_REG |=
            ((uint32)(RC_Timer_PWM_RUN_MODE         << RC_Timer_ONESHOT_SHIFT));

            RC_Timer_WriteCounter(RC_Timer_PWM_PR_INIT_VALUE);
        #else
            RC_Timer_CONTROL_REG |=
            (((uint32)(RC_Timer_PWM_ALIGN           << RC_Timer_UPDOWN_SHIFT))          |
             ((uint32)(RC_Timer_PWM_KILL_EVENT      << RC_Timer_PWM_SYNC_KILL_SHIFT)));
        #endif  /* (RC_Timer__PWM_PR == RC_Timer_PWM_MODE) */

        #if (RC_Timer__PWM_DT == RC_Timer_PWM_MODE)
            RC_Timer_CONTROL_REG |=
            ((uint32)(RC_Timer_PWM_DEAD_TIME_CYCLE  << RC_Timer_PRESCALER_SHIFT));
        #endif  /* (RC_Timer__PWM_DT == RC_Timer_PWM_MODE) */

        #if (RC_Timer__PWM == RC_Timer_PWM_MODE)
            RC_Timer_CONTROL_REG |=
            ((uint32)RC_Timer_PWM_PRESCALER         << RC_Timer_PRESCALER_SHIFT);
        #endif  /* (RC_Timer__PWM == RC_Timer_PWM_MODE) */
    #endif  /* (RC_Timer__PWM_SEL == RC_Timer_CONFIG) */

    #if (RC_Timer__TIMER == RC_Timer_CONFIG)
        RC_Timer_CONTROL_REG =
        (((uint32)(RC_Timer_TC_PRESCALER            << RC_Timer_PRESCALER_SHIFT))   |
         ((uint32)(RC_Timer_TC_COUNTER_MODE         << RC_Timer_UPDOWN_SHIFT))      |
         ((uint32)(RC_Timer_TC_RUN_MODE             << RC_Timer_ONESHOT_SHIFT))     |
         ((uint32)(RC_Timer_TC_COMP_CAP_MODE        << RC_Timer_MODE_SHIFT)));
    #endif  /* (RC_Timer__TIMER == RC_Timer_CONFIG) */

    /* Set values from customizer to CTRL1 */
    #if (RC_Timer__QUAD == RC_Timer_CONFIG)
        RC_Timer_TRIG_CONTROL1_REG  =
        (((uint32)(RC_Timer_QUAD_PHIA_SIGNAL_MODE   << RC_Timer_COUNT_SHIFT))       |
         ((uint32)(RC_Timer_QUAD_INDEX_SIGNAL_MODE  << RC_Timer_RELOAD_SHIFT))      |
         ((uint32)(RC_Timer_QUAD_STOP_SIGNAL_MODE   << RC_Timer_STOP_SHIFT))        |
         ((uint32)(RC_Timer_QUAD_PHIB_SIGNAL_MODE   << RC_Timer_START_SHIFT)));
    #endif  /* (RC_Timer__QUAD == RC_Timer_CONFIG) */

    #if (RC_Timer__PWM_SEL == RC_Timer_CONFIG)
        RC_Timer_TRIG_CONTROL1_REG  =
        (((uint32)(RC_Timer_PWM_SWITCH_SIGNAL_MODE  << RC_Timer_CAPTURE_SHIFT))     |
         ((uint32)(RC_Timer_PWM_COUNT_SIGNAL_MODE   << RC_Timer_COUNT_SHIFT))       |
         ((uint32)(RC_Timer_PWM_RELOAD_SIGNAL_MODE  << RC_Timer_RELOAD_SHIFT))      |
         ((uint32)(RC_Timer_PWM_STOP_SIGNAL_MODE    << RC_Timer_STOP_SHIFT))        |
         ((uint32)(RC_Timer_PWM_START_SIGNAL_MODE   << RC_Timer_START_SHIFT)));
    #endif  /* (RC_Timer__PWM_SEL == RC_Timer_CONFIG) */

    #if (RC_Timer__TIMER == RC_Timer_CONFIG)
        RC_Timer_TRIG_CONTROL1_REG  =
        (((uint32)(RC_Timer_TC_CAPTURE_SIGNAL_MODE  << RC_Timer_CAPTURE_SHIFT))     |
         ((uint32)(RC_Timer_TC_COUNT_SIGNAL_MODE    << RC_Timer_COUNT_SHIFT))       |
         ((uint32)(RC_Timer_TC_RELOAD_SIGNAL_MODE   << RC_Timer_RELOAD_SHIFT))      |
         ((uint32)(RC_Timer_TC_STOP_SIGNAL_MODE     << RC_Timer_STOP_SHIFT))        |
         ((uint32)(RC_Timer_TC_START_SIGNAL_MODE    << RC_Timer_START_SHIFT)));
    #endif  /* (RC_Timer__TIMER == RC_Timer_CONFIG) */

    /* Set values from customizer to INTR */
    #if (RC_Timer__QUAD == RC_Timer_CONFIG)
        RC_Timer_SetInterruptMode(RC_Timer_QUAD_INTERRUPT_MASK);
    #endif  /* (RC_Timer__QUAD == RC_Timer_CONFIG) */

    #if (RC_Timer__PWM_SEL == RC_Timer_CONFIG)
        RC_Timer_SetInterruptMode(RC_Timer_PWM_INTERRUPT_MASK);
    #endif  /* (RC_Timer__PWM_SEL == RC_Timer_CONFIG) */

    #if (RC_Timer__TIMER == RC_Timer_CONFIG)
        RC_Timer_SetInterruptMode(RC_Timer_TC_INTERRUPT_MASK);
    #endif  /* (RC_Timer__TIMER == RC_Timer_CONFIG) */

    /* Set other values from customizer */
    #if (RC_Timer__TIMER == RC_Timer_CONFIG)
        RC_Timer_WritePeriod(RC_Timer_TC_PERIOD_VALUE );

        #if (RC_Timer__COUNT_DOWN == RC_Timer_TC_COUNTER_MODE)
            RC_Timer_WriteCounter(RC_Timer_TC_PERIOD_VALUE );
        #endif  /* (RC_Timer__COUNT_DOWN == RC_Timer_TC_COUNTER_MODE) */

        #if (RC_Timer__COMPARE == RC_Timer_TC_COMP_CAP_MODE)
            RC_Timer_WriteCompare(RC_Timer_TC_COMPARE_VALUE);

            #if (1u == RC_Timer_TC_COMPARE_SWAP)
                RC_Timer_SetCompareSwap(1u);
                RC_Timer_WriteCompareBuf(RC_Timer_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == RC_Timer_TC_COMPARE_SWAP) */
        #endif  /* (RC_Timer__COMPARE == RC_Timer_TC_COMP_CAP_MODE) */
    #endif  /* (RC_Timer__TIMER == RC_Timer_CONFIG) */

    #if (RC_Timer__PWM_SEL == RC_Timer_CONFIG)
        RC_Timer_WritePeriod(RC_Timer_PWM_PERIOD_VALUE );
        RC_Timer_WriteCompare(RC_Timer_PWM_COMPARE_VALUE);

        #if (1u == RC_Timer_PWM_COMPARE_SWAP)
            RC_Timer_SetCompareSwap(1u);
            RC_Timer_WriteCompareBuf(RC_Timer_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == RC_Timer_PWM_COMPARE_SWAP) */

        #if (1u == RC_Timer_PWM_PERIOD_SWAP)
            RC_Timer_SetPeriodSwap(1u);
            RC_Timer_WritePeriodBuf(RC_Timer_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == RC_Timer_PWM_PERIOD_SWAP) */

        /* Set values from customizer to CTRL2 */
        #if (RC_Timer__PWM_PR == RC_Timer_PWM_MODE)
            RC_Timer_TRIG_CONTROL2_REG =
                    (RC_Timer_CC_MATCH_NO_CHANGE    |
                    RC_Timer_OVERLOW_NO_CHANGE      |
                    RC_Timer_UNDERFLOW_NO_CHANGE);
        #else
            #if (RC_Timer__LEFT == RC_Timer_PWM_ALIGN)
                RC_Timer_TRIG_CONTROL2_REG = RC_Timer_PWM_MODE_LEFT;
            #endif  /* ( RC_Timer_PWM_LEFT == RC_Timer_PWM_ALIGN) */

            #if (RC_Timer__RIGHT == RC_Timer_PWM_ALIGN)
                RC_Timer_WriteCounter(RC_Timer_PWM_PERIOD_VALUE);
                RC_Timer_TRIG_CONTROL2_REG = RC_Timer_PWM_MODE_RIGHT;
            #endif  /* ( RC_Timer_PWM_RIGHT == RC_Timer_PWM_ALIGN) */

            #if (RC_Timer__CENTER == RC_Timer_PWM_ALIGN)
                RC_Timer_TRIG_CONTROL2_REG = RC_Timer_PWM_MODE_CENTER;
            #endif  /* ( RC_Timer_PWM_CENTER == RC_Timer_PWM_ALIGN) */

            #if (RC_Timer__ASYMMETRIC == RC_Timer_PWM_ALIGN)
                RC_Timer_TRIG_CONTROL2_REG = RC_Timer_PWM_MODE_ASYM;
            #endif  /* (RC_Timer__ASYMMETRIC == RC_Timer_PWM_ALIGN) */
        #endif  /* (RC_Timer__PWM_PR == RC_Timer_PWM_MODE) */
    #endif  /* (RC_Timer__PWM_SEL == RC_Timer_CONFIG) */
}


/*******************************************************************************
* Function Name: RC_Timer_Enable
********************************************************************************
*
* Summary:
*  Enables the RC_Timer.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    RC_Timer_BLOCK_CONTROL_REG |= RC_Timer_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (RC_Timer__PWM_SEL == RC_Timer_CONFIG)
        #if (0u == RC_Timer_PWM_START_SIGNAL_PRESENT)
            RC_Timer_TriggerCommand(RC_Timer_MASK, RC_Timer_CMD_START);
        #endif /* (0u == RC_Timer_PWM_START_SIGNAL_PRESENT) */
    #endif /* (RC_Timer__PWM_SEL == RC_Timer_CONFIG) */

    #if (RC_Timer__TIMER == RC_Timer_CONFIG)
        #if (0u == RC_Timer_TC_START_SIGNAL_PRESENT)
            RC_Timer_TriggerCommand(RC_Timer_MASK, RC_Timer_CMD_START);
        #endif /* (0u == RC_Timer_TC_START_SIGNAL_PRESENT) */
    #endif /* (RC_Timer__TIMER == RC_Timer_CONFIG) */
}


/*******************************************************************************
* Function Name: RC_Timer_Start
********************************************************************************
*
* Summary:
*  Initializes the RC_Timer with default customizer
*  values when called the first time and enables the RC_Timer.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  RC_Timer_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time RC_Timer_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the RC_Timer_Start() routine.
*
*******************************************************************************/
void RC_Timer_Start(void)
{
    if (0u == RC_Timer_initVar)
    {
        RC_Timer_Init();
        RC_Timer_initVar = 1u;
    }

    RC_Timer_Enable();
}


/*******************************************************************************
* Function Name: RC_Timer_Stop
********************************************************************************
*
* Summary:
*  Disables the RC_Timer.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_BLOCK_CONTROL_REG &= (uint32)~RC_Timer_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the RC_Timer. This function is used when
*  configured as a generic RC_Timer and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the RC_Timer to operate in
*   Values:
*   - RC_Timer_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - RC_Timer_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - RC_Timer_MODE_QUAD - Quadrature decoder
*         - RC_Timer_MODE_PWM - PWM
*         - RC_Timer_MODE_PWM_DT - PWM with dead time
*         - RC_Timer_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_CONTROL_REG &= (uint32)~RC_Timer_MODE_MASK;
    RC_Timer_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - RC_Timer_MODE_X1 - Counts on phi 1 rising
*         - RC_Timer_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - RC_Timer_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_CONTROL_REG &= (uint32)~RC_Timer_QUAD_MODE_MASK;
    RC_Timer_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - RC_Timer_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - RC_Timer_PRESCALE_DIVBY2    - Divide by 2
*         - RC_Timer_PRESCALE_DIVBY4    - Divide by 4
*         - RC_Timer_PRESCALE_DIVBY8    - Divide by 8
*         - RC_Timer_PRESCALE_DIVBY16   - Divide by 16
*         - RC_Timer_PRESCALE_DIVBY32   - Divide by 32
*         - RC_Timer_PRESCALE_DIVBY64   - Divide by 64
*         - RC_Timer_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_CONTROL_REG &= (uint32)~RC_Timer_PRESCALER_MASK;
    RC_Timer_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the RC_Timer runs
*  continuously or stops when terminal count is reached.  By default the
*  RC_Timer operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_CONTROL_REG &= (uint32)~RC_Timer_ONESHOT_MASK;
    RC_Timer_CONTROL_REG |= ((uint32)((oneShotEnable & RC_Timer_1BIT_MASK) <<
                                                               RC_Timer_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetPWMMode(uint32 modeMask)
{
    RC_Timer_TRIG_CONTROL2_REG = (modeMask & RC_Timer_6BIT_MASK);
}



/*******************************************************************************
* Function Name: RC_Timer_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_CONTROL_REG &= (uint32)~RC_Timer_PWM_SYNC_KILL_MASK;
    RC_Timer_CONTROL_REG |= ((uint32)((syncKillEnable & RC_Timer_1BIT_MASK)  <<
                                               RC_Timer_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_CONTROL_REG &= (uint32)~RC_Timer_PWM_STOP_KILL_MASK;
    RC_Timer_CONTROL_REG |= ((uint32)((stopOnKillEnable & RC_Timer_1BIT_MASK)  <<
                                                         RC_Timer_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_CONTROL_REG &= (uint32)~RC_Timer_PRESCALER_MASK;
    RC_Timer_CONTROL_REG |= ((uint32)((deadTime & RC_Timer_8BIT_MASK) <<
                                                          RC_Timer_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - RC_Timer_INVERT_LINE   - Inverts the line output
*         - RC_Timer_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_CONTROL_REG &= (uint32)~RC_Timer_INV_OUT_MASK;
    RC_Timer_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: RC_Timer_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_WriteCounter(uint32 count)
{
    RC_Timer_COUNTER_REG = (count & RC_Timer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: RC_Timer_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 RC_Timer_ReadCounter(void)
{
    return (RC_Timer_COUNTER_REG & RC_Timer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: RC_Timer_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - RC_Timer_COUNT_UP       - Counts up
*     - RC_Timer_COUNT_DOWN     - Counts down
*     - RC_Timer_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - RC_Timer_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_CONTROL_REG &= (uint32)~RC_Timer_UPDOWN_MASK;
    RC_Timer_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_WritePeriod(uint32 period)
{
    RC_Timer_PERIOD_REG = (period & RC_Timer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: RC_Timer_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 RC_Timer_ReadPeriod(void)
{
    return (RC_Timer_PERIOD_REG & RC_Timer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: RC_Timer_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_CONTROL_REG &= (uint32)~RC_Timer_RELOAD_CC_MASK;
    RC_Timer_CONTROL_REG |= (swapEnable & RC_Timer_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_WritePeriodBuf(uint32 periodBuf)
{
    RC_Timer_PERIOD_BUF_REG = (periodBuf & RC_Timer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: RC_Timer_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 RC_Timer_ReadPeriodBuf(void)
{
    return (RC_Timer_PERIOD_BUF_REG & RC_Timer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: RC_Timer_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_CONTROL_REG &= (uint32)~RC_Timer_RELOAD_PERIOD_MASK;
    RC_Timer_CONTROL_REG |= ((uint32)((swapEnable & RC_Timer_1BIT_MASK) <<
                                                            RC_Timer_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_WriteCompare(uint32 compare)
{
    #if (RC_Timer_CY_TCPWM_V2)
        uint32 currentMode;
    #endif /* (RC_Timer_CY_TCPWM_V2) */

    #if (RC_Timer_CY_TCPWM_V2)
        currentMode = ((RC_Timer_CONTROL_REG & RC_Timer_UPDOWN_MASK) >> RC_Timer_UPDOWN_SHIFT);

        if (RC_Timer__COUNT_DOWN == currentMode)
        {
            RC_Timer_COMP_CAP_REG = ((compare + 1u) & RC_Timer_16BIT_MASK);
        }
        else if (RC_Timer__COUNT_UP == currentMode)
        {
            RC_Timer_COMP_CAP_REG = ((compare - 1u) & RC_Timer_16BIT_MASK);
        }
        else
        {
            RC_Timer_COMP_CAP_REG = (compare & RC_Timer_16BIT_MASK);
        }
    #else
        RC_Timer_COMP_CAP_REG = (compare & RC_Timer_16BIT_MASK);
    #endif /* (RC_Timer_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: RC_Timer_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
*******************************************************************************/
uint32 RC_Timer_ReadCompare(void)
{
    #if (RC_Timer_CY_TCPWM_V2)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (RC_Timer_CY_TCPWM_V2) */

    #if (RC_Timer_CY_TCPWM_V2)
        currentMode = ((RC_Timer_CONTROL_REG & RC_Timer_UPDOWN_MASK) >> RC_Timer_UPDOWN_SHIFT);

        if (RC_Timer__COUNT_DOWN == currentMode)
        {
            regVal = ((RC_Timer_COMP_CAP_REG - 1u) & RC_Timer_16BIT_MASK);
        }
        else if (RC_Timer__COUNT_UP == currentMode)
        {
            regVal = ((RC_Timer_COMP_CAP_REG + 1u) & RC_Timer_16BIT_MASK);
        }
        else
        {
            regVal = (RC_Timer_COMP_CAP_REG & RC_Timer_16BIT_MASK);
        }
        return (regVal);
    #else
        return (RC_Timer_COMP_CAP_REG & RC_Timer_16BIT_MASK);
    #endif /* (RC_Timer_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: RC_Timer_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_WriteCompareBuf(uint32 compareBuf)
{
    #if (RC_Timer_CY_TCPWM_V2)
        uint32 currentMode;
    #endif /* (RC_Timer_CY_TCPWM_V2) */

    #if (RC_Timer_CY_TCPWM_V2)
        currentMode = ((RC_Timer_CONTROL_REG & RC_Timer_UPDOWN_MASK) >> RC_Timer_UPDOWN_SHIFT);

        if (RC_Timer__COUNT_DOWN == currentMode)
        {
            RC_Timer_COMP_CAP_BUF_REG = ((compareBuf + 1u) & RC_Timer_16BIT_MASK);
        }
        else if (RC_Timer__COUNT_UP == currentMode)
        {
            RC_Timer_COMP_CAP_BUF_REG = ((compareBuf - 1u) & RC_Timer_16BIT_MASK);
        }
        else
        {
            RC_Timer_COMP_CAP_BUF_REG = (compareBuf & RC_Timer_16BIT_MASK);
        }
    #else
        RC_Timer_COMP_CAP_BUF_REG = (compareBuf & RC_Timer_16BIT_MASK);
    #endif /* (RC_Timer_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: RC_Timer_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
*******************************************************************************/
uint32 RC_Timer_ReadCompareBuf(void)
{
    #if (RC_Timer_CY_TCPWM_V2)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (RC_Timer_CY_TCPWM_V2) */

    #if (RC_Timer_CY_TCPWM_V2)
        currentMode = ((RC_Timer_CONTROL_REG & RC_Timer_UPDOWN_MASK) >> RC_Timer_UPDOWN_SHIFT);

        if (RC_Timer__COUNT_DOWN == currentMode)
        {
            regVal = ((RC_Timer_COMP_CAP_BUF_REG - 1u) & RC_Timer_16BIT_MASK);
        }
        else if (RC_Timer__COUNT_UP == currentMode)
        {
            regVal = ((RC_Timer_COMP_CAP_BUF_REG + 1u) & RC_Timer_16BIT_MASK);
        }
        else
        {
            regVal = (RC_Timer_COMP_CAP_BUF_REG & RC_Timer_16BIT_MASK);
        }
        return (regVal);
    #else
        return (RC_Timer_COMP_CAP_BUF_REG & RC_Timer_16BIT_MASK);
    #endif /* (RC_Timer_CY_TCPWM_V2) */
}


/*******************************************************************************
* Function Name: RC_Timer_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 RC_Timer_ReadCapture(void)
{
    return (RC_Timer_COMP_CAP_REG & RC_Timer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: RC_Timer_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 RC_Timer_ReadCaptureBuf(void)
{
    return (RC_Timer_COMP_CAP_BUF_REG & RC_Timer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: RC_Timer_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - RC_Timer_TRIG_LEVEL     - Level
*     - RC_Timer_TRIG_RISING    - Rising edge
*     - RC_Timer_TRIG_FALLING   - Falling edge
*     - RC_Timer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_TRIG_CONTROL1_REG &= (uint32)~RC_Timer_CAPTURE_MASK;
    RC_Timer_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - RC_Timer_TRIG_LEVEL     - Level
*     - RC_Timer_TRIG_RISING    - Rising edge
*     - RC_Timer_TRIG_FALLING   - Falling edge
*     - RC_Timer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_TRIG_CONTROL1_REG &= (uint32)~RC_Timer_RELOAD_MASK;
    RC_Timer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << RC_Timer_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - RC_Timer_TRIG_LEVEL     - Level
*     - RC_Timer_TRIG_RISING    - Rising edge
*     - RC_Timer_TRIG_FALLING   - Falling edge
*     - RC_Timer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_TRIG_CONTROL1_REG &= (uint32)~RC_Timer_START_MASK;
    RC_Timer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << RC_Timer_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - RC_Timer_TRIG_LEVEL     - Level
*     - RC_Timer_TRIG_RISING    - Rising edge
*     - RC_Timer_TRIG_FALLING   - Falling edge
*     - RC_Timer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_TRIG_CONTROL1_REG &= (uint32)~RC_Timer_STOP_MASK;
    RC_Timer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << RC_Timer_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - RC_Timer_TRIG_LEVEL     - Level
*     - RC_Timer_TRIG_RISING    - Rising edge
*     - RC_Timer_TRIG_FALLING   - Falling edge
*     - RC_Timer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_TRIG_CONTROL1_REG &= (uint32)~RC_Timer_COUNT_MASK;
    RC_Timer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << RC_Timer_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - RC_Timer_CMD_CAPTURE    - Trigger Capture command
*     - RC_Timer_CMD_RELOAD     - Trigger Reload command
*     - RC_Timer_CMD_STOP       - Trigger Stop command
*     - RC_Timer_CMD_START      - Trigger Start command
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    RC_Timer_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: RC_Timer_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the RC_Timer.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - RC_Timer_STATUS_DOWN    - Set if counting down
*     - RC_Timer_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 RC_Timer_ReadStatus(void)
{
    return ((RC_Timer_STATUS_REG >> RC_Timer_RUNNING_STATUS_SHIFT) |
            (RC_Timer_STATUS_REG & RC_Timer_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: RC_Timer_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - RC_Timer_INTR_MASK_TC       - Terminal count mask
*     - RC_Timer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetInterruptMode(uint32 interruptMask)
{
    RC_Timer_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: RC_Timer_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - RC_Timer_INTR_MASK_TC       - Terminal count mask
*     - RC_Timer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 RC_Timer_GetInterruptSourceMasked(void)
{
    return (RC_Timer_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: RC_Timer_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - RC_Timer_INTR_MASK_TC       - Terminal count mask
*     - RC_Timer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 RC_Timer_GetInterruptSource(void)
{
    return (RC_Timer_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: RC_Timer_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - RC_Timer_INTR_MASK_TC       - Terminal count mask
*     - RC_Timer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_ClearInterrupt(uint32 interruptMask)
{
    RC_Timer_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: RC_Timer_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - RC_Timer_INTR_MASK_TC       - Terminal count mask
*     - RC_Timer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void RC_Timer_SetInterrupt(uint32 interruptMask)
{
    RC_Timer_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */