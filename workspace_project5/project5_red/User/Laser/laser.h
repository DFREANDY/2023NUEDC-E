/*
 * laser.h
 *
 *  Created on: 2023Äê7ÔÂ21ÈÕ
 *      Author: Andy Dufresne
 */

#ifndef USER_LASER_LASER_H_
#define USER_LASER_LASER_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    int8_t angle1;
    int8_t n1;
    int8_t angle2;
    int8_t n2;
}laser_message_t;

extern laser_message_t LaserMessage;

void Laser_Init(void);

#endif /* USER_LASER_LASER_H_ */
