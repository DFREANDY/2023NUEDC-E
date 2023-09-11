#include <led.h>

// /*LED2ºìµÆÁÁ*/
// #define LED2_RED_ON     GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN5)
// /*LED2ÂÌµÆÁÁ*/
// #define LED2_GREEN_ON   GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN6)
// /*LED2À¶µÆÁÁ*/
// #define LED2_BLUE_ON    GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN7)

// /*LED2ºìµÆÃð*/
// #define LED2_RED_OFF    GPIO_setOutputLowOnPin(GPIO_PORT_P3,GPIO_PIN5)
// /*LED2ÂÌµÆÃð*/
// #define LED2_GREEN_OFF  GPIO_setOutputLowOnPin(GPIO_PORT_P3,GPIO_PIN6)
// /*LED2À¶µÆÃð*/
// #define LED2_BLUE_OFF   GPIO_setOutputLowOnPin(GPIO_PORT_P3,GPIO_PIN7)

// /*LED2ºìµÆ·­×ª*/
// #define LED2_RED_TOG    GPIO_toggleOutputOnPin(GPIO_PORT_P3,GPIO_PIN5)
// /*LED2ÂÌµÆ·­×ª*/
// #define LED2_GREEN_TOG  GPIO_toggleOutputOnPin(GPIO_PORT_P3,GPIO_PIN6)
// /*LED2À¶µÆ·­×ª*/
// #define LED2_BLUE_TOG   GPIO_toggleOutputOnPin(GPIO_PORT_P3,GPIO_PIN7)

// void LED_Init(void)
// {
//     /*LED1ÅäÖÃ*/
//     GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
//     // /*LED2ÅäÖÃ*/
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
