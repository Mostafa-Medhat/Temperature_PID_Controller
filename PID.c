#include "PID.h"

void PIDController_Init(PIDController *pid) {

	/* Clear controller variables */
	pid->integrator = 0.0f;

	pid->differentiator  = 0.0f;
	pid->prevMeasurement = 0.0f;

	pid->out = 0.0f;

}

float PIDController_Update(PIDController *pid, float setpoint, float measurement)
{
	int32_t temp;

	/*
	* Error signal
	*/
    float error = setpoint - measurement;


	/*
	* Proportional
	*/
    float proportional = pid->Kp * error;


	/*
	* Integral
	*/
    temp = pid->sumError + error;

	/* Anti-wind-up via integrator clamping */
    if (temp > pid->limMaxInt)
    {
        pid->integrator = pid->limMaxInt;
    }
    else if (temp < pid->limMinInt)
    {
        pid->integrator = pid->limMinInt;
    }
    else
    {
    	pid->sumError = temp;
        pid->integrator = pid->Ki * pid->sumError;
    }


	/*
	* Derivative
	*/
		
    pid->differentiator = pid->Kd * (measurement - pid->prevMeasurement);


	/*
	* Compute output and apply limits
	*/
    pid->out = proportional + pid->integrator + pid->differentiator;

    if (pid->out > pid->limMax) {

        pid->out = pid->limMax;

    } else if (pid->out < pid->limMin) {

        pid->out = pid->limMin;

    }

	/* Store error and measurement for later use */
    pid->prevMeasurement = measurement;

	/* Return controller output */
    return pid->out;

}
