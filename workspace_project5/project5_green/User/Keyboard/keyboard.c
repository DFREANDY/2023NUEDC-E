/* DriverLib Includes */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

#include "keyboard.h"

uint32_t KeyS = 0;            //键值

void KeyboardInit(void)
{
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN4);     //第1列C1
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN5);     //第2列C2
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN6);     //第3列C3
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN7);     //第4列C4

    /* 所有列输出低电平*/
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN4);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN5);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN6);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN7);

    /* 配置第1行R1--P4.0为上拉电阻输入并使能中断  */
    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN0);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P4, GPIO_PIN0);
    MAP_GPIO_enableInterrupt(GPIO_PORT_P4, GPIO_PIN0);
    MAP_Interrupt_enableInterrupt(INT_PORT4);

//    /* 配置第2行R2--P4.1为上拉电阻输入并使能中断  */
//    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN1);
//    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P4, GPIO_PIN1);
//    MAP_GPIO_enableInterrupt(GPIO_PORT_P4, GPIO_PIN1);
//    MAP_Interrupt_enableInterrupt(INT_PORT4);
//
//    /* 配置第3行R3--P4.2为上拉电阻输入并使能中断  */
//    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN2);
//    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P4, GPIO_PIN2);
//    MAP_GPIO_enableInterrupt(GPIO_PORT_P4, GPIO_PIN2);
//    MAP_Interrupt_enableInterrupt(INT_PORT4);
//
//    /* 配置第4行R4--P4.3为上拉电阻输入并使能中断  */
//    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN3);
//    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P4, GPIO_PIN3);
//    MAP_GPIO_enableInterrupt(GPIO_PORT_P4, GPIO_PIN3);
//    MAP_Interrupt_enableInterrupt(INT_PORT4);

}

int GetKey(void)
{
    return KeyS;
}

/* GPIO中断服务程序  */
/* 在中断中进行列扫描判断哪个按键按下，中断结束将所有列置为0. */
/* 第1行和第2行的按键中断服务程序，*/
void PORT4_IRQHandler(void)
{
    uint32_t status1;    //设置一个状态标志量，寄存中断情况

    status1 = MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P4);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P4, status1);           //清零所有中断标志位

    /* 判断第一列按键是否按下,按下输入为0 */
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN4);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN5);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN6);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN7);
    if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN0)) )        //S1按下
    {
        KeyS = 1;

    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN1)) )   //S4按下
//    {
//        KeyS=4;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN2)) )   //S7按下
//    {
//            KeyS=7;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN3)) )   //S13按下
//    {
//            KeyS=13;
//
//    }

    /* 判断第二列按键是否按下,按下输入为0 */
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN4);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN5);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN6);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN7);
    if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN0)) )        //S2按下
    {
            KeyS = 2;

    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN1)) )   //56按下
//    {
//            KeyS=5;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN2)) )   //S8按下
//    {
//            KeyS=8;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN3)) )   //S14按下
//    {
//            KeyS=14;
//
//    }

    /* 判断第三列按键是否按下,按下输入为0 */
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN4);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN5);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN6);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN7);
    if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN0)) )        //S3按下
    {
            KeyS = 3;

    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN1)) )   //S6按下
//    {
//            KeyS=6;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN2)) )   //S9按下
//    {
//           KeyS=9;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN3)) )   //S15按下
//    {
//           KeyS=15;
//
//    }

    /* 判断第四列按键是否按下,按下输入为0 */
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN4);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN5);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN6);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN7);
    if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN0)) )        //SA按下
    {
           KeyS = 4;

    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN1)) )   //SB按下
//    {
//           KeyS=11;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN2)) )   //SC按下
//    {
//           KeyS=0;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN3)) )   //S16按下
//    {
//           KeyS=16;
//
//    }

    /*所有列置0，方便下一次进入中断*/
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN4);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN5);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN6);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN7);

}



