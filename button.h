#ifndef BUTTON_H
#define BUTTON_H

#include <mraa/gpio.h>
#include <iostream>
#include <string>

using namespace std;

class Button{
	private:
		int myPin;
		mraa_gpio_context myButton;
	public:
		Button(int pin);
		~Button();

		// Getter
		int read();

};

#endif
