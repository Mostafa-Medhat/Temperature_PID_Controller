#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H


/* Controller parameters */
#define PID_KP  0.9f
#define PID_KI  0.1f
#define PID_KD  0.0f

#define SET_POINT	30

#define PWM_MAX .73f
#define PWM_MIN 0.0f


typedef struct {

	/* Controller gains */
	float Kp;
	float Ki;
	float Kd;


	/* Controller "memory" */
	float integrator;
	float prevError;			/* Required for integrator */
	float differentiator;

	/* Controller output */
	float out;

} PIDController;

extern PIDController pid;

void  PIDController_Init(PIDController *pid);
float PIDController_Update(PIDController *pid, float setpoint, float measurement);

#endif
