#include "LCD.h"
#include <mraa/aio.h>
#include <mraa/gpio.h>

using namespace std;

int main(){
         
	mraa_gpio_context m_gpio, but_gpio, touch_gpio;
	mraa_init();
	m_gpio = mraa_gpio_init(2);
	touch_gpio = mraa_gpio_init(4);
	but_gpio = mraa_gpio_init(3);
	
	LCD ecran;

	while(1){
		ecran.setRGB(0,255,0);       
		ecran.write("'Salut !'",1,0);
		sleep(1);
		ecran.setRGB(255,0,0);
		ecran.write("'tu travailles ?'",0,0);
                sleep(1);  
		ecran.setRGB(0,0,255);
		ecran.write("'moi aussi !'",1,0);
                sleep(1);  

/*
		//if(mraa_gpio_read(but_gpio)){
			//mraa_gpio_write(m_gpio, 1);
			sleep(2);
		//} else if(mraa_gpio_read(touch_gpio)){
			//mraa_gpio_write(m_gpio, 1);
			sleep(2);
		//} else {
			//mraa_gpio_write(m_gpio, 0);
			sleep(2);
		//}
*/
	}
	return (0);
}
