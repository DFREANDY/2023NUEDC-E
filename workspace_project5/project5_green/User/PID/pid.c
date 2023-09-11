#include "pid.h"
#include "math.h"

/**
* \brief pid initialize
* \param[in] pid PID struct to be initialized
* \param[in] kp Proportional coefficient
* \param[in] ki Integral coefficient
* \param[in] kd Derivative coefficient
* \param[in] sum_error_max Maximum value of the integral term
* \param[in] output_max Maximum value of the output
*/
void pid_initialize(pid_t *const pid, float kp, float ki, float kd, uint_fast16_t sum_error_max, uint_fast16_t output_max)
{
	//< pid parameters
	pid->kp = kp;
	pid->ki = ki;
	pid->kd = kd;
	
	//< clear buffers
	pid->cur_error = 0;
	pid->last_error = 0;
	pid->sum_error = 0;
	
	//< constrain parameters
	pid->sum_error_max = sum_error_max;
	pid->output_max = output_max;
}

/**
* \brief Compute pid output
* \param[in] pid The  pid struct to be updated
* \param[in] error Calculated error of the control system (target - feedback)
* \return Control output
*/
float pid_update(pid_t *const pid, const float error)
{
	pid->last_error = pid->cur_error;
	pid->cur_error = error;
	pid->sum_error += pid->cur_error;
	pid->sum_error = Limiter(pid->sum_error, -pid->sum_error_max, pid->sum_error_max);
	pid->output = pid->kp * pid->cur_error +\
								pid->ki * pid->sum_error +\
								pid->kd * (pid->cur_error - pid->last_error);
	return pid->output = Limiter(pid->output, -pid->output_max, pid->output_max);
}
