#include "task_control.h"
#include "motor.h"
#include "openmv.h"
#include "laser.h"
#include "infoprint.h"
#include "key.h"
#include "keyboard.h"

float yaw_step = 0;
float pitch_step = 0;
float laser_angle = 0;
uint16_t times = 0;
bool main_control_flag;

void main_control()
{
    while(1)
    {
        if(main_control_flag == 0)
            break;
        
        if (time_count_flag)
        {
            mission_time_count++;
        }
        for(times = 0; times <= 160; ++times)
        {
            if(GetKey() == 3)
                return;
            if(yaw_pulse_count > 0)
            {
                GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN4);
                --yaw_pulse_count;
            }
            if(pitch_pulse_count > 0)
            {
                GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN4);
                --pitch_pulse_count;
            }
            delay_us(62);
            
            GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN4);
            GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN4);
            delay_us(62);

            if(yaw_pulse_count == 0 && pitch_pulse_count == 0)
            {
                break;
            }
        }

        main_control_flag = 0;
    }
}


/* Timer A3 IRQ Hander */
void TA3_0_IRQHandler(void)
{    
    Timer_A_clearCaptureCompareInterrupt(TIMER_A3_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0); //清除中断状态
    Timer_A_clearTimer(TIMER_A3_BASE);                                                      //清除定时器计数    
    
    main_control_flag = 1;
    
}
