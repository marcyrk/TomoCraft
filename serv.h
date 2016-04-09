#ifndef SERV_H
#define SERV_H

#include <mraa/pwm.h>
#include <mraa/gpio.h>
#include <string>
#include <iostream>
#include <unistd.h>

#define MIN_PULSE_WIDTH             (600)
#define MAX_PULSE_WIDTH             (2500)
#define PERIOD                      (5000)

#define HIGH                        (1)
#define LOW                         (0)

#define DEFAULT_WAIT_DISABLE_PWM    (0)

using namespace std;

class Serv {
	protected :
		int myPin;
		int myMinPW;
		int myMaxPW;
		int myPeriod;
		mraa_pwm_context myPWM;
		//void initPWM(int pin, int minPW, int maxPW, int period);
	public :
		// Constructeurs et destructeurs
		Serv(int pin);
		//Serv(int pin, int minPW, int maxPW);
		~Serv();
		
		// Setters
		void setMinPW(int w);
		void setMaxPW(int w);

		void setAngle(float a);

		void sayNO(int timePause);
		void goFront();

		// Getters
		int getMinPW();
		int getMaxPW();
		int getPeriod();
		
		float getPWM();
};

#endif



