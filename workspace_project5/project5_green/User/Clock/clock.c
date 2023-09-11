#include "clock.h"

/******************************NOTICE*****************************
*代码移植自b站UP主m-RNA,本人仅作注释
*源码地址https://gitee.com/chenjjian/MSP432_Quick_entry
*****************************************************************/

/*****************************************************************
*Function: CLOCK_Init(void)
*Description:时钟初始化
*Input:无
*Output:无
*Return:无
*Others:无
*Data:2021/09/15
*****************************************************************/
void CLOCK_Init(void)
{
	WDT_A_holdTimer();
	/*P.J0、1、2、3配置为复用，连接外部晶振*/
	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_PJ,GPIO_PIN0,GPIO_PRIMARY_MODULE_FUNCTION);
	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_PJ,GPIO_PIN1,GPIO_PRIMARY_MODULE_FUNCTION);
	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_PJ,GPIO_PIN2,GPIO_PRIMARY_MODULE_FUNCTION);
	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_PJ,GPIO_PIN3,GPIO_PRIMARY_MODULE_FUNCTION);
	
	/*低速时钟32768，高速时钟48M*/
	CS_setExternalClockSourceFrequency(32768,48000000);	
	
	/*配置内核电压等级为1*/
	MAP_PCM_setCoreVoltageLevel(PCM_VCORE1);
	
	/*配置FLASH等待状态为1*/
	MAP_FlashCtl_setWaitState(FLASH_BANK0,1);
	MAP_FlashCtl_setWaitState(FLASH_BANK1,1);
	
	/*驱动高速时钟和低速时钟*/
	CS_startHFXT(false);
	CS_startLFXT(CS_LFXT_DRIVE3);
	
	/*连接MCLK HSMCLK SMCLK至高速晶振*/
	MAP_CS_initClockSignal(CS_MCLK,CS_HFXTCLK_SELECT,CS_CLOCK_DIVIDER_1);
	MAP_CS_initClockSignal(CS_HSMCLK,CS_HFXTCLK_SELECT,CS_CLOCK_DIVIDER_1);
	MAP_CS_initClockSignal(CS_SMCLK,CS_HFXTCLK_SELECT,CS_CLOCK_DIVIDER_1);

}



