#include <led.h>

// /*LED2�����*/
// #define LED2_RED_ON     GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN5)
// /*LED2�̵���*/
// #define LED2_GREEN_ON   GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN6)
// /*LED2������*/
// #define LED2_BLUE_ON    GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN7)

// /*LED2�����*/
// #define LED2_RED_OFF    GPIO_setOutputLowOnPin(GPIO_PORT_P3,GPIO_PIN5)
// /*LED2�̵���*/
// #define LED2_GREEN_OFF  GPIO_setOutputLowOnPin(GPIO_PORT_P3,GPIO_PIN6)
// /*LED2������*/
// #define LED2_BLUE_OFF   GPIO_setOutputLowOnPin(GPIO_PORT_P3,GPIO_PIN7)

// /*LED2��Ʒ�ת*/
// #define LED2_RED_TOG    GPIO_toggleOutputOnPin(GPIO_PORT_P3,GPIO_PIN5)
// /*LED2�̵Ʒ�ת*/
// #define LED2_GREEN_TOG  GPIO_toggleOutputOnPin(GPIO_PORT_P3,GPIO_PIN6)
// /*LED2���Ʒ�ת*/
// #define LED2_BLUE_TOG   GPIO_toggleOutputOnPin(GPIO_PORT_P3,GPIO_PIN7)

// void LED_Init(void)
// {
//     /*LED1����*/
//     GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
//     // /*LED2����*/
//     // GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN5);
//     // GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN6);
//     // GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN7);

//     LED1_OFF;
//     // LED2_BLUE_OFF;
//     // LED2_GREEN_OFF;
//     // LED2_RED_OFF;

// }
// void LED2_RGB(uint8_t red, uint8_t green, uint8_t blue)
// {
//     if(red)
//         LED2_RED_ON;
//     else
//         LED2_RED_OFF;
//     if(green)
//         LED2_GREEN_ON;
//     else
//         LED2_GREEN_OFF;
//     if(blue)
//         LED2_BLUE_ON;
//     else
//         LED2_BLUE_OFF;
// }
