#ifndef __DELAY_H
#define __DELAY_H 			   

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
	 
void delay_init(void);
void delay_ms(uint16_t nms);
void delay_us(uint32_t nus);

#endif





























