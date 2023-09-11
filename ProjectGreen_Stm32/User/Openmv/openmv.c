#include "openmv.h"
#include "usart.h"
openmv_message_t OpenmvMessage;
uint8_t RXData = 0;
uint8_t RxBuffer[100];
int16_t rect_x[4];
int16_t rect_y[4];

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
                 if((int8_t)openmv[4] != 125)
                 {
                     OpenmvMessage.laser_x[1] = (int8_t)openmv[4];
                     OpenmvMessage.laser_y[1] = (int8_t)openmv[6];
                 }
             }
             else if(openmv[2] <= 3)
             {
                 rect_x[openmv[2]] = (int8_t)openmv[4];
                 rect_y[openmv[2]] = (int8_t)openmv[6];
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

/**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
*/
uint16_t uart_receive()
{    
	if(HAL_UART_Receive(&huart1, RxBuffer, 10 * 8, 5000) == HAL_TIMEOUT)
		return 1;

    uint8_t i;
    for(i = 0; i < 10 * 8; ++i)
    {
        RXData = RxBuffer[i];
        Openmv_Receive_Data(RXData);
    }
    
	return 0;
}
