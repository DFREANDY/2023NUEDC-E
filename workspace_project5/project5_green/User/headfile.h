#ifndef __HEADFILE_H
#define __HEADFILE_H

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "delay.h"
#include "clock.h"
#include <stdint.h>
#include <stdbool.h>

#include "pid.h"


#define mySgn(val)           ((val) < 0 ? -1 : ((val) > 0 ? 1 : 0))
#define PI 3.14159f

#define PITCH_OFFSET    0
#define YAW_OFFSET      0


typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef int16_t int16;
typedef int32_t int32;

typedef enum SIGN_E
{
    SIGN_OFF,
    SIGN_ON,
    SIGN_BLINK
} sigh_enum;

typedef struct
{
	uint8_t state;				
	uint8_t task_mode;          
	uint8_t task_progress;
    int8_t  start_point[2];
    int8_t  target_point[2];

    sigh_enum led_state;
    sigh_enum buzzer_state;

    float input_speed;

} state_machine_t;

extern int32_t time_count_flag;
extern int32_t mission_time_count;

extern pid_t pid_lb;
extern pid_t pid_rb;
extern pid_t pid_lf;
extern pid_t pid_rf;
extern pid_t pid_diff;
extern pid_t pid_pitch;
extern pid_t pid_yaw;

extern state_machine_t StateMachine;

#endif
