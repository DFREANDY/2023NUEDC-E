#ifndef __KEY_H
#define __KEY_H

#include <stdint.h>
#include <stdbool.h>

#include "main.h"

#define KEY1 HAL_GPIO_ReadPin(K3_GPIO_Port, K3_Pin)
#define KEY2 HAL_GPIO_ReadPin(K4_GPIO_Port, K4_Pin)

#define KEY1_PRESSED 1 // KEY1
#define KEY2_PRESSED 2 // KEY2

void KEY_Init(void); 
uint8_t KEY_Input(void); 
#endif
