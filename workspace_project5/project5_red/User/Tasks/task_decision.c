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
float current_x = 0, current_y = 0;
float error_x = 0, error_y = 0;
float yaw_delta_angle = 0, pitch_delta_angle = 0;


void start_to_target();
void current_to_next();
float point_to_angle(float point);
void go_to_point(float x, float y);

void start_to_target_k();
void current_to_next_k();
void task_test(void)
{
    //current_to_next();
}
void task_1(void)
{
    uint8_t i;
    for(i = 0; i < 15; ++i)
    {
        next_x = next_y = 0;
        current_x = OpenmvMessage.laser_x[0];
        current_y = OpenmvMessage.laser_y[0];
        current_to_next();
        delay_ms(100);
    }
    yaw_angle = pitch_angle = 0;
}
void task_2(void)
{
    task_1();
    int16_t x[4], y[4];
    x[0] = -75, y[0] = -78;
    x[1] =  80, y[1] = -75;
    x[2] =  77, y[2] =  79;
    x[3] = -74, y[3] =  76;

    go_to_point(x[0], y[0]);
    LED2_RGB(1, 0, 0);

    StateMachine.start_point[0]  = x[0];
    StateMachine.start_point[1]  = y[0];
    StateMachine.target_point[0] = x[1];
    StateMachine.target_point[1] = y[1];
    start_to_target();
    LED2_RGB(0, 1, 0);

    StateMachine.start_point[0]  = x[1];
    StateMachine.start_point[1]  = y[1];
    StateMachine.target_point[0] = x[2];
    StateMachine.target_point[1] = y[2];
    start_to_target();
    LED2_RGB(0, 0, 1);

    StateMachine.start_point[0]  = x[2];
    StateMachine.start_point[1]  = y[2];
    StateMachine.target_point[0] = x[3];
    StateMachine.target_point[1] = y[3];
    start_to_target();
    LED2_RGB(1, 1, 0);

    StateMachine.start_point[0]  = x[3];
    StateMachine.start_point[1]  = y[3];
    StateMachine.target_point[0] = x[0];
    StateMachine.target_point[1] = y[0];
    start_to_target();
    LED2_RGB(1, 0, 1);
}
void task_3(void)
{
    task_4();


}
void task_4(void)
{
    update_rect();
    LED2_RGB(1, 1, 1);
    next_x = rect_x[0];
    next_y = rect_y[0];
    uint8_t i;
    for(i = 0; i < 15; ++i)
    {
        current_x = OpenmvMessage.laser_x[0];
        current_y = OpenmvMessage.laser_y[0];
        current_to_next();
        delay_ms(100);
    }
    LED2_RGB(1, 0, 0);

    StateMachine.start_point[0]  = rect_x[0];
    StateMachine.start_point[1]  = rect_y[0];
    StateMachine.target_point[0] = rect_x[1];
    StateMachine.target_point[1] = rect_y[1];
    start_to_target();
    LED2_RGB(0, 1, 0);

    StateMachine.start_point[0]  = rect_x[1];
    StateMachine.start_point[1]  = rect_y[1];
    StateMachine.target_point[0] = rect_x[2];
    StateMachine.target_point[1] = rect_y[2];
    start_to_target();
    LED2_RGB(0, 0, 1);

    StateMachine.start_point[0]  = rect_x[2];
    StateMachine.start_point[1]  = rect_y[2];
    StateMachine.target_point[0] = rect_x[3];
    StateMachine.target_point[1] = rect_y[3];
    start_to_target();
    LED2_RGB(1, 1, 0);

    StateMachine.start_point[0]  = rect_x[3];
    StateMachine.start_point[1]  = rect_y[3];
    StateMachine.target_point[0] = rect_x[0];
    StateMachine.target_point[1] = rect_y[0];
    start_to_target();
    LED2_RGB(1, 0, 1);
}

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
        error_x = Limiter(OpenmvMessage.laser_x[0] - current_x, -6, 6);
        error_y = Limiter(OpenmvMessage.laser_y[0] - current_y, -6, 6);
        current_x += error_x;
        current_y += error_y;
        current_to_next();

        next_x += step_x;
        next_y += step_y;
        delay_ms(75);
    }
    error_x = Limiter(OpenmvMessage.laser_x[0] - current_x, -6, 6);
    error_y = Limiter(OpenmvMessage.laser_y[0] - current_y, -6, 6);
    current_x += error_x;
    current_y += error_y;
    current_to_next();
    
}
void start_to_target_k()
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
        current_to_next_k();
        current_x = next_x;
        current_y = next_y;

        delay_ms(50);
    }
}
void current_to_next()
{
    yaw_delta_angle     = point_to_angle(next_x) - point_to_angle(current_x);
    pitch_delta_angle   = point_to_angle(next_y) - point_to_angle(current_y);
    yaw_delta_angle    *= 0.5;
    pitch_delta_angle  *= 0.5;
    pulse_steering(yaw_delta_angle, pitch_delta_angle);
}
void current_to_next_k()
{
    yaw_delta_angle     = point_to_angle(next_x) - point_to_angle(current_x);
    pitch_delta_angle   = point_to_angle(next_y) - point_to_angle(current_y);
    pulse_steering(yaw_delta_angle, pitch_delta_angle);
}
void go_to_point(float x, float y)
{
    uint8_t i;
    next_x = x;
    next_y = y;
    for(i = 0; i < 15; ++i)
    {
        current_x = OpenmvMessage.laser_x[0];
        current_y = OpenmvMessage.laser_y[0];
        current_to_next();
        delay_ms(100);
    }
}
float point_to_angle(float point)
{
    return atan(point / 300) / PI * 180;
}
