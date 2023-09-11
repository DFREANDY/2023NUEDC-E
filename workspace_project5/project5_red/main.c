#include "headfile.h"
#include "delay.h"
#include "clock.h"

#include "key.h"
#include "led.h"
#include "keyboard.h"

#include "task_decision.h"

#include "motor.h"
#include "timer.h"
#include "pid.h"

#include "openmv.h"
#include "laser.h"
#include "oled.h"

#include "infoprint.h"

int32_t time_count_flag;
int32_t mission_time_count;

pid_t pid_pitch;
pid_t pid_yaw;

state_machine_t StateMachine;

uint8_t pointer = 0;

void clear_statemachine();
void clear_openmvmessage();
void steering_init();

int main(void)
{
    /* Stop Watchdog  */
    MAP_WDT_A_holdTimer();
    /*时钟初始化*/
    CLOCK_Init();
    delay_init();
    /*LED初始化*/
    LED_Init();
    /*按键初始化*/
    KEY_Init();
    KeyboardInit();
    /*步进电机初始化*/
    step_motor_init();
    /*定时器初始化*/
    TimA2_Init(20000 - 1, 48);
    TA3_IT_INIT();
    //--------------------------------------------------usart--------------------------------------------------
    Openmv_Init();
    //Laser_Init();
    /*开启总中断*/
    MAP_Interrupt_enableMaster();

    //--------------------------------------------------main--------------------------------------------------

//    while(1)
//    {
//        if(KEY_Input() == KEY1_PRESSED)
//        {
//            pulse_steering(10, 0);
//        }
//        else
//        {
//            pulse_steering(-10, 0);
//        }
//        delay_ms(100);
//
//    }

//    while (1)
//    {
//        clear_statemachine();
//        clear_openmvmessage();
//        steering_init();
//
//        LED1_ON;
//        LED2_RGB(1, 0, 0);
//        if(KEY_Input());
//        LED2_RGB(0, 1, 0);
//        LED1_OFF;
//
//        StateMachine.state = 1;
//        StateMachine.task_mode = pointer + 1;
//
//        task_1();
//
//        delay_ms(1000);
//        delay_ms(1000);
//        delay_ms(1000);
//        BUZZER_OFF;
//
//    }
    


   while (1)
   {
       info_print_mainmenu(pointer);
       while (KEY_Input() == KEY1_PRESSED)
       {
           pointer = (pointer + 1) % 4;
           info_print_mainmenu(pointer);
       }

       clear_statemachine();
       clear_openmvmessage();
       steering_init();

       LED1_OFF;
       LED2_RGB(0, 0, 0);

       StateMachine.state = 1;
       StateMachine.task_mode = pointer + 1;

       switch (pointer)
       {
       case 0:
           task_1();
           break;
       case 1:
           task_2();
           break;
       case 2:
           task_3();
           break;
       case 3:
           task_4();
           break;
       default:
           break;
       }
       delay_ms(1000);
       delay_ms(1000);
       delay_ms(1000);
       BUZZER_OFF;
   }
}
void clear_statemachine()
{
    StateMachine.state = 0;
    StateMachine.task_mode = 0;
    StateMachine.task_progress = 0;

    StateMachine.led_state = SIGN_OFF;
    StateMachine.buzzer_state = SIGN_OFF;

    StateMachine.input_speed = 0;
}
void clear_openmvmessage()
{
    OpenmvMessage.number = 0;
    OpenmvMessage.laser_x[0] = 0;
    OpenmvMessage.laser_x[1] = 0;
    OpenmvMessage.laser_y[0] = 0;
    OpenmvMessage.laser_y[1] = 0;
}
void steering_init()
{
    pid_initialize(&pid_pitch,  0.7, 0,  0,  6, 10);
    pid_initialize(&pid_yaw,    0.7, 0,  0,  6, 45);
    pitch_angle = PITCH_OFFSET;
    yaw_angle = YAW_OFFSET;
    set_steering();
}
