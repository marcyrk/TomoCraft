#include "buzz.h"
#include "button.h"
#include "touch.h"
#include "LED.h"
#include <iostream>


using namespace std;

int main(){
	//mraa_gpio_context m_gpio, touch_gpio;
	mraa_init();
	//m_gpio = mraa_gpio_init(8);
	LED testLED(8);
	//touch_gpio = mraa_gpio_init(4);
	Touch testTouch(4);
	//mraa_gpio_dir(m_gpio, MRAA_GPIO_OUT);
	//mraa_gpio_dir(touch_gpio, MRAA_GPIO_IN);
	
	int melody1[7] = {DO, DO, SOL, SOL, LA, LA, SOL};
	int melody2[7] = {FA, FA, MI, MI, RE, RE, DO};
	int melody3[7] = {SOL, SOL, FA, FA, MI, MI, RE};   
        int melody4[7] = {SOL, SOL, FA, FA, MI, MI, RE};    
        int melody5[7] = {DO, DO, SOL, SOL, LA, LA, SOL};
	int melody6[7] = {FA, FA, MI, MI, RE, RE, DO};    
	
	int duree[7] = {1, 1, 1, 1, 1, 1, 2};

	Button testButton(2);
	Buzz testBuzz(5);
	while(1){
		if(testButton.read()){
			//cout<<"playsound"<<endl;
			for(int i = 0 ; i < 7 ; i++){
				testBuzz.playSound(melody1[i], duree[i]*250000);
				usleep(100*1000);
			}            
                        for(int i = 0 ; i < 7 ; i++){         
                                testBuzz.playSound(melody2[i], duree[i]*250000);
                                usleep(100*1000);             
                        }                  
                        for(int i = 0 ; i < 7 ; i++){         
                                testBuzz.playSound(melody3[i], duree[i]*250000);
                                usleep(100*1000);             
                        }                  
                        for(int i = 0 ; i < 7 ; i++){         
                                testBuzz.playSound(melody4[i], duree[i]*250000);
                                usleep(100*1000);             
                        }                  
                        for(int i = 0 ; i < 7 ; i++){         
                                testBuzz.playSound(melody5[i], duree[i]*250000);
                                usleep(100*1000);             
                        }                  
                        for(int i = 0 ; i < 7 ; i++){         
                                testBuzz.playSound(melody6[i], duree[i]*250000);
                                usleep(100*1000);             
                        }      
                	//testBuzz.playSound(RE); 
              		//testBuzz.playSound(MI); 
                	//testBuzz.playSound(FA); 
                	//testBuzz.playSound(SOL); 
               	} else if(testTouch.read()){
			testBuzz.playSound(LA, 1000000); 
                	//testBuzz.playSound(SI); 
			//sleep(1);
			//testBuzz.stopSound();
		} else {
			testBuzz.stopSound();
		}
	}
	return (0);

	
}
