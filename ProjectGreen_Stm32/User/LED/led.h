#ifndef __LED_H
#define __LED_H

#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#define LED1_ON     HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET)

#define LED1_TOG    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin)

#define LED1_OFF    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET)


//void LED_Init(void);
//void LED2_RGB(uint8_t red, uint8_t green, uint8_t blue);

#endif

