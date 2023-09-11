#include "task_control.h"
#include "motor.h"
#include "openmv.h"
#include "key.h"

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
            if(yaw_pulse_count > 0)
            {
				HAL_GPIO_WritePin(YP_GPIO_Port, YP_Pin, GPIO_PIN_SET);
                --yaw_pulse_count;
            }
            if(pitch_pulse_count > 0)
            {
				HAL_GPIO_WritePin(PP_GPIO_Port, PP_Pin, GPIO_PIN_SET);
                --pitch_pulse_count;
            }
            delay_us(62);
            HAL_GPIO_WritePin(YP_GPIO_Port, YP_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(PP_GPIO_Port, PP_Pin, GPIO_PIN_RESET);
            delay_us(62);

            if(yaw_pulse_count == 0 && pitch_pulse_count == 0)
            {
                break;
            }
        }

        main_control_flag = 0;
    }
}


void T2_IRQHandler(void)
{     
    main_control_flag = 1;
    
}
