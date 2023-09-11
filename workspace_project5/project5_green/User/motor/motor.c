#include "motor.h"
#include "pid.h"
#include "task_control.h"
#include "keyboard.h"
/*PWMÏÞ·ù*/
#define CCR0_MAX 999
#define CCR2_MAX 19999

float basic_speed;                  // [-100,100]

float pitch_angle = 0;
float yaw_angle = 0;
int16_t pitch_pulse_count = 0;
int16_t yaw_pulse_count = 0;

void set_pitch(float angle)
{
    angle += 90;
    angle = Limiter(angle, 45, 135);
    float duty_ratio = angle / 18 + 2.5;
    uint16_t ccr = duty_ratio * CCR2_MAX / 100;
    MAP_Timer_A_setCompareValue(TIMER_A2_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_3, ccr);     //P6.6
}

void set_yaw(float angle)
{
    angle += 90;
    angle = Limiter(angle, 45, 135);
    float duty_ratio = angle / 18 + 2.5;
    uint16_t ccr = duty_ratio * CCR2_MAX / 100;
    MAP_Timer_A_setCompareValue(TIMER_A2_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_4, ccr);     //P6.7
}
void set_steering()
{
    if(GetKey() == 3)
        return;
    yaw_angle = Limiter(yaw_angle, -20, 18);
    pitch_angle = Limiter(pitch_angle, -20, 18);
    
    set_yaw(yaw_angle);
    set_pitch(pitch_angle);
}

void step_motor_init()
{
    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN4);   //yaw_pul
    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN5);   //yaw_dir
    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN4);   //pitch_pul
    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN5);   //pitch_dir
}

void set_pulse_pitch(float angle)
{
    pitch_angle += angle;
    if(angle < 0)
    {
        angle = -angle;
        GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN5);
    }
    else
    {
        GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN5);
    }
    pitch_pulse_count = angle / 360 * 6400;
}
void set_pulse_yaw(float angle)
{
    yaw_angle += angle;
    if(angle < 0)
    {
        angle = -angle;
        GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN5);
    }
    else
    {
        GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN5);
    }
    yaw_pulse_count = angle / 360 * 6400;
}
void pulse_steering(float a_y, float a_p)
{
    if(fabs(a_y) > 10)
        a_y = 0;
    if(fabs(a_p) > 10)
        a_p = 0;
    set_pulse_yaw(a_y);
    set_pulse_pitch(a_p);

    while(pitch_pulse_count > 0 || yaw_pulse_count > 0)
    {
        main_control();
    }
}
