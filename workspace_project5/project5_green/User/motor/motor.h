#ifndef __MOTOR_H
#define __MOTOR_H
#include "headfile.h"

extern float basic_speed;
extern float turn_diff[10];

extern float pitch_angle;
extern float yaw_angle;
extern int16_t pitch_pulse_count;
extern int16_t yaw_pulse_count;

void set_steering();
void step_motor_init();
void set_pulse_pitch(float angle);
void set_pulse_yaw(float angle);
void pulse_steering(float a_y, float a_p);
#endif
