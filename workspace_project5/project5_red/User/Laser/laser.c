#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "laser.h"


laser_message_t LaserMessage;
const eUSCI_UART_ConfigV1 uartConfigLaser =
{
        EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
        26,                                      // BRDIV
        0,                                       // UCxBRF
        111,                                       // UCxBRS   设置波特率为115200
        EUSCI_A_UART_NO_PARITY,                  // No Parity
        EUSCI_A_UART_LSB_FIRST,                  // LSB First
        EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
        EUSCI_A_UART_MODE,                       // UART mode
        EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION,  // Oversampling
        EUSCI_A_UART_8_BIT_LEN                   // 8  bit data length
};

void Laser_Init(void)
{
    // 配置GPIO复用
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P2, GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
    //配置DCO频率
    MAP_UART_initModule(EUSCI_A1_BASE, &uartConfigLaser);
    // 开启串口模块
    MAP_UART_enableModule(EUSCI_A1_BASE);

    // 使能相关中断
    MAP_UART_enableInterrupt(EUSCI_A1_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
    MAP_Interrupt_enableInterrupt(INT_EUSCIA1);

    MAP_Interrupt_enableMaster();
}

void Laser_Receive_Data(int8_t data)
{
    static int8_t laser[7];    //存取数据
    static int8_t state = 0;
    static int8_t bit_number = 0;
    uint8_t i;

    if(state == 0 && data == 0x2C)
    {
        state = 1;
        laser[bit_number++] = data;
    }
    else if(state == 1 && data == 0x04)
    {
        state = 2;
        laser[bit_number++] = data;
    }
    else if(state == 2)
    {
        laser[bit_number++] = data;
        if(bit_number >= 6)
            state = 3;
    }
    else if(state == 3)
    {
        //检测到结束位
         if(data == 0x5B)
         {
             state = 0;
             laser[bit_number++] = data;
             LaserMessage.angle1 = (int8_t)laser[2];
             LaserMessage.n1     = (int8_t)laser[3];
             LaserMessage.angle2 = (int8_t)laser[4];
             LaserMessage.n2   = (int8_t)laser[5];

         }
         //未检测到结束位
         else if(data != 0x5B)
         {
             state = 0;
             for(i = 0; i <= 6; i++)
                 laser[i] = 0x00;
         }
    }
    else
    {
        state = 0;
        bit_number = 0;
        for(i = 0; i <= 6; i++)
            laser[i] = 0x00;
    }
    bit_number %= 7;
}
void EUSCIA1_IRQHandler(void)
{
    uint32_t status = UART_getEnabledInterruptStatus(EUSCI_A1_BASE);
    int8_t RxData;
    if(status & EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
    {
        RxData = UART_receiveData(EUSCI_A1_BASE);
        Laser_Receive_Data(RxData);
    }
}
