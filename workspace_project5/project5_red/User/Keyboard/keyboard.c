/* DriverLib Includes */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

#include "keyboard.h"

uint32_t KeyS = 0;            //��ֵ

void KeyboardInit(void)
{
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN4);     //��1��C1
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN5);     //��2��C2
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN6);     //��3��C3
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN7);     //��4��C4

    /* ����������͵�ƽ*/
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN4);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN5);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN6);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN7);

    /* ���õ�1��R1--P4.0Ϊ�����������벢ʹ���ж�  */
    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN0);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P4, GPIO_PIN0);
    MAP_GPIO_enableInterrupt(GPIO_PORT_P4, GPIO_PIN0);
    MAP_Interrupt_enableInterrupt(INT_PORT4);

//    /* ���õ�2��R2--P4.1Ϊ�����������벢ʹ���ж�  */
//    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN1);
//    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P4, GPIO_PIN1);
//    MAP_GPIO_enableInterrupt(GPIO_PORT_P4, GPIO_PIN1);
//    MAP_Interrupt_enableInterrupt(INT_PORT4);
//
//    /* ���õ�3��R3--P4.2Ϊ�����������벢ʹ���ж�  */
//    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN2);
//    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P4, GPIO_PIN2);
//    MAP_GPIO_enableInterrupt(GPIO_PORT_P4, GPIO_PIN2);
//    MAP_Interrupt_enableInterrupt(INT_PORT4);
//
//    /* ���õ�4��R4--P4.3Ϊ�����������벢ʹ���ж�  */
//    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN3);
//    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P4, GPIO_PIN3);
//    MAP_GPIO_enableInterrupt(GPIO_PORT_P4, GPIO_PIN3);
//    MAP_Interrupt_enableInterrupt(INT_PORT4);

}

int GetKey(void)
{
    return KeyS;
}

/* GPIO�жϷ������  */
/* ���ж��н�����ɨ���ж��ĸ��������£��жϽ�������������Ϊ0. */
/* ��1�к͵�2�еİ����жϷ������*/
void PORT4_IRQHandler(void)
{
    uint32_t status1;    //����һ��״̬��־�����Ĵ��ж����

    status1 = MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P4);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P4, status1);           //���������жϱ�־λ

    /* �жϵ�һ�а����Ƿ���,��������Ϊ0 */
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN4);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN5);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN6);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN7);
    if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN0)) )        //S1����
    {
        KeyS = 1;

    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN1)) )   //S4����
//    {
//        KeyS=4;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN2)) )   //S7����
//    {
//            KeyS=7;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN3)) )   //S13����
//    {
//            KeyS=13;
//
//    }

    /* �жϵڶ��а����Ƿ���,��������Ϊ0 */
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN4);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN5);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN6);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN7);
    if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN0)) )        //S2����
    {
            KeyS = 2;

    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN1)) )   //56����
//    {
//            KeyS=5;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN2)) )   //S8����
//    {
//            KeyS=8;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN3)) )   //S14����
//    {
//            KeyS=14;
//
//    }

    /* �жϵ����а����Ƿ���,��������Ϊ0 */
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN4);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN5);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN6);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN7);
    if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN0)) )        //S3����
    {
            KeyS = 3;

    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN1)) )   //S6����
//    {
//            KeyS=6;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN2)) )   //S9����
//    {
//           KeyS=9;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN3)) )   //S15����
//    {
//           KeyS=15;
//
//    }

    /* �жϵ����а����Ƿ���,��������Ϊ0 */
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN4);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN5);
    MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN6);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN7);
    if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN0)) )        //SA����
    {
           KeyS = 4;

    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN1)) )   //SB����
//    {
//           KeyS=11;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN2)) )   //SC����
//    {
//           KeyS=0;
//
//    }
//    else if(!(MAP_GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN3)) )   //S16����
//    {
//           KeyS=16;
//
//    }

    /*��������0��������һ�ν����ж�*/
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN4);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN5);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN6);
    MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN7);

}



