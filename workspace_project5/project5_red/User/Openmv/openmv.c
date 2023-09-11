#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "openmv.h"

openmv_message_t OpenmvMessage;
uint8_t RXData = 0;
int16_t rect_x[4];
int16_t rect_y[4];
const eUSCI_UART_ConfigV1 uartConfigOpen =
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

void Openmv_Init(void)
{
    // 配置GPIO复用
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P3, GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
    //配置DCO频率
    MAP_UART_initModule(EUSCI_A2_BASE, &uartConfigOpen);
    // 开启串口模块
    MAP_UART_enableModule(EUSCI_A2_BASE);

    // 使能相关中断
    MAP_UART_enableInterrupt(EUSCI_A2_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
    MAP_Interrupt_enableInterrupt(INT_EUSCIA2);

    MAP_Interrupt_enableMaster();
}

void Openmv_Receive_Data(uint8_t data)
{
    static uint8_t openmv[10];    //存取数据
    static uint8_t state = 0;
    static uint8_t bit_number = 0;
    uint8_t i;

    if(state == 0 && data == 0x2C)
    {
        state = 1;
        openmv[bit_number++] = data;
    }
    else if(state == 1 && data == 0x04)
    {
        state = 2;
        openmv[bit_number++] = data;
    }
    else if(state == 2)
    {
        openmv[bit_number++] = data;
        if(bit_number >= 7)
            state = 3;
    }
    else if(state == 3)
    {
        //检测到结束位
         if(data == 0x5B)
         {
             state = 0;
             openmv[bit_number++] = data;
             OpenmvMessage.number = openmv[2];
             if(openmv[2] == 4)
             {
                 if((int8_t)openmv[4] != 125)
                 {
                     OpenmvMessage.laser_x[0] = (int8_t)openmv[4];
                     OpenmvMessage.laser_y[0] = (int8_t)openmv[6];
                 }

             }
             else if(openmv[2] == 5)
             {
                 OpenmvMessage.laser_x[1] = (int8_t)openmv[4];
                 OpenmvMessage.laser_y[1] = (int8_t)openmv[6];
             }
             else if(openmv[2] <= 3)
             {
                 OpenmvMessage.rect_x[openmv[2]] = (int8_t)openmv[4];
                 OpenmvMessage.rect_y[openmv[2]] = (int8_t)openmv[6];
             }
             else if(openmv[2] == 7)
             {
                 OpenmvMessage.angle[0] = (int8_t)openmv[4];
                 OpenmvMessage.angle[1] = (int8_t)openmv[6];
             }

         }
         //未检测到结束位
         else if(data != 0x5B)
         {
             state = 0;
             for(i = 0; i <= 9; i++)
                 openmv[i] = 0x00;
         }
    }
    else
    {
        state = 0;
        bit_number = 0;
        for(i = 0; i <= 7; i++)
            openmv[i] = 0x00;
    }
    bit_number %= 8;
}
void openmv_request_data(uint8_t content)
{
    MAP_UART_transmitData(EUSCI_A2_BASE, 0x2C);
	MAP_UART_transmitData(EUSCI_A2_BASE, 0x04);
	MAP_UART_transmitData(EUSCI_A2_BASE, content);
	MAP_UART_transmitData(EUSCI_A2_BASE, 0x5B);
}
void update_rect()
{
    uint8_t i = 0;
    for(i = 0; i < 4; ++i)
    {
        rect_x[i] = OpenmvMessage.rect_x[i];
        rect_y[i] = OpenmvMessage.rect_y[i];
    }
}
void EUSCIA2_IRQHandler(void)
{
    uint32_t status = UART_getEnabledInterruptStatus(EUSCI_A2_BASE);
    //MAP_UART_clearInterruptFlag(EUSCI_A2_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG);
    if(status & EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
    {
        RXData = UART_receiveData(EUSCI_A2_BASE);
        Openmv_Receive_Data(RXData);
    }
}
