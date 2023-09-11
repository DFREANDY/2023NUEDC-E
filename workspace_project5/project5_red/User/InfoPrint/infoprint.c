#include "infoprint.h"

#include "math.h"

#include "headfile.h"

#include "openmv.h"

#include "motor.h"
#include "task_control.h"


void info_print_prog()
{
    OLED_Clear();
    OLED_ShowString(2, 0, "Prog:", 8);
    OLED_ShowNum(64, 0, StateMachine.task_progress, 3, 8);

//    OLED_ShowString(2, 1, "Base :", 8);
//    OLED_ShowNum(64, 1, abs(basic_speed) * 10, 3, 8);
//
//    OLED_ShowString(2, 2, "Diff:", 8);
//    OLED_ShowNum(64, 2, abs(diff_speed) * 10, 3, 8);

    
}
void info_print_number(uint8_t number)
{
    OLED_Clear();

    if(number == 0)
    {
        OLED_ShowString(2, 1, "None!", 16);
    }
    else
    {
        OLED_ShowNum(2, 1, number, 3, 16);
    }


}
void info_print_mainmenu(uint8_t pointer)
{
    LED1_ON;
    LED2_RGB(0, 0, 0);
    switch (pointer)
    {
    case 0:
        LED2_RGB(1, 0, 0);
        break;
    case 1:
        LED2_RGB(0, 1, 0);
        break;
    case 2:
        LED2_RGB(0, 0, 1);
        break;
    case 3:
        LED2_RGB(1, 1, 0);
        break;
    case 4:
        LED2_RGB(1, 0, 1);
        break;
    case 5:
        LED2_RGB(0, 1, 1);
        break;
    case 6:
        LED2_RGB(1, 1, 0);
        break;
    case 7:
        LED2_RGB(1, 0, 1);
        break;
    case 8:
        LED2_RGB(1, 1, 1);
        break;
    default:
        break;
    }

}
