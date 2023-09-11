#include "timer.h"
/*****************************************************************
 *Function: TimA0_Init(uint16_t ccr0, uint16_t psc)
 *Description:定时器TA0初始化
 *Input:ccr0为自动重装载值，psc为分频 1 2 4 8 3 5 6 7 10 12 14 16 20 24 28 32 40 48 56 64
 *Output:无
 *Return:无
 *Others:注意psc有限制，需查有效参数
 *Data:2021/09/19
 *****************************************************************/
void TimA0_Init(uint16_t ccr0, uint16_t psc)
{
    /*初始化引脚*/
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN7 | GPIO_PIN6 | GPIO_PIN5 | GPIO_PIN4, GPIO_PRIMARY_MODULE_FUNCTION);

    Timer_A_PWMConfig TimA0_PWMConfig;
    /*定时器PWM初始化*/
    TimA0_PWMConfig.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;             //时钟源
    TimA0_PWMConfig.clockSourceDivider = psc;                            //时钟分频 范围1-64
    TimA0_PWMConfig.timerPeriod = ccr0;                                  //自动重装载值（ARR）
    TimA0_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_1; //通道一 （引脚定义）
    TimA0_PWMConfig.compareOutputMode = TIMER_A_OUTPUTMODE_TOGGLE_SET;   //输出模式
    TimA0_PWMConfig.dutyCycle = ccr0;                                    //这里是改变占空比的地方 默认100%

    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &TimA0_PWMConfig); /* 初始化比较寄存器以产生 PWM1 */

    TimA0_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_2; //通道一 （引脚定义）
    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &TimA0_PWMConfig);            /* 初始化比较寄存器以产生 PWM1 */

    TimA0_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_3; //通道一 （引脚定义）
    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &TimA0_PWMConfig);            /* 初始化比较寄存器以产生 PWM1 */

    TimA0_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_4; //通道一 （引脚定义）
    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &TimA0_PWMConfig);            /* 初始化比较寄存器以产生 PWM1 */
}
/*****************************************************************
 *Function: TimA1_PWM_Init(uint16_t ccr0, uint16_t psc)
 *Description:定时器TA1初始化
 *Input:ccr0为自动重装载值，psc为分频
 *Output:无
 *Return:无
 *Others:注意psc有限制，需查有效参数
 *Data:2021/09/19
 *****************************************************************/
void TimA1_Init(uint16_t ccr0, uint16_t psc)
{
    /*初始化引脚*/
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P7, GPIO_PIN7 | GPIO_PIN6 | GPIO_PIN5 | GPIO_PIN4, GPIO_PRIMARY_MODULE_FUNCTION);

    Timer_A_PWMConfig TimA1_PWMConfig;
    /*定时器PWM初始化*/
    TimA1_PWMConfig.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;             //时钟源
    TimA1_PWMConfig.clockSourceDivider = psc;                            //时钟分频 范围1-64
    TimA1_PWMConfig.timerPeriod = ccr0;                                  //自动重装载值（ARR）
    TimA1_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_1; //通道一 （引脚定义）
    TimA1_PWMConfig.compareOutputMode = TIMER_A_OUTPUTMODE_TOGGLE_SET;   //输出模式
    TimA1_PWMConfig.dutyCycle = ccr0;                                    //这里是改变占空比的地方 默认100%

    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &TimA1_PWMConfig); /* 初始化比较寄存器以产生 PWM1 */

    TimA1_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_2; //通道2 （引脚定义）
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &TimA1_PWMConfig);            /* 初始化比较寄存器以产生 PWM1 */

    TimA1_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_3; //通道3 （引脚定义）
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &TimA1_PWMConfig);            /* 初始化比较寄存器以产生 PWM1 */

    TimA1_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_4; //通道4 （引脚定义）
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &TimA1_PWMConfig);            /* 初始化比较寄存器以产生 PWM1 */
}

void TimA2_Init(uint16_t ccr0, uint16_t psc)
{
    /*初始化引脚*/
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P6, GPIO_PIN6 | GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);

    Timer_A_PWMConfig TimA2_PWMConfig;
    /*定时器PWM初始化*/
    TimA2_PWMConfig.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;             //时钟源
    TimA2_PWMConfig.clockSourceDivider = psc;                            //时钟分频 范围1-64
    TimA2_PWMConfig.timerPeriod = ccr0;                                  //自动重装载值（ARR）
    TimA2_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_3; //
    TimA2_PWMConfig.compareOutputMode = TIMER_A_OUTPUTMODE_TOGGLE_SET;   //输出模式
    TimA2_PWMConfig.dutyCycle = ccr0;                                    //这里是改变占空比的地方 默认100%

    MAP_Timer_A_generatePWM(TIMER_A2_BASE, &TimA2_PWMConfig);            /* 初始化比较寄存器以产生 PWM */

    TimA2_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_4; //通道4 （引脚定义）
    MAP_Timer_A_generatePWM(TIMER_A2_BASE, &TimA2_PWMConfig);            /* 初始化比较寄存器以产生 PWM */
}



/* Timer_A UpMode Configuration Parameter */
const Timer_A_UpModeConfig upConfig =
    {
        TIMER_A_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
        TIMER_A_CLOCKSOURCE_DIVIDER_48,     // SMCLK/48 = 1us
        25000,                              //
        TIMER_A_TAIE_INTERRUPT_DISABLE,     // Disable Timer interrupt
        TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE, // Enable CCR0 interrupt
        TIMER_A_DO_CLEAR                    // Clear value
};

void TA3_IT_INIT(void)
{
    Timer_A_configureUpMode(TIMER_A3_BASE, &upConfig);
    // Interrupt_enableSleepOnIsrExit();//退出中断进入低功耗模式 没必要
    Interrupt_enableInterrupt(INT_TA3_0);
    Timer_A_startCounter(TIMER_A3_BASE, TIMER_A_UP_MODE);

    TA3CCR0 = 10000;
    //	//开中断控制器
    Interrupt_enableMaster();
}
