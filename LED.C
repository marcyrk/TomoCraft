#include "LED.h"

LED::LED(int pin){                              
	mraa_init();
	myPin = pin;
	myLED = mraa_gpio_init(pin);                                                   
	mraa_gpio_dir(myLED, MRAA_GPIO_OUT);                                          
}                                                                               

LED::~LED(){
	mraa_gpio_close(myLED);
}
                                                                                
void LED::ON(){                                         
	mraa_gpio_write(myLED,LED_ON);                                                     
	myState = LED_ON;
}                                                                               
                                                                                
void LED::OFF(){                                        
	mraa_gpio_write(myLED,LED_OFF);
	myState = LED_OFF;                                                     
}

void LED::blink(int rep, int duration){
	for(int i = 0 ; i<2*rep ; i++){
		if(myState == LED_ON){
			LED::OFF(); 
		} else {
			LED::ON();
		}
		usleep(duration*1000); // sleep en ms
	}
}
