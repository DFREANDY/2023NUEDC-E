#ifndef __LED_H
#define __LED_H

#include <stdint.h>
#include <stdbool.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/*LED1ÁÁ*/
#define LED1_ON GPIO_setOutputHighOnPin(GPIO_PORT_P1,GPIO_PIN0)

/*LED1·­×ª*/
#define LED1_TOG    GPIO_toggleOutputOnPin(GPIO_PORT_P1,GPIO_PIN0)

/*LED1Ãð*/
#define LED1_OFF GPIO_setOutputLowOnPin(GPIO_PORT_P1,GPIO_PIN0)


#define BUZZER_ON       GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN2)
#define BUZZER_OFF      GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN2)

void LED_Init(void);
void LED2_RGB(uint8_t red, uint8_t green, uint8_t blue);

#endif

