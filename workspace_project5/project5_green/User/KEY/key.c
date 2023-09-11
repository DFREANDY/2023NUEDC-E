#include "key.h"
#include "delay.h"
void KEY_Init(void)
{
	GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1 | GPIO_PIN4);
}

uint8_t KEY_Input()
{
	while (1)
    {
        if (!KEY1)
        {
            while (1)
            {
                if (KEY1)
                {
                    delay_ms(20);
                    return KEY1_PRESSED;
                }
            }
        }
        else if (!KEY2)
        {
            while (1)
            {
                if (KEY2)
                {
                    delay_ms(20);
                    return KEY2_PRESSED;
                }
            }
        }
    }
}
