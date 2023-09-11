#ifndef __TIMER_H
#define __TIMER_H
#include "headfile.h"

/**
 * @brief :
 * @note  :
 *  a:TAx 0 / 1
 *  x:CCRx 0/1/2/3/4   0:the period of TIMER
 *  y:CCR value
 */
#define PWM_CHANGE_CCR(_0_or_1, _01234, _uint16) TA##_0_or_1##CCR##_01234## = (_uint16)


/*
 * 定时器PWM周期：
 *
 * T_timer_a = CLKDIV * (CCR0 + 1) / f_clk
 *           = 48 * （19999 + 1） / 48000000
 *           = 0.02s = 50Hz
 */
void TimA0_Init(uint16_t ccr0, uint16_t psc);
void TimA1_Init(uint16_t ccr0, uint16_t psc);
void TimA2_Init(uint16_t ccr0, uint16_t psc);
void TA3_IT_INIT(void);

#endif
