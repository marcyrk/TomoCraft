#include "button.h"

using namespace std;

Button::Button(int pin){
	mraa_init();
	myPin = pin;
	myButton = mraa_gpio_init(pin);
	mraa_gpio_dir(myButton, MRAA_GPIO_IN); 
}

Button::~Button(){
	mraa_gpio_close(myButton);
}

int Button::read(){
	return (mraa_gpio_read(myButton));
}

