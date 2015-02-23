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

    uint8_t lightOff = 0;
uint8_t pwm_light_adj[4] = {0x10, 0x10, 0x10, 0x10};
static const uint8 CYCODE pwm_light_init[4] = {0x10, 0x10, 0x10, 0x10};

uint8_t channelValue[8] = {0, 0, 0, 0, 0, 0, 0, 0};

extern int16_t channelTime[8];

extern uint32_t seconds;
extern uint16_t counter_off_millis;
extern uint16_t counter_setup_millis;

uint16_t flashTime_StrobeLight = 60;
uint16_t pauseTime_StrobeLight = 60;
uint16_t flashTime_CollisionLight = 60;

int main()
{
    uint8_t i;
    uint8_t uartByte;
    uint8_t lightAdj = 0;

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
    
    for (i=0;i<4;i++)
        pwm_light[i] = pwm_light_init[i];
 
    
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
            
            if (counter_setup_millis > 1000)
            {
                Em_EEPROM_1_Write(pwm_light_adj,pwm_light_init,4);
                lightAdj = (lightAdj + 1) % 4;
                for (i=0;i<4;i++)       //Turn all lights off on after 2s of stick in right-low corner
                {
                    pwm_light[i] = 0;
                }
                lightOff = 1;
                pwm_light[lightAdj] = pwm_light_adj[lightAdj];
                counter_off_millis = 0;
                counter_setup_millis = 0;
            }
                
            if (counter_off_millis == 1500 && lightOff == 1) //Turn all lights back on after 1s
            {
                lightOff = 0;
                counter_off_millis = 0;
            }
            
            pwm_light_adj[lightAdj] = channelValue[ch1];
        }
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
