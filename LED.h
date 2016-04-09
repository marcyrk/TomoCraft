#ifndef LED_H
#define LED_H

#include <mraa/gpio.h>
#include <iostream>
#include <string>
#include <unistd.h>

#define LED_ON	(1)
#define LED_OFF	(0)

class LED {

	private:
		int myPin;
		mraa_gpio_context myLED;
		int myState;

	public:
		LED(int pin);
		~LED();

		void ON();
		void OFF();
		// parametres : nb de repetitions, et duree
		void blink(int rep, int duration);

/*
void LED_BRIGHT(mraa_gpio_context capteur, int pin, string etat, int duree_bright, float periode){

mraa_pwm_context PWM;

PWM = mraa_pwm_init(pin);
mraa_pwm_period_ms(PWM, periode); //periode en ms

if (etat==ON){

int i;
float duty = 0.0;

mraa_pwm_enable(PWM,1);

for (i=0; i<10; i++)
{
	for (duty=0.0; duty < 1.0; duty+=0.1)
	{
	mraa_pwm_write(PWM, rap_cyc);  // rapport cyclique entre 0.0 et 1.0
	usleep(duree_bright);
	}
	sleep(1);

	for (duty=1.0; duty > 0.0; duty-=0.1)
	{
	mraa_pwm_write(PWM, rap_cyc);  // rapport cyclique entre 0.0 et 1.0
	usleep(duree_bright);
	}
	sleep(1);	

}

else if (etat==OFF) {

mraa_pwm_enable(PWM,0);
mraa_pwm_close(PWM);

}*/

};

#endif




