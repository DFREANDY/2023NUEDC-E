#include "key.h"
#include "delay.h"

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
