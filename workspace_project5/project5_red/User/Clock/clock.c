#include "clock.h"

/******************************NOTICE*****************************
*������ֲ��bվUP��m-RNA,���˽���ע��
*Դ���ַhttps://gitee.com/chenjjian/MSP432_Quick_entry
*****************************************************************/

/*****************************************************************
*Function: CLOCK_Init(void)
*Description:ʱ�ӳ�ʼ��
*Input:��
*Output:��
*Return:��
*Others:��
*Data:2021/09/15
*****************************************************************/
void CLOCK_Init(void)
{
	WDT_A_holdTimer();
	/*P.J0��1��2��3����Ϊ���ã������ⲿ����*/
	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_PJ,GPIO_PIN0,GPIO_PRIMARY_MODULE_FUNCTION);
	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_PJ,GPIO_PIN1,GPIO_PRIMARY_MODULE_FUNCTION);
	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_PJ,GPIO_PIN2,GPIO_PRIMARY_MODULE_FUNCTION);
	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_PJ,GPIO_PIN3,GPIO_PRIMARY_MODULE_FUNCTION);
	
	/*����ʱ��32768������ʱ��48M*/
	CS_setExternalClockSourceFrequency(32768,48000000);	
	
	/*�����ں˵�ѹ�ȼ�Ϊ1*/
	MAP_PCM_setCoreVoltageLevel(PCM_VCORE1);
	
	/*����FLASH�ȴ�״̬Ϊ1*/
	MAP_FlashCtl_setWaitState(FLASH_BANK0,1);
	MAP_FlashCtl_setWaitState(FLASH_BANK1,1);
	
	/*��������ʱ�Ӻ͵���ʱ��*/
	CS_startHFXT(false);
	CS_startLFXT(CS_LFXT_DRIVE3);
	
	/*����MCLK HSMCLK SMCLK�����پ���*/
	MAP_CS_initClockSignal(CS_MCLK,CS_HFXTCLK_SELECT,CS_CLOCK_DIVIDER_1);
	MAP_CS_initClockSignal(CS_HSMCLK,CS_HFXTCLK_SELECT,CS_CLOCK_DIVIDER_1);
	MAP_CS_initClockSignal(CS_SMCLK,CS_HFXTCLK_SELECT,CS_CLOCK_DIVIDER_1);

}



