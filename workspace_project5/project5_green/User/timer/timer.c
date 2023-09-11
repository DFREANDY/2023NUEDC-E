#include "timer.h"
/*****************************************************************
 *Function: TimA0_Init(uint16_t ccr0, uint16_t psc)
 *Description:��ʱ��TA0��ʼ��
 *Input:ccr0Ϊ�Զ���װ��ֵ��pscΪ��Ƶ 1 2 4 8 3 5 6 7 10 12 14 16 20 24 28 32 40 48 56 64
 *Output:��
 *Return:��
 *Others:ע��psc�����ƣ������Ч����
 *Data:2021/09/19
 *****************************************************************/
void TimA0_Init(uint16_t ccr0, uint16_t psc)
{
    /*��ʼ������*/
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN7 | GPIO_PIN6 | GPIO_PIN5 | GPIO_PIN4, GPIO_PRIMARY_MODULE_FUNCTION);

    Timer_A_PWMConfig TimA0_PWMConfig;
    /*��ʱ��PWM��ʼ��*/
    TimA0_PWMConfig.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;             //ʱ��Դ
    TimA0_PWMConfig.clockSourceDivider = psc;                            //ʱ�ӷ�Ƶ ��Χ1-64
    TimA0_PWMConfig.timerPeriod = ccr0;                                  //�Զ���װ��ֵ��ARR��
    TimA0_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_1; //ͨ��һ �����Ŷ��壩
    TimA0_PWMConfig.compareOutputMode = TIMER_A_OUTPUTMODE_TOGGLE_SET;   //���ģʽ
    TimA0_PWMConfig.dutyCycle = ccr0;                                    //�����Ǹı�ռ�ձȵĵط� Ĭ��100%

    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &TimA0_PWMConfig); /* ��ʼ���ȽϼĴ����Բ��� PWM1 */

    TimA0_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_2; //ͨ��һ �����Ŷ��壩
    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &TimA0_PWMConfig);            /* ��ʼ���ȽϼĴ����Բ��� PWM1 */

    TimA0_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_3; //ͨ��һ �����Ŷ��壩
    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &TimA0_PWMConfig);            /* ��ʼ���ȽϼĴ����Բ��� PWM1 */

    TimA0_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_4; //ͨ��һ �����Ŷ��壩
    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &TimA0_PWMConfig);            /* ��ʼ���ȽϼĴ����Բ��� PWM1 */
}
/*****************************************************************
 *Function: TimA1_PWM_Init(uint16_t ccr0, uint16_t psc)
 *Description:��ʱ��TA1��ʼ��
 *Input:ccr0Ϊ�Զ���װ��ֵ��pscΪ��Ƶ
 *Output:��
 *Return:��
 *Others:ע��psc�����ƣ������Ч����
 *Data:2021/09/19
 *****************************************************************/
void TimA1_Init(uint16_t ccr0, uint16_t psc)
{
    /*��ʼ������*/
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P7, GPIO_PIN7 | GPIO_PIN6 | GPIO_PIN5 | GPIO_PIN4, GPIO_PRIMARY_MODULE_FUNCTION);

    Timer_A_PWMConfig TimA1_PWMConfig;
    /*��ʱ��PWM��ʼ��*/
    TimA1_PWMConfig.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;             //ʱ��Դ
    TimA1_PWMConfig.clockSourceDivider = psc;                            //ʱ�ӷ�Ƶ ��Χ1-64
    TimA1_PWMConfig.timerPeriod = ccr0;                                  //�Զ���װ��ֵ��ARR��
    TimA1_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_1; //ͨ��һ �����Ŷ��壩
    TimA1_PWMConfig.compareOutputMode = TIMER_A_OUTPUTMODE_TOGGLE_SET;   //���ģʽ
    TimA1_PWMConfig.dutyCycle = ccr0;                                    //�����Ǹı�ռ�ձȵĵط� Ĭ��100%

    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &TimA1_PWMConfig); /* ��ʼ���ȽϼĴ����Բ��� PWM1 */

    TimA1_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_2; //ͨ��2 �����Ŷ��壩
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &TimA1_PWMConfig);            /* ��ʼ���ȽϼĴ����Բ��� PWM1 */

    TimA1_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_3; //ͨ��3 �����Ŷ��壩
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &TimA1_PWMConfig);            /* ��ʼ���ȽϼĴ����Բ��� PWM1 */

    TimA1_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_4; //ͨ��4 �����Ŷ��壩
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &TimA1_PWMConfig);            /* ��ʼ���ȽϼĴ����Բ��� PWM1 */
}

void TimA2_Init(uint16_t ccr0, uint16_t psc)
{
    /*��ʼ������*/
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P6, GPIO_PIN6 | GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);

    Timer_A_PWMConfig TimA2_PWMConfig;
    /*��ʱ��PWM��ʼ��*/
    TimA2_PWMConfig.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;             //ʱ��Դ
    TimA2_PWMConfig.clockSourceDivider = psc;                            //ʱ�ӷ�Ƶ ��Χ1-64
    TimA2_PWMConfig.timerPeriod = ccr0;                                  //�Զ���װ��ֵ��ARR��
    TimA2_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_3; //
    TimA2_PWMConfig.compareOutputMode = TIMER_A_OUTPUTMODE_TOGGLE_SET;   //���ģʽ
    TimA2_PWMConfig.dutyCycle = ccr0;                                    //�����Ǹı�ռ�ձȵĵط� Ĭ��100%

    MAP_Timer_A_generatePWM(TIMER_A2_BASE, &TimA2_PWMConfig);            /* ��ʼ���ȽϼĴ����Բ��� PWM */

    TimA2_PWMConfig.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_4; //ͨ��4 �����Ŷ��壩
    MAP_Timer_A_generatePWM(TIMER_A2_BASE, &TimA2_PWMConfig);            /* ��ʼ���ȽϼĴ����Բ��� PWM */
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
    // Interrupt_enableSleepOnIsrExit();//�˳��жϽ���͹���ģʽ û��Ҫ
    Interrupt_enableInterrupt(INT_TA3_0);
    Timer_A_startCounter(TIMER_A3_BASE, TIMER_A_UP_MODE);

    TA3CCR0 = 10000;
    //	//���жϿ�����
    Interrupt_enableMaster();
}
