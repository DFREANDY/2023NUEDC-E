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


void start_to_target();
void current_to_target(uint8_t current, uint8_t target);

void go_to_next();
void pulse_to_next();

float point_to_angle_yaw(float x);
float point_to_angle_pitch(float y);

void calculate_revise();

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
        if(yaw_angle > 45)
            t = -1;
        else if(yaw_angle < -45)
            t = 1;
        pulse_steering(t, 0);
    }

    while(1)
    {
        if(OpenmvMessage.laser_x[0] != 125 && OpenmvMessage.laser_x[1] != 125)
        {
            dx = OpenmvMessage.laser_x[0] - OpenmvMessage.laser_x[1];
            dy = OpenmvMessage.laser_y[0] - OpenmvMessage.laser_y[1];
            if(abs(dx) < 12 && abs(dy) < 12)
            {
                BUZZER_ON;
                LED2_RGB(1, 1, 1);
            }
            else
            {
                BUZZER_OFF;
                LED2_RGB(0, 0, 0);
            }
            yaw_delta_angle     = -0.3 * point_to_angle_yaw(dx);
            pitch_delta_angle   =  0.3 * point_to_angle_pitch(dy);
            pulse_steering(yaw_delta_angle, pitch_delta_angle);

        }
        delay_ms(100);
    }

}
void task_2(void)
{

}
void task_3(void)
{

}
void task_4(void)
{
//    while(rect_x[0] == 0)
//        openmv_request_data(1);
//    while(OpenmvMessage.laser_x[0] == 0)
//        openmv_request_data(2);

    yaw_angle = point_to_angle_yaw(rect_x[0]) ;
    pitch_angle = point_to_angle_pitch(rect_y[0]) ;
    set_steering();
    LED2_RGB(1, 1, 0);
    delay_ms(1000);
    delay_ms(1000);
    delay_ms(1000);
    LED2_RGB(0, 1, 0);


    StateMachine.start_point[0]  = rect_x[0];
    StateMachine.start_point[1]  = rect_y[0];
    StateMachine.target_point[0] = rect_x[1];
    StateMachine.target_point[1] = rect_y[1];
    start_to_target();
    delay_ms(1000);
    delay_ms(1000);
    delay_ms(1000);
    StateMachine.start_point[0]  = rect_x[1];
    StateMachine.start_point[1]  = rect_y[1];
    StateMachine.target_point[0] = rect_x[2];
    StateMachine.target_point[1] = rect_y[2];
    start_to_target();
    delay_ms(1000);
    delay_ms(1000);
    delay_ms(1000);
    StateMachine.start_point[0]  = rect_x[2];
    StateMachine.start_point[1]  = rect_y[2];
    StateMachine.target_point[0] = rect_x[3];
    StateMachine.target_point[1] = rect_y[3];
    start_to_target();
    delay_ms(1000);
    delay_ms(1000);
    delay_ms(1000);
    StateMachine.start_point[0]  = rect_x[3];
    StateMachine.start_point[1]  = rect_y[3];
    StateMachine.target_point[0] = rect_x[0];
    StateMachine.target_point[1] = rect_y[0];
    start_to_target();
    delay_ms(1000);
    delay_ms(1000);
    delay_ms(1000);
}
void task_5(void)
{
    while(1)
    {
        go_to_next();
        //calculate_revise();
        delay_ms(1000);
    }
}
void task_6(void);

void start_to_target()
{
    dx = StateMachine.target_point[0] - StateMachine.start_point[0];
    dy = StateMachine.target_point[1] - StateMachine.start_point[1];
    
    step_x = dx / 70.0;
    step_y = dy / 70.0; 
    next_x = StateMachine.start_point[0];
    next_y = StateMachine.start_point[1];
    for(StateMachine.task_progress = 0; StateMachine.task_progress < 70; ++StateMachine.task_progress)
    {       
        next_x += step_x;
        next_y += step_y;
        go_to_next();
        calculate_revise();
        delay_ms(1000);
    }
    

}
void current_to_target(uint8_t current, uint8_t target)
{
    next_x = rect_x[current];
    next_y = rect_y[current];

    for(StateMachine.task_progress = 0; StateMachine.task_progress < 70; ++StateMachine.task_progress)
    {
        dx = rect_x[target] - next_x;
        dy = rect_y[target] - next_y;

        step_x = dx / (70.0 - StateMachine.task_progress);
        step_y = dy / (70.0 - StateMachine.task_progress);

        next_x += step_x;
        next_y += step_y;
        go_to_next();
        //calculate_revise();
        delay_ms(100);
    }

}
void go_to_next()
{
    yaw_angle = point_to_angle_yaw(next_x) + yaw_revise ;
    pitch_angle = point_to_angle_pitch(next_y) + pitch_revise ;
    set_steering();
}
void pulse_to_next()
{
    yaw_delta_angle = point_to_angle_yaw(next_x - current_x) ;
    pitch_delta_angle = point_to_angle_pitch(next_y - current_y) ;
    pulse_steering(yaw_delta_angle, pitch_delta_angle);
    current_x = next_x;
    current_y = next_y;
}
float point_to_angle_yaw(float x)
{
    return -atan(x / 300) / PI * 180;
}
float point_to_angle_pitch(float y)
{
    return atan(y / 300) / PI * 180;
}
void calculate_revise()
{
    if(OpenmvMessage.laser_x[0] != 0)
    {
//        while(1)
//        {
//            LED2_RGB(1, 1, 0);
//        }
        yaw_revise += point_to_angle_yaw(next_x - OpenmvMessage.laser_x[0]) ;
    }
    if(OpenmvMessage.laser_x[0] != 0)
    {
//        while(1)
//        {
//            LED2_RGB(1, 0, 1);
//        }
        pitch_revise += point_to_angle_pitch(next_y - OpenmvMessage.laser_y[0]);
    }
    yaw_revise = Limiter(yaw_revise, -3, 3);
    pitch_revise = Limiter(pitch_revise, -3, 3);
}
