#include "touch.h"

Touch::Touch(int pin){
	mraa_init();
	myPin = pin;
	myTouch = mraa_gpio_init(pin);
	mraa_gpio_dir(myTouch, MRAA_GPIO_IN);                       
}                                                   
                                                    
Touch::~Touch(){
	mraa_gpio_close(myTouch);	
}

int Touch::read(){
	return mraa_gpio_read(myTouch);
}
