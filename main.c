/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
enum lights {strobe = 0, collision, navigation, landing};
enum chanels {ch1 = 0, ch2, ch3, ch4, ch5, ch6, ch7, ch8};

uint8_t pwm_light[4] = {0x10, 0x10, 0x10, 0x10};


uint8_t pwm_light_adj[4] = {0x10, 0x10, 0x10, 0x10};

uint8_t channelValue[8] = {0, 0, 0, 0, 0, 0, 0, 0};

extern int16_t channelTime[8];

uint16_t flashTime_StrobeLight = 60;
uint16_t pauseTime_StrobeLight = 60;
uint16_t flashTime_CollisionLight = 60;

int main()
{
    uint8_t i;
    uint8_t uartByte;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    CyGlobalIntEnable;
    PWM_Timer_Start();
    Blink_Timer_Start();
    RC_Timer_Start();
    UART_1_Start();
    UART_2_Start();
    isr_uart_Start();
    isr_pwm_Start();
    isr_RC_Start();
    isr_blink_Start();
 
    
    for(;;)
    {
        uartByte = UART_2_UartGetChar();
        if (uartByte != 0)
        {
            for (i=0;i<4;i++)
             pwm_light_adj[i] = uartByte;
        }else
        {
            for (i=0;i<8;i++)
            {
                if (channelTime[i] < 1000)
                {
                    channelValue[i] = 0;
                }else if (channelTime[i] > 2000)
                {
                    channelValue[i] = 255;
                }else
                {
                    channelValue[i] = (uint8_t) (((channelTime[i] - 1000) * 255) / 1000);
                }  
            }
            
            
            for (i=0;i<4;i++)
             pwm_light_adj[i] = channelValue[ch6];
        }
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
