#include "motor.h"
#include "task_control.h"
/*PWMÏÞ·ù*/
#define CCR0_MAX 999
#define CCR2_MAX 19999

float basic_speed = 0;                  // [-100,100]

float pitch_angle = 0;
float yaw_angle = 0;
int16_t pitch_pulse_count = 0;
int16_t yaw_pulse_count = 0;

// void step_motor_init()
// {
//     GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN4);   //yaw_pul
//     GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN5);   //yaw_dir
//     GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN4);   //pitch_pul
//     GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN5);   //pitch_dir
// }

void set_pulse_pitch(float angle)
{
    pitch_angle += angle;
    if(angle < 0)
    {
        angle = -angle;
		HAL_GPIO_WritePin(PD_GPIO_Port, PD_Pin, GPIO_PIN_SET);
    }
    else
    {
		HAL_GPIO_WritePin(PD_GPIO_Port, PD_Pin, GPIO_PIN_RESET);
    }
    pitch_pulse_count = angle / 360 * 6400;
}
void set_pulse_yaw(float angle)
{
    yaw_angle += angle;
    if(angle < 0)
    {
        angle = -angle;
		HAL_GPIO_WritePin(YD_GPIO_Port, YD_Pin, GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(YD_GPIO_Port, YD_Pin, GPIO_PIN_SET);
    }
    yaw_pulse_count = angle / 360 * 6400;
}
void pulse_steering(float a_y, float a_p)
{
//    if(fabs(a_y) > 10)
//	{
//		a_y = 0;
//		basic_speed++;
//	}
//        
//    if(fabs(a_p) > 10)
//	{
//		a_p = 0;
//		basic_speed++;
//	}
	
    set_pulse_yaw(a_y);
    set_pulse_pitch(a_p);

    while(pitch_pulse_count > 0 || yaw_pulse_count > 0)
    {
        main_control();
    }
}
