#ifndef __KEY_H
#define __KEY_H

#include <stdint.h>
#include <stdbool.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

#define KEY1 GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN1)
#define KEY2 GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4)

#define KEY1_PRESSED 1 // KEY1
#define KEY2_PRESSED 2 // KEY2

void KEY_Init(void); 
uint8_t KEY_Input(); 
#endif
