#include "task_decision.h"
#include "motor.h"
#include "task_control.h"
#include "openmv.h"
#include "led.h"
#include "math.h"
#define STEERING_STEP 0.5

int16_t dx = 0, dy = 0;
float next_x = 0, next_y = 0;
float step_x = 0, step_y = 0;
float yaw_revise = 0, pitch_revise = 0;
float current_x = 0, current_y = 0;
float yaw_delta_angle = 0, pitch_delta_angle = 0;

float point_to_angle_yaw(float x);
float point_to_angle_pitch(float y);


void task_test(void)
{
    //yaw_delta_angle = point_to_angle_yaw(dx);
    //pitch_delta_angle = point_to_angle_pitch(dy);

    pulse_steering(yaw_delta_angle, pitch_delta_angle);
    dx = dy = 0;
}
void task_1(void)
{
    int8_t t = 1;
    while(OpenmvMessage.laser_x[1] == 125)
    {
		uart_receive();
        if(yaw_angle > 45)
            t = -1;
        else if(yaw_angle < -45)
            t = 1;
        pulse_steering(t, 0);
    }

    while(1)
    {
		uart_receive();
        if(OpenmvMessage.laser_x[0] != 125 && OpenmvMessage.laser_x[1] != 125)
        {
            dx = OpenmvMessage.laser_x[0] - OpenmvMessage.laser_x[1];
            dy = OpenmvMessage.laser_y[0] - OpenmvMessage.laser_y[1];
//            if(abs(dx) < 12 && abs(dy) < 12)
//            {
//                BUZZER_ON;
//                LED2_RGB(1, 1, 1);
//            }
//            else
//            {
//                BUZZER_OFF;
//                LED2_RGB(0, 0, 0);
//            }
            yaw_delta_angle     = -0.3 * point_to_angle_yaw(dx);
            pitch_delta_angle   =  0.3 * point_to_angle_pitch(dy);
            pulse_steering(yaw_delta_angle, pitch_delta_angle);

        }
		LED1_ON;
        delay_ms(50);
		LED1_OFF;
		delay_ms(50);
    }

}
float point_to_angle_yaw(float x)
{
    return -atan(x / 300) / PI * 180;
}
float point_to_angle_pitch(float y)
{
    return atan(y / 300) / PI * 180;
}
