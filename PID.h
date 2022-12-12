#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H


/* Controller parameters */
#define PID_KP  0.1f
#define PID_KI  0.01f
#define PID_KD  0.0f

#define PID_TAU 0.02f

#define PID_LIM_MIN 	0
#define PID_LIM_MAX  73.0f

#define PID_LIM_MIN_INT -5.0f
#define PID_LIM_MAX_INT  5.0f

#define SAMPLE_TIME_S 0.5f

/* Maximum run-time of simulation */
#define SIMULATION_TIME_MAX 4.0f

#define SET_POINT	30


typedef struct {

	/* Controller gains */
	float Kp;
	float Ki;
	float Kd;

	/* Derivative low-pass filter time constant */
	float tau;

	/* Output limits */
	float limMin;
	float limMax;
	
	/* Integrator limits */
	float limMinInt;
	float limMaxInt;

	/* Sample time (in seconds) */
	float T;

	/* Controller "memory" */
	float integrator;
	float prevError;			/* Required for integrator */
	float differentiator;
	float prevMeasurement;		/* Required for differentiator */

	/* Controller output */
	float out;

} PIDController;

extern PIDController pid;

void  PIDController_Init(PIDController *pid);
float PIDController_Update(PIDController *pid, float setpoint, float measurement);

#endif
