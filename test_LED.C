#include "LED.h"
//#include "button.h"

int main(){

	LED testLED(8);
	/*
	Button testButton(2);
	
	while(1){
		if(testButton.getButton()){
			cout << "ON" << endl;
			testLED.ON();
		} else {
			cout << "OFF" << endl;
			testLED.OFF();
		}
	}
	*/
	
	testLED.blink(5, 500);
	return (0);
}
