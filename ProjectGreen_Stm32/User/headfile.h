#ifndef __HEADFILE_H
#define __HEADFILE_H

#include "delay.h"
#include <stdint.h>
#include <stdbool.h>
#include "main.h"

#define mySgn(val)           ((val) < 0 ? -1 : ((val) > 0 ? 1 : 0))
#define PI 3.14159f

#define Limiter(val,min,max) ((val)<(min)?(min):((val)>(max)?(max):(val)))

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

extern state_machine_t StateMachine;

#endif
