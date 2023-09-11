#ifndef __pid_H__
#define __pid_H__

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdint.h>
#include <stdbool.h>

#define Limiter(val,min,max) ((val)<(min)?(min):((val)>(max)?(max):(val)))

typedef struct {
	/**
	* \brief pid parameters
	*/
	float kp, ki, kd;
	
	/**
	* \brief errors
	*/
	float cur_error, last_error, sum_error;
	
	/**
	* \brief pid output
	*/
	float output;
	
	/**
	* \brief Constrain parameters
	*/
	float sum_error_max, output_max;
} pid_t;

/**
* \brief PID initialize
* \param[in] pid PID struct to be initialized
* \param[in] kp Proportional coefficient
* \param[in] ki Integral coefficient
* \param[in] kd Derivative coefficient
* \param[in] sum_error_max Maximum value of the integral term
* \param[in] output_max Maximum value of the output
*/
void pid_initialize(pid_t *const pid, float kp, float ki, float kd, uint_fast16_t sum_error_max, uint_fast16_t output_max);

/**
* \brief Compute pid output
* \param[in] pid The  pid struct to be updated
* \param[in] error Calculated error of the control system (target - feedback)
* \return Control output
*/
float pid_update(pid_t *const pid, const float error);

#endif
