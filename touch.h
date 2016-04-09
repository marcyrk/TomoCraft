#ifndef TOUCH_H
#define TOUCH_H

#include <mraa/gpio.h>

class Touch{

	private:
		int myPin;
		mraa_gpio_context myTouch;
		int myState;
	public:
		Touch(int pin);
		~Touch();

		int read();

};

#endif
