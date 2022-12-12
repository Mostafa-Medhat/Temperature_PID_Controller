#include "PID.h"

PIDController pid = { PID_KP, PID_KI, PID_KD};

void PIDController_Init(PIDController *pid) {

	/* Clear controller variables */
	pid->integrator = 0.0f;

	pid->prevError  = 0.0f;

	pid->differentiator  = 0.0f;

	pid->out = 0.0f;

}

float PIDController_Update(PIDController *pid, float setpoint, float measurement) {

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
    pid->integrator = pid->integrator + error ;


	/*
	* Derivative
	*/
		
    pid->differentiator = error - pid->prevError;


	/*
	* Compute output and apply limits
	*/
    pid->out = proportional + pid->integrator + pid->differentiator;

    
	/* Store error and measurement for later use */
    pid->prevError       = error; // update prevError


	if( (pid->out/255) > PWM_MAX)
	{
		pid->out = 255 * PWM_MAX;
	} 
	else if( (pid->out/255) < PWM_MIN)
	{
		pid->out = 255 * PWM_MIN;
	} 

	/* Return controller output */
    return pid->out;

}
