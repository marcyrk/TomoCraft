#include "serv.h"
#include <mraa/aio.h>
#include <mraa/gpio.h>

using namespace std;

int main(){
         
	//mraa_gpio_context m_gpio, but_gpio, touch_gpio;
	mraa_init();
	//m_gpio = mraa_gpio_init(2);
	//touch_gpio = mraa_gpio_init(4);
	//but_gpio = mraa_gpio_init(3);
	
	Serv testServ(3);

	//while(1){
	/*
		//if(mraa_gpio_read(but_gpio)){
			//mraa_gpio_write(m_gpio, 1);
			testServ.setAngle(0.0);
			sleep(2);
		//} else if(mraa_gpio_read(touch_gpio)){
			//mraa_gpio_write(m_gpio, 1);
			testServ.setAngle(45.0);
			sleep(2);
		//} else {
			testServ.setAngle(90.0);
			sleep(2);
			testServ.setAngle(135.0);
			sleep(2);
			//mraa_gpio_write(m_gpio, 0);
			testServ.setAngle(160.0);
			sleep(2);
		//}
	*/
	testServ.sayNO(500);
	testServ.sayNO(500);
	//}
	return (0);
}
