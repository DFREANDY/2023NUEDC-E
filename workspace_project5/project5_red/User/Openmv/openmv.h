#ifndef USER_OPENMV_H_
#define USER_OPENMV_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    int8_t laser_x[2];
    int8_t laser_y[2];
    int16_t rect_x[4];
    int16_t rect_y[4];
    uint8_t number;
    float   angle[2];
}openmv_message_t;

void Openmv_Init(void);
void Openmv_Receive_Data(uint8_t data);
void openmv_request_data(uint8_t content);
void update_rect();
extern openmv_message_t OpenmvMessage;
extern int16_t rect_x[4];
extern int16_t rect_y[4];
#endif /* USER_OPENMV_OPENMV_H_ */
